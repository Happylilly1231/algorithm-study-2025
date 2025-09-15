/*
    알고리즘 : 이분탐색
    시간복잡도 : O(NlogN)
    아이디어 : 집의 좌표를 정렬한 뒤, high를 가장 먼 두 집 사이의 거리로 초기화
              mid 이상 떨어지도록 공유기를 최대한 설치해보고
              설치한 개수가 c개 이상인 경우 거리(mid)를 늘려보고,
              그렇지 않으면 거리(mid)를 줄여 탐색함
              -> 결국 설치 가능한 최대 거리를 찾음
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c, max_dist = 0;
    int house[200001];
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }

    sort(house, house + n);

    int low = 1, high = house[n - 1] - house[0];
    int mid, cnt, prev;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cnt = 1, prev = house[0];
        for (int i = 1; i < n; i++)
        {
            if (prev + mid <= house[i])
            {
                prev = house[i];
                cnt++;
            }
        }

        if (cnt >= c)
        {
            max_dist = max(max_dist, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << max_dist;

    return 0;
}