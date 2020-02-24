//
// Created by JianquanWang on 2020/2/23.
//

#ifndef SRC_SOLUTION_HPP
#define SRC_SOLUTION_HPP

#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution{
public:
    /** POJ 1363 Rails: Medium*/
    bool check_is_valid_order(queue<int> &Q){
        stack<int> S;
        for(int i = 1; i<=Q.size(); i++){
            S.push(i);
            while(S.top() == Q.front() && !S.empty()){
                S.pop();
                Q.pop();
            }
        }
        return Q.empty();
    }

    /** LeetCode 215. Kth Largest Element in an Array: Medium*/
    int findKthLargest(vector<int> & nums, int k){
        priority_queue<int, vector<int>, greater<int>> small_heap;
        for (int val:nums){
            if(small_heap.size() < k){
                small_heap.push(val);
            }else{
                if(val > small_heap.top()){
                    small_heap.pop();
                    small_heap.push(val);
                }
            }
        }
        return small_heap.top();
    }
    /** LeetCode 295. Find Median from Data Stream: Hard*/
    class MedianFinder{
    public:
        MedianFinder(){}
        void addNum(int num){
            if(small_heap.empty() && big_heap.empty()){
                big_heap.push(num);
                return;
            }
            if(big_heap.size() == small_heap.size()){
                if(num < big_heap.top()){
                    big_heap.push(num);
                }else{
                    small_heap.push(num);
                }
            }else if(big_heap.size() > small_heap.size()){
                if(num < big_heap.top()){
                    small_heap.push(big_heap.top());
                    big_heap.pop();
                    big_heap.push(num);
                }else{
                    small_heap.push(num);
                }
            }else{
                if(num < big_heap.top()){
                    big_heap.push(num);
                }else{
                    big_heap.push(small_heap.top());
                    small_heap.pop();
                    small_heap.push(num);
                }
            }
        }
        double findMedian(){
            if(big_heap.size() == small_heap.size()){
                return double(big_heap.top() + small_heap.top()) / 2;
            } else if(big_heap.size() < small_heap.size()){
                return double(small_heap.top());
            } else{
                return double(big_heap.top());
            }
        }

    private:

        priority_queue<int, vector<int>, less<int>> big_heap;
        priority_queue<int, vector<int>, greater<int>> small_heap;
    };
};
#endif //SRC_SOLUTION_HPP
