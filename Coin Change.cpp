#include<bits/stdc++.h>
using namespace std;

void NumberOfWays(int n, int value, int coins[])
{
    int table[n+1][value+1];

    for(int i=1; i<=value; i++)
    {
        table[0][i] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        table[i][0] = 1;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=value; j++)
        {
            if(j >= coins[i])
                table[i][j] = table[i-1][j] + table[i][j-coins[i]];
            else
                table[i][j] = table[i-1][j];
        }
    }
    cout << "Number Of Ways: ";
    cout << table[n][value] << endl;
}

void MinimumNumerOfCoins(int n, int value, int coins[])
{
    int table[n+1][value+1];

    for(int i=1; i<=value; i++)
    {
        table[0][i] = 999;
    }
    for(int i=0; i<=n; i++)
    {
        table[i][0] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=value; j++)
        {
            if(j >= coins[i])
                table[i][j] = min(table[i-1][j], table[i][j-coins[i]] + 1);
            else
                table[i][j] = table[i-1][j];
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=value; j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }

    int i=n, j=value;
    cout << "Used Coins Are: " << endl;
    while(i>0 && j>0)
    {
        if(table[i][j] == table[i-1][j])
        {
            i--;
        }
        else
        {
            j -= coins[i];
            cout << coins[i] << " ";
        }
//        cout << i << " " << j << endl;
    }
}

int main()
{
    int value; cin >> value;
    int n;
    cin >> n;

    int coins[n+1];
    for(int i=1; i<=n; i++) cin >> coins[i];
//    NumberOfWays(n, value, coins);
    MinimumNumerOfCoins(n, value, coins);
}
