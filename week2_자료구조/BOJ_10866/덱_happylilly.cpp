/*
알고리즘 : 자료구조 - 덱
시간 복잡도 : 탐색 : O(1) - 인덱스로 접근 /
    삽입/삭제
        - 맨 앞, 뒤 : O(1)
        - 임의 위치 : O(n)
참고 링크 : x
아이디어 : STL 덱을 사용한다.
*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x;
    string s;
    deque<int> deque;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s;

        if (s == "push_front")
        {
            cin >> x;
            deque.push_front(x);
        }
        else if (s == "push_back")
        {
            cin >> x;
            deque.push_back(x);
        }
        else if (s == "pop_front")
        {
            if (deque.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << deque.front() << '\n';
            deque.pop_front();
        }
        else if (s == "pop_back")
        {
            if (deque.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << deque.back() << '\n';
            deque.pop_back();
        }
        else if (s == "size")
        {
            cout << deque.size() << '\n';
        }
        else if (s == "empty")
        {
            x = deque.empty() ? 1 : 0;
            cout << x << '\n';
        }
        else if (s == "front")
        {
            if (deque.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << deque.front() << '\n';
        }
        else if (s == "back")
        {
            if (deque.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << deque.back() << '\n';
        }
    }
    return 0;
}