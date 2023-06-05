// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	for(int i=0;i<n;i++){
		int index=abs(arr[i]);
		arr[index]*=-1;

		if(arr[index]>0)
			return index;
	}

	return -1;
}
