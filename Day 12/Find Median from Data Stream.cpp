class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);

        if (minHeap.size() > 0 && maxHeap.top() > minHeap.top())
        {

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // cout<<"bf "<<maxHeap.size()<<" "<<minHeap.size()<<endl;
        // balancing

        if ((maxHeap.size() > minHeap.size() + 1))
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if ((minHeap.size() > maxHeap.size() + 1))
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        //    cout<<"af "<<maxHeap.size()<<" "<<minHeap.size()<<endl;
    }

    double findMedian()
    {

        // cout<<maxHeap.size()<<" "<<minHeap.size()<<endl;
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();

        if (minHeap.size() > maxHeap.size())
            return minHeap.top();

        return double(maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */