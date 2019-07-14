#include<bits/stdc++.h>
using namespace std;
int main()
{
    double k, m = 1000;
    double a = 0.644;
    cin >> k;
    cout << floor(m*((k*a)-floor(k*a))) << endl;
}
