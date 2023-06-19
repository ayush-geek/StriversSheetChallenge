vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> res;
    stack<int> st;
    
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty() && A[st.top()]>=A[i])
            st.pop();
            
        if(st.empty())
        {
            res.push_back(-1);
        }
        else
            res.push_back(A[st.top()]);
            
        st.push(i);
    
    }
    return res;
}
