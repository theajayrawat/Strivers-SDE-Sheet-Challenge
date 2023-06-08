// Time Complexity: O(N)
// Space Complexity: O(1)

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int i = 0;
    if (n == 1)
        return n;

    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}