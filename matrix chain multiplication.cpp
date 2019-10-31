#include<bits/stdc++.h>
using namespace std;

void printSequence(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";

    printSequence(i, *((bracket+i*n)+j), n, bracket, name);
    printSequence(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    cout << ")";

}

void chainMatrixMultiplication(int p[], int n)
{
    int m[n][n], b[n][n];

    for(int i=0; i<n; i++)
        m[i][i] = 0;

    for(int d = 2; d < n; d++)
    {
        for(int i=1; i<n- d+1; i++)
        {
            int j = i + d - 1;
            m[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(m[i][j] >q)
                {
                    m[i][j] = q;
                    b[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "The sequence is: " << endl;
    printSequence(1, n-1, n, (int *)b, name);
    cout << endl << m[1][n-1] << endl;

}

int main()
{
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p)/sizeof(p[0]);
    chainMatrixMultiplication(p, n);
}
