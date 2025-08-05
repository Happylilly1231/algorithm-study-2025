/*
    알고리즘 : 자료구조 - 맵
    시간복잡도 : O(nlogN)
    아이디어 : 이름을 key로 하는 map을 생성하여 등장 횟수를 저장
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, cnt = 0;
    string name;
    map<string, int> name_cnt;

    cin >> n >> m;

    while (n--)
    {
        cin >> name;
        name_cnt[name]++;
    }
    while (m--)
    {
        cin >> name;
        if (++name_cnt[name] == 2)
            cnt++;
    }

    cout << cnt << '\n';

    for (auto iter : name_cnt)
    {
        if (iter.second == 2)
        {
            cout << iter.first << '\n';
        }
    }

    return 0;
}