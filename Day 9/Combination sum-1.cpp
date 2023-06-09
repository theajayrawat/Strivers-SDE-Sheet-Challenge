// Time Complexity: O(2^n*k) “k”:average space for the temp;
// Space Complexity:O(k*x) “x":combination

#include <bits/stdc++.h> 
void help( vector<vector<int>>&v,vector<int>&candidates,vector<int>temp,int i,int k){
    if(i==candidates.size()){
        if(k==0)v.push_back(temp);
            return ;
    }

    help(v,candidates,temp,i+1,k);

    temp.push_back(candidates[i]);

    help(v,candidates,temp,i+1,k-candidates[i]);

    temp.pop_back();
    }
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>v;
    vector<int>temp;
    int sum=0;
    help(v,arr,temp,0,k);
    return v;
}

