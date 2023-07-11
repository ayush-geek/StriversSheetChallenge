class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int mx = 0;

        for (int i = 0; i <= n; i++)
        {
            // find left smaller
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int ht = heights[st.top()];
                st.pop();

                int width = -1;

                if (!st.empty())
                    width = i - st.top() - 1;
                else
                    width = i;
                // cout<<width<<" "<<ht<<endl;
                mx = max(mx, width * ht);
            }
            st.push(i);
        }
        return mx;
    }
};