/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        for(string s:tokens){
            if(s=="+")
            {
                int a=stack.top();
                stack.pop();
                int b=stack.top();
                stack.pop();
                int c=a+b;
                stack.push(c);
            }
            else if(s=="-")
            {
                int a=stack.top();
                stack.pop();
                int b=stack.top();
                stack.pop();
                int c=b-a;
                stack.push(c);
            }
            else if(s=="*")
            {
                int a=stack.top();
                stack.pop();
                int b=stack.top();
                stack.pop();
                int c=a*b;
                stack.push(c);
            }
            else if(s=="/")
            {
                int a=stack.top();
                stack.pop();
                int b=stack.top();
                stack.pop();
                int c=b/a;
                stack.push(c);
            }
            else
            {
                stack.push(stoi(s));
            }
        }
        return stack.top();
        
    }
};
// @lc code=end

