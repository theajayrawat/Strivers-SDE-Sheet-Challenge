// Time Complexity: O(N)
//  Space Complexity: O(N)

#include <bits/stdc++.h>
string reverseString(string &str)
{
    // Write your code here.
    vector<string> v;
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        v.push_back(word);

    string ans;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i];
        if (i != 0)
            ans += " ";
    }
    return ans;
}