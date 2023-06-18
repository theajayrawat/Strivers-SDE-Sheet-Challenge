// Time Complexity: O(N)
//  Space Complexity: O(N)

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
     if(str1.length() != str2.length()){
            return false;
        }
        vector<int>arr(26,0);
        for(int i=0; i<str1.length(); i++){
            arr[str1[i]-'a']++;
            arr[str2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
}