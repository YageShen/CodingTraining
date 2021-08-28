class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(!stack2.empty()) {
            int temp = stack2.top();
            stack2.pop();
            return temp;
        } 
        else {
            while(!stack1.empty()) {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            return pop();
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};