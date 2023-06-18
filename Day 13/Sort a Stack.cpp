#include <bits/stdc++.h>

void insert(int z1, stack<int> &st)
{
    if (st.empty() || st.top() <= z1)
    {
        st.push(z1);
        return;
    }
    int z2 = st.top();
    st.pop();
    insert(z1, st);
    st.push(z2);
}

void sortStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }

    int z1 = st.top();
    st.pop();
    sortStack(st);

    insert(z1, st);
}
