class KthLargest
{
private:
    int k;
    priority_queue<int> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(-1 * nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
        // return abs(pq.top());
    }

    int add(int val)
    {
        pq.push(-1 * val);
        if (pq.size() > k)
            pq.pop();

        return -1 * pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */