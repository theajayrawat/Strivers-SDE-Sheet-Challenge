// Time Complexity: O(N*log N)
//  Space Complexity: O(N)

#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    string str;
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (arr[0][i] == arr[arr.size() - 1][i])
            str += arr[0][i];
        else
            break;
    }

    return str;
}
