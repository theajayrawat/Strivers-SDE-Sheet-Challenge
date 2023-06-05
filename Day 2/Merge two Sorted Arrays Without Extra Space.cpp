// Time Complexity: O(M+N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int ptr1 = m - 1;
    int ptr2 = n - 1;
    int ptr3 = n + m - 1;

    while (ptr1 >= 0 && ptr2 >= 0)
    {
        if (arr1[ptr1] > arr2[ptr2])
            arr1[ptr3--] = arr1[ptr1--];
        else
            arr1[ptr3--] = arr2[ptr2--];
    }

    while (ptr2 >= 0)
        arr1[ptr3--] = arr2[ptr2--];

    return arr1;
}