// Time Complexity: O(N)
//  Space Complexity: O(1)

#include <bits/stdc++.h>
int atoi(string str)
{
    // Write your code here.
    int ans = 0;
    int sing = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            ans = ans * 10 + str[i] - '0';
        if (str[i] == '-')
            sing = -1;
    }

    return ans * sing;
}