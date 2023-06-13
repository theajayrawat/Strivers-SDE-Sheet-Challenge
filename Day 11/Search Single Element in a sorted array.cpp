// Time Complexity: O(log(N))
// Space Complexity: O(1)

int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    int low = 0;
    int high = arr.size() - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid % 2)
        {
            if (arr[mid] == arr[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return arr[low];
}