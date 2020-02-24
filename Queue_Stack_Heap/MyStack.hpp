//
// Created by JianquanWang on 2020/2/23.
//

#ifndef SRC_MYSTACK_HPP
#define SRC_MYSTACK_HPP

#include <queue>
using namespace std;
/** LeetCode 255. Implement Stack using Queues: Easy*/
class MyStack{
public:
    MyStack(){
    }
    void push(int x){
        queue<int> temp_queue;
        while(!_data.empty()){
            temp_queue.push(_data.front());
            _data.pop();
        }
        _data.push(x);
        while(!temp_queue.empty()){
            _data.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    int pop(){
        int val = _data.front();
        _data.pop();
        return val;
    }
    int top(){
        return _data.front();
    }
    bool empty(){
        return _data.empty();
    }
private:
    queue<int> _data;
};

#endif //SRC_MYSTACK_HPP
