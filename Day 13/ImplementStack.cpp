#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int sz;
    int *arr;
    int top;

public:
    Stack()
    {
        sz = 5;
        top = -1;
        arr = new int[sz];
    }

    void push(int i)
    {
        if (top + 1 == sz)
            cout << "Stack Full";
        else
            arr[++top] = i;
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Empty";
        else
            top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack Empty";
            return -1;
        }
        else
            return arr[top];
    }

    bool isempty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == sz - 1;
    }
};

int main()
{
    // cout << "dd" << endl;
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    // cout << st.Top();
    // st.pop();
    // cout << st.Top();
}