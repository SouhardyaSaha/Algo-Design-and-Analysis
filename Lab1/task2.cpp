#include<bits/stdc++.h>
using namespace std;
vector<string> tokens;
int value[1000];
int hashFunctionKey(int radix, string s)
{
    int hashValue = 0;
    int rad = 0;
    for(int i = 0; i<s.size(); i++)
    {
        rad = ((int)s[i]) * pow(radix, i);
        hashValue = hashValue + rad%1000;
    }
    return hashValue;
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
    vector<string> uniq;
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
        int hashValue = hashFunctionKey(radix, tokens[i]);
        if(value[hashValue] == 0) uniq.push_back(tokens[i]);
        value[hashValue]++;
    }
    cout << "total Unique Words " << uniq.size() << endl << "the words are: " << endl;
    for(int i=0; i<uniq.size(); i++)
    {
        int hashValue = hashFunctionKey(radix, tokens[i]);
        cout << tokens[i] << ' ' << value[hashValue] << endl;
    }
}
