#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    string v;
    cin >> v ;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= '0' && v[i] <= '9')
        {
                printf("%c", v[i]);
        }
        else
        {
            if (s.empty())
            {
                s.push(v[i]);
            }
            else
            {
                if (v[i] == '(')
                    s.push(v[i]);
                if (v[i] == '+' || v[i] == '-')
                {
                    while (!s.empty())
                    {
                        if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                        {
                            printf("%c", s.top());
                            s.pop();
                        }
                        else
                            break;
                    }
                    s.push(v[i]);
                }
                else if (v[i] == '*' || v[i] == '/')
                {
                    while (!s.empty())
                    {
                        if (s.top() == '*' || s.top() == '/')
                        {
                            printf("%c", s.top());
                            s.pop();
                        }
                        else
                            break;
                    }
                    s.push(v[i]);
                }
                else if (v[i] == ')')
                {
                    while (!s.empty())
                    {
                        if (s.top() == '(')
                        {
                            s.pop();
                            break;
                        }
                        printf("%c", s.top());
                        s.pop();
                    }
                }
            }
        }
    }
    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }
    return 0;
}