/*
알고리즘: 그리디
시간 복잡도: O(NlogN)
참고 링크: x
아이디어:
    - 최적의 해는 회의가 끝나는 시간이 짧은 순으로 겹치지 않도록 고르는 것이다. 회의 시간을 저장할 때 pair를 사용하였으나, pair의 기본 정렬은 first 다음 second를 확인하는 것이므로 cmp라는 커스텀 비교 함수를 만들어 second 다음 first로 정렬될 수 있도록 하였다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    vector<pair<int, int>> time;

    cin >> N;

    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        time.push_back(make_pair(s, e));
    }

    sort(time.begin(), time.end(), cmp);

    pair<int, int> prev = time[0];
    int cnt = 1;
    for (int i = 1; i < time.size(); i++)
    {
        if (time[i].first >= prev.second)
        {
            cnt++;
            prev = time[i];
        }
    }

    cout << cnt;

    return 0;
}