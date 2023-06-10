// Time Complexity:  O((2^n)*k) "k" is the average length of word 
// Space Complexity:  O(1)

#include <bits/stdc++.h>
void solve(int index, string s, vector<string>& path,
    vector <string> & res, unordered_map<string,int>&st) {
    if (index == s.size()) {
       string str = "";
        for (auto it : path)
        {
            str += it + " ";
        }
        str.pop_back();
        res.push_back(str);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (st.find(s.substr(index, i - index + 1))!=st.end()) {
        path.push_back(s.substr(index, i - index + 1));
        solve(i + 1, s, path, res, st);
        path.pop_back();
      }
    }
  }

vector<string> wordBreak(string &s, vector<string> &dictionary) {
  // Write your code here
  vector<string> path,res;
  unordered_map<string,int> st;
  for (auto it : dictionary)
    {
      st[it]++;
    }

  solve(0, s, path, res, st);
  return res;
}