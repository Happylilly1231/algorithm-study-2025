/*
    알고리즘 : 그리디 알고리즘
    시간 복잡도 : O(NlogN)
    아이디어 : 회의를 최대한 많이 배치하려면 끝나는 시간이 가장 빠른 회의부터 선택하는 게 최적
              회의를 끝내는 시간 기준(같다면 시작 시간 기준)으로 오름차순 정렬한 후,
              이전에 선택한 회의의 종료 시간 이후에 시작하는 회의만 선택
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> t1, pair<int, int> t2)
{
    if (t1.second == t2.second)
        return t1.first < t2.first;
    return t1.second < t2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 1;
    vector<pair<int, int>> t;

    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end(), compare);

    int end_time = t[0].second;
    for (int i = 1; i < n; i++)
    {
        if (t[i].first >= end_time)
        {
            cnt++;
            end_time = t[i].second;
        }
    }

    cout << cnt;

    return 0;
}