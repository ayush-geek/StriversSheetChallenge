class MinStack
{
private:
    stack<long long> st;
    // stack<int> st2;
    long long mn;

public:
    MinStack()
    {
        mn = INT_MAX;
    }

    void push(long long val)
    {

        long long nv = val;

        if (st.empty())
        {

            mn = nv;
        }
        else
        {
            if (nv < mn)
            {
                nv = 2 * val - mn;
                mn = val;
            }
        }
        st.push(nv);
    }

    void pop()
    {

        long long val = st.top();
        st.pop();
        if (val < mn)
        {
            int pvmn = 2 * mn - val;
            mn = pvmn;
        }
    }

    int top()
    {
        long long val = st.top();

        if (val < mn)
        {
            return mn;
        }
        return val;
    }

    int getMin()
    {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */