// Time Complexity: O(N)
// Space Complexity: O(K)

#include <bits/stdc++.h>
class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int gk;
    Kthlargest(int k, vector<int> &arr)
    {
        gk = k;
        for (auto a : arr)
        {
            if (pq.size() < k)
                pq.push(a);
            else if (pq.size() == k && a >= pq.top())
            {
                pq.pop();
                pq.push(a);
            }
        }
    }

    void add(int num)
    {
        if (pq.size() < gk)
            pq.push(num);
        else if (pq.size() == gk && num >= pq.top())
        {
            pq.pop();
            pq.push(num);
        }
    }

    int getKthLargest()
    {
        return pq.top();
    }
};