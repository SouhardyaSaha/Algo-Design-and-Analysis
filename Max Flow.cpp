#include<bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parrent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parrent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int x = 0; x < V; x++)
        {
            if(!visited[x] && rGraph[u][x] > 0)
            {
                q.push(x);
                parrent[x] = u;
                visited[x] = true;
            }
        }
    }

    return (visited[t] == true);
}

int maxFlow(int rGraph[V][V], int s, int t)
{
    int u, v;
    int parrent[V];
    int max_flow = 0;

    while(bfs(rGraph, s, t, parrent))
    {
        int path_flow = INT_MAX;
        for(v=t; v!=s; v=parrent[v])
        {
            u = parrent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for(v=t; v!=s; v=parrent[v])
        {
            u = parrent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
     int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The maximum possible flow is " << maxFlow(graph, 0, 5);

    return 0;
}
