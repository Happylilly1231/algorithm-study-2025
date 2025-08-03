/*
알고리즘 : 자료구조 - 힙
시간 복잡도 :
    - 생성: O(n)
    - 탐색: O(n)
    - 삽입/삭제: O(log n)
참고 링크 : x
아이디어 : STL 힙을 사용한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x;
    vector<int> v;

    make_heap(v.begin(), v.end());

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (v.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << v.front() << '\n';
            pop_heap(v.begin(), v.end());
            v.pop_back();
        }
        else
        {
            v.push_back(x);
            push_heap(v.begin(), v.end());
        }
    }
}