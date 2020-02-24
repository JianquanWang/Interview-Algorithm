//
// Created by JianquanWang on 2020/2/23.
//

#ifndef SRC_MYQUEUE_HPP
#define SRC_MYQUEUE_HPP

#include <stack>
using namespace std;
/** LeetCode 232. Implement Queue using Stack: Easy*/
class MyQueue{
    MyQueue(){}
    void push(int x){
        _in.push(x);
    }
    int pop(){
        adjust();
        int val = _out.top();
        _out.pop();
        return val;
    }
    int peek(){
        adjust();
        return _out.top();
    }
    bool empty(){
        return _in.empty() && _out.empty();
    }
    void adjust(){
        if(_out.empty()){
            while(!_in.empty()){
                _out.push(_in.top());
                _in.pop();
            }
        }
        return;
    }
private:
    stack<int> _in;
    stack<int> _out;

};
#endif //SRC_MYQUEUE_HPP
