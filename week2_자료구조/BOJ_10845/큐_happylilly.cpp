/*
알고리즘 : 자료구조 - 큐
시간 복잡도 : 탐색 : O(n) / 삽입/삭제 : O(1)
참고 링크 : x
아이디어 : STL 큐를 사용한다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x;
    string s;
    queue<int> queue;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            queue.push(x);
        }
        else if (s == "pop")
        {
            if (queue.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            x = queue.front();
            queue.pop();
            cout << x << '\n';
        }
        else if (s == "size")
        {
            cout << queue.size() << '\n';
        }
        else if (s == "empty")
        {
            x = queue.empty() ? 1 : 0;
            cout << x << '\n';
        }
        else if (s == "front")
        {
            if (queue.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << queue.front() << '\n';
        }
        else if (s == "back")
        {
            if (queue.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << queue.back() << '\n';
        }
    }
    return 0;
}