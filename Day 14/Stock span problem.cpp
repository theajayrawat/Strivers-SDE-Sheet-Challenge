// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h> 
int next(int price,stack<pair<int,int>>& st) {
        int span =1;
        while(!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
        
    }
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>> st;
    int n=price.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(next(price[i],st));
    }

    return ans;

}