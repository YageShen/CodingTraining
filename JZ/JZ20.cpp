class Solution {
public:
    stack<int> normal, minval;
    void push(int value) {
        normal.push(value);
        if(minval.empty()) {
            minval.push(value);
        }
        else if(value < minval.top()) {
            minval.push(value);
        }
        else {
            minval.push(minval.top());
        }
    }
    void pop() {
        normal.pop();
        minval.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return minval.top();
    }
};