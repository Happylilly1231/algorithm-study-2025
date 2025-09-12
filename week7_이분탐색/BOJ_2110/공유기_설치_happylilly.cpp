/*
알고리즘: 이분탐색
시간 복잡도: O(NlogN)
참고 링크:
    - 이분탐색
        - https://m42-orion.tistory.com/69
    - 매개변수 탐색
        - https://m42-orion.tistory.com/70
아이디어:
    - 가장 인접한 두 공유기 사이의 거리를 이분 탐색의 mid로 설정하고 매개변수 탐색을 진행한다.
        - low = 1 / high = 처음 집과 마지막 집 사이의 거리(= 가장 먼 두 집 사이 거리)
        - 현재 가장 인접한 두 공유기 사이의 거리로 C개 설치 가능한지 여부 검사
            - 가능 -> 현재 가장 인접한 두 공유기 사이 거리 저장 & 늘려서 탐색
            - 불가능 -> 줄여서 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

// 이분 탐색
void binarySearch(int C)
{
    int low = 1;
    int high = v.back() - v.front(); // 처음 집과 마지막 집 사이의 거리(= 가장 먼 두 집 사이의 거리)
    int res;

    while (low <= high)
    {
        // 가장 인접한 두 공유기 사이의 거리 -> mid
        int adjacent_distance = (low + high) / 2;

        // 1번째 집은 무조건 설치
        int install_id = 0; // 이전 설치한 집 인덱스
        int cnt = 1;        // 설치한 집 수

        // 현재 가장 인접한 두 공유기 사이의 거리로 C개 설치 가능한지 여부 검사
        bool canInstall = false;
        for (int i = 1; i < v.size(); i++)
        {
            // 이전 설치한 집에서 현재 집까지의 거리가 현재 가장 인접한 두 공유기 사이의 거리 이상이면 -> 현재 집에 설치
            if (v[i] - v[install_id] >= adjacent_distance)
            {
                cnt++; // 설치한 집 수 증가

                // C개 설치 완료
                if (cnt == C)
                {
                    canInstall = true; // C개 설치 가능으로 설정
                    break;             // 검사 종료
                }

                install_id = i; // 이전에 설치한 집 인덱스를 현재 집 인덱스로 설정
            }
        }

        if (canInstall) // C개 설치 가능하면 -> 가장 인접한 거리 더 늘려도 될 수 있음
        {
            res = adjacent_distance;     // 현재 가장 인접한 두 공유기 사이의 거리를 결과 변수에 저장
            low = adjacent_distance + 1; // 가장 인접한 두 공유기 사이의 거리 늘려서 탐색
        }
        else // 불가능하면 -> 가장 인접한 거리 줄여야 됨
        {
            high = adjacent_distance - 1; // 가장 인접한 두 공유기 사이의 거리 줄여서 탐색
        }
    }
    cout << res << '\n'; // 결과 출력
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C, x;

    // 입력
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 이분 탐색
    binarySearch(C);

    return 0;
}