//
// Created by JianquanWang on 2020/2/23.
//

#ifndef SRC_MINSTACK_HPP
#define SRC_MINSTACK_HPP

#include <stack>
using namespace std;
/** LeetCode 155. Min Stack: Easy*/
class MinStack{
public:
    MinStack(){}
    void push(int x){
        _data.push(x);
        if(_min.empty()){
            _min.push(x);
        }else{
            _min.push(_min.top() < x ? _min.top() : x);
        }
    }
    void pop(){
        _data.pop();
        _min.pop();
    }
    int top(){
        return _data.top();
    }
    int getMin(){
        return _min.top();
    }
private:
    stack<int> _data;
    stack<int> _min;
};
#endif //SRC_MINSTACK_HPP
