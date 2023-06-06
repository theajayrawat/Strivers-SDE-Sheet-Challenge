// Time Complexity: O(log n)
// Space Complexity: O(N log N)

#include<bits/stdc++.h>

using namespace std;
int Merge(vector < int > & nums, int low, int mid, int high) {
  	int total = 0;
  	int j = mid + 1;
  	for (int i = low; i <= mid; i++) {
    	while (j <= high && nums[i] > 2 * nums[j]) {
      		j++;
    	}
    	total += (j - (mid + 1));
  	}

  	vector < int > t;
  	int left = low, right = mid + 1;

  	while (left <= mid && right <= high) {

    	if (nums[left] <= nums[right]) {
      		t.push_back(nums[left++]);
    	} else {
      		t.push_back(nums[right++]);
    	}
  	}

  	while (left <= mid) {
    	t.push_back(nums[left++]);
  	}
  	while (right <= high) {
    	t.push_back(nums[right++]);
  	}

  	for (int i = low; i <= high; i++) {
    	nums[i] = t[i - low];
  	}
  	return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

    int mid,inv = 0;
    if(high>low)
    {
        mid = (low + high) / 2;
		inv = MergeSort(nums, low, mid);
  		inv += MergeSort(nums, mid + 1, high);
  		inv += Merge(nums, low, mid, high);
    }
    return inv;
}
int reversePairs(vector < int > & arr, int n) {
  return MergeSort(arr, 0, arr.size() - 1);
}