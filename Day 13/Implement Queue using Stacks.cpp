class MyQueue
{
public:
    stack<int> input, output;

    MyQueue()
    {
    }

    void push(int x)
    {

        input.push(x);
    }

    int pop()
    {
        int z = peek();

        output.pop();
        return z;
    }

    int peek()
    {
        int z = 0;
        if (!output.empty())
        {
            z = output.top();
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            z = output.top();
        }
        return z;
    }

    bool empty()
    {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */