// Time Complexity: O(N)
// Space Complexity: O(N)

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;

    for (int i = 0; i < expression.size(); i++)
    {
        if (!st.empty() && st.top() == '(' && expression[i] == ')')
            st.pop();
        else if (!st.empty() && st.top() == '{' && expression[i] == '}')
            st.pop();
        else if (!st.empty() && st.top() == '[' && expression[i] == ']')
            st.pop();
        else
            st.push(expression[i]);
    }

    return st.empty();
}