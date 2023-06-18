// Time Complexity: O(N^2)
//  Space Complexity: O(1)

#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    // Write your code here.
    if (n == 1)
        return "1";

    string str = writeAsYouSpeak(n - 1);
    string ans;
    int i = 0;
    while (i < str.size())
    {
        int count = 1;
        while (i + 1 < str.size() && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        ans += to_string(count);
        ans += str[i];
        i++;
    }

    return ans;
}