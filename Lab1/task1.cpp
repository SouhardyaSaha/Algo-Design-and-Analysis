#include<bits/stdc++.h>
using namespace std;
vector<string> tokens;
int value[1000];
int radix_value(int radix, string s)
{
    int radix_sum = 0;
    int rad = 0;
    for(int i = 0; i<s.size(); i++)
    {
        rad = ((int)s[i]) * pow(radix, i);
        radix_sum = radix_sum + rad%78;
    }
    return radix_sum;
}
void stringTokenize(string line)
{
    stringstream check1(line);
    string intermediate;
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
}
int main()
{
    int radix;
    string s;
    cout << "Radix Value: ";
    cin >> radix;
    cout << "String: ";
    getchar();
    getline(cin, s);

    stringTokenize(s);
    for(int i=0; i<tokens.size(); i++)
    {
        int radix_sum = radix_value(radix, tokens[i]);
        value[radix_sum]++;
    }
    for(int i=0; i<tokens.size(); i++)
    {
        int radix_sum = radix_value(radix, tokens[i]);
        cout << tokens[i] << ' ' << value[radix_sum] << endl;
    }
}
