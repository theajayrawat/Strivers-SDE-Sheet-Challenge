// Time Complexity: O(N)
//  Space Complexity: O(1)

int minCharsforPalindrome(string str)
{
    // Write your code here.
    int n = str.size();
    int low = 0;
    int high = n - 1;
    int e2 = high;
    int cnt = 0;

    while (low < high)
    {
        if (str[low] == str[high])
        {
            low++;
            high--;
        }
        else
        {
            cnt++;
            low = 0;
            e2--;
            high = e2;
        }
    }

    return cnt;
}
