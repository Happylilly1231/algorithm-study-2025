/*
    알고리즘 : 자료구조 - 스택
    시간복잡도 : O(n)
    참고링크 : switch에서 문자열 사용하기(https://velog.io/@dnr6054/C-switch%EC%97%90%EC%84%9C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0-feat.-constexpr)
    아이디어 : switch에서 문자열을 사용하여 입력으로 주어지는 명령을 처리함
*/

#include <iostream>
#include <stack>

using namespace std;

constexpr unsigned int HashCode(const char *str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<int> st;

    cin >> n;

    while (n--)
    {
        char operation[10];
        cin >> operation;

        switch (HashCode(operation))
        {
        case HashCode("push"):
        {
            int value;
            cin >> value;
            st.push(value);
            continue;
        }
        case HashCode("pop"):
        {
            if (!st.empty())
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
            continue;
        }
        case HashCode("size"):
        {
            cout << st.size() << '\n';
            continue;
        }
        case HashCode("empty"):
        {
            if (st.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        case HashCode("top"):
        {
            if (!st.empty())
                cout << st.top() << '\n';
            else
                cout << -1 << '\n';
            continue;
        }
        }
    }

    return 0;
}