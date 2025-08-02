/*
알고리즘 : 자료구조 - 스택
시간 복잡도 : 탐색 : O(n) / 삽입/삭제 : O(1)
참고 링크 : x
아이디어 : STL 스택을 사용한다.
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, x;
    string s;
    stack<int> stack;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            stack.push(x);
        }
        else if (s == "pop")
        {
            if (stack.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            x = stack.top();
            stack.pop();
            cout << x << '\n';
        }
        else if (s == "size")
        {
            cout << stack.size() << '\n';
        }
        else if (s == "empty")
        {
            x = stack.empty() ? 1 : 0;
            cout << x << '\n';
        }
        else if (s == "top")
        {
            if (stack.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << stack.top() << '\n';
        }
    }
    return 0;
}