/*
알고리즘: 자료구조 - 맵
시간 복잡도:
    - 탐색: O(logN)
    - 삽입: O(logN)
    - 전체: O(NlogN)
참고 링크: x
아이디어: 맵 하나만으로 구현하기 위해, 보도 못한 사람을 먼저 맵으로 받고, 듣도 못한 사람은 보도 못한 사람 명단에 있는 것만 value를 1로 설정한다. value가 1인 것들만 출력한다.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    map<string, int> m;
    string name;
    int cnt = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> name;
        m.insert({name, 0});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> name;
        if (m.find(name) != m.end())
        {
            m[name] = 1;
            cnt++;
        }
    }

    cout << cnt << '\n';

    for (auto it : m)
    {
        if (it.second == 1)
            cout << it.first << '\n';
    }

    return 0;
}