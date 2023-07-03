// Time Complexity: O(2^N)
// Space Complexity: O(2^N)

void powerSet(vector<int> &v, vector<int> &ds, vector<vector<int>> &ans, int ind)
{

    ans.push_back(ds);

    for (int i = ind; i < v.size(); i++)
    {

        // take the element

        ds.push_back(v[i]);

        powerSet(v, ds, ans, i + 1);

        // remove the existing element

        ds.pop_back();
    }
}

vector<vector<int>> pwset(vector<int> v)

{

    // Write your code here

    vector<int> ds;

    vector<vector<int>> ans;

    powerSet(v, ds, ans, 0);

    return ans;
}