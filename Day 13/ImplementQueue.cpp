#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int ct;
    int *arr;
    int front;
    int back;
    int msz;

public:
    Queue(int sz)
    {
        ct = 0;
        front = -1;
        back = -1;
        arr = new int[sz];
        msz = sz;
    }

    void push(int i)
    {
        if (ct == msz - 1)
            cout << "Queue Full";
        else
        {

            if (back == -1)
            {
                front = 0;
                back = 0;
            }
            else
            {
                back = (back + 1) % msz;
            }
            arr[back] = i;
            ct++;
        }
    }

    void pop()
    {
        if (front == -1)
            cout << "Queue Empty";
        else
        {
            int tp = arr[front];

            if (ct == 1)
            {
                front = -1;
                back = -1;
            }
            else
            {
                front = (front + 1) % msz;
            }
            ct--;
        }
    }

    int Top()
    {
        if (front == -1)
        {
            cout << "Queue Empty";
            return -1;
        }

        return arr[front];
    }

    bool isempty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ct == msz;
    }
};

int main()
{
    // cout << "dd" << endl;
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // q.push(6);
    q.pop();
    q.pop();

    cout << q.Top();
    q.pop();
    cout << q.Top();
}