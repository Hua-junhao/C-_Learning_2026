/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    stack<int>stackIn;
    stack<int>stackOut;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if(stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result=stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        if(stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        return stackOut.top();
    }
    
    bool empty() {
        if(stackIn.empty()&&stackOut.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

