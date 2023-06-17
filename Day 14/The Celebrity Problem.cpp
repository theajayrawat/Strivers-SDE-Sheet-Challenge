// Time complexity: O(N)
// Space complexity: O(N)

#include <bits/stdc++.h>
/*
        This is signature of helper function 'knows'.
        You should not implement it, or speculate about its implementation.

        bool knows(int A, int B);
        Function 'knows(A, B)' will returns "true" if the person having
        id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
  // Write your code here.
  stack<int> s;
  // step1: push all element in stack
  for (int i = 0; i < n; i++) {
    s.push(i);
  }

  // step2: get 2 elements and copare them

  while (s.size() > 1) {

    int a = s.top();
    s.pop();

    int b = s.top();
    s.pop();

    if (knows(a, b)) {
      s.push(b);
    } else {
      s.push(a);
    }
  }
  int ans = s.top();
  // step3: single element in stack is potential celeb
  // so verify it

  //Everyone know cleb

  for (int i = 0; i < n; i++) {
    if (i!=ans && !knows(i, ans))
      return -1;
  }

	//cleb not know anyone

  for (int i = 0; i < n; i++) {
    if (i!=ans && knows(ans, i))
      return -1;
  }


  return ans;
}