/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


class MinStack {
public:
    /** initialize your data structure here. */
    std::vector<int> _stack;
    int min_index= 0;
    int min = INT_MAX;
    MinStack() {

    }

    void push(int x) {
        _stack.push_back(x);
        if (x < min){
            min = x;
            min_index = _stack.size()-1;
        }
    }

    void pop() {
        if (!_stack.empty()){

            _stack.pop_back();

            if (_stack.size() == min_index){
                //重新获取最小值
                min = INT_MAX;
                for (int i = 0; i < _stack.size(); ++i) {
                    if (_stack[i] < min){
                        min = _stack[i];
                        min_index = i;
                    }
                }
            }
        }
    }

    int top() {
        return _stack.back();
    }

    //限定常数时间
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack minStack;
    minStack.push(-1);
    minStack.push(-2);
    minStack.push(-3);
    minStack.pop();
    std::cout << minStack.getMin() << std::endl;
}