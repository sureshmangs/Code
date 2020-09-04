Median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?








class MedianFinder {
public:

    priority_queue<int> q1; // max heap
    priority_queue<int, vector<int>, greater<int> > q2;  // min heap

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(q1.empty() || q1.top()>num)
            q1.push(num);
        else q2.push(num);

        if(q1.size()>q2.size()+1){
            q2.push(q1.top());
            q1.pop();
        } else if(q2.size()>q1.size()+1){
            q1.push(q2.top());
            q2.pop();
        }

    }

    double findMedian() {
        int q1size=q1.size();
        int q2size=q2.size();
        if(q1size>q2size) return q1.top();
        else if(q2size>q1size)return q2.top();
        else return (double)(q1.top()+q2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */




 // Approach 1: Simple Sorting
 // Time complexity: O(nlog n) + O(1) = O(nlogn)
 // Space complexity: O(n)

 // Approach 2: Insertion Sort
 // When a new number comes, we just have to put it in it's right place in the already sorted array
 // We can use binary search for it
 // Time complexity:  O(n) + O(logn) ≈ O(n)
 // Space complexity: O(n)



 // Approach 3: Two Heaps
 // Time complexity: (O(logn)
// Space complexity: O(n)
