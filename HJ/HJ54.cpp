#include <iostream>
#include <stack>

using namespace std;

string input;
int idx = 0;

int compute()
{
    int num = 0;
    stack<int> st;
    char flag = '+';
    
    while(idx < input.size())
    {
        if(input[idx] == '(')
        {
            idx ++;
            num = compute();
        }
        while(input[idx] >= '0' && input[idx] <= '9' && idx < input.size())
        {
            num = num * 10 + input[idx] - '0';
            idx ++;
        }
        switch (flag)
        {
            case '+': {
                st.push(num);
            } break;
            case '-': {
                st.push(-num);
            } break;
            case '*': {
                int temp = st.top();
                temp *= num;
                st.pop();
                st.push(temp);
            } break;
            case '/': {
                int temp = st.top();
                temp /= num;
                st.pop();
                st.push(temp);
            } break;
            default:
                break;
        }
        flag = input[idx];
        num = 0;
        if(flag == ')')
        {
            idx ++;
            break;
        }
        idx ++;
    }
    int sum = 0;
    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int main()
{
    while(cin >> input)
    {
        cout << compute() << endl;
    }
    return 0;
}