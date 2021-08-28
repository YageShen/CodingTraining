#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;
int idx = 0;

int compute()
{
    stack<int> st;
    int num = 0;
    char flag = '+';
    while(idx < input.size())
    {
        if(input[idx] == '(' || input[idx] == '[' || input[idx] == '{')
        {
            idx ++;
            num = compute();
        }
        
        while(input[idx] >= '0' && input[idx] <= '9' && idx < input.size())
        {
            num = 10 * num + input[idx] - '0';
            idx ++;
        }
        
        switch(flag)
        {
            case '+':
                st.push(num);
                break;
            case '-':
                st.push(-num);
                break;
            case '*':
            {
                int temp = st.top();
                temp *= num;
                st.pop();
                st.push(temp);
            }
                break;
            case '/':
            {
                int temp = st.top();
                temp /= num ;
                st.pop();
                st.push(temp);
            }
                break;
            default:
                break;
        }
        
        flag = input[idx];
        num = 0;
        if(flag == ')' || flag == ']' || flag == '}')
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
        idx = 0;
        int res = compute();
        cout << res << endl;
    }
    return 0;
}