// Time Complexity: O(log(N))
// Space Complexity: O(1)

int search(int *nums, int n, int key)
{
    // Write your code here.
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == key)
            return mid;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= key && nums[mid] >= key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] <= key && key <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}