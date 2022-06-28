// https://leetcode.com/problems/find-median-from-data-stream/
// ARTICLE LINK -> https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/

// Method - 1
// Concept of Insertion Sort
// TC: O(n ^ 2)
// SC: O(1)

// Method - 2
// MaxHeapx  &  MinHeap
// TC: O(n logn)
// SC: O(n)
class MedianFinder
{
public:
    priority_queue<int> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (MaxHeap.empty() == true)
            MaxHeap.push(num);

        else if (MaxHeap.top() > num)
            MaxHeap.push(num);
        else
            MinHeap.push(num);

        int m1 = MaxHeap.size();
        int m2 = MinHeap.size();

        if ((m1 + 1) < m2)
        {
            int x = MinHeap.top();
            MinHeap.pop();
            MaxHeap.push(x);
        }

        else if ((m2 + 1) < m1)
        {
            int x = MaxHeap.top();
            MaxHeap.pop();
            MinHeap.push(x);
        }
    }

    double findMedian()
    {
        if (MaxHeap.size() == MinHeap.size())
            return (MinHeap.top() + MaxHeap.top()) / 2.0;

        else if (MaxHeap.size() > MinHeap.size())
            return MaxHeap.top();

        return MinHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */