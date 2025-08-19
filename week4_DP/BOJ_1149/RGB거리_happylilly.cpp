/*
알고리즘: DP
시간 복잡도: O(N)
참고 링크: x
아이디어:
    dp 이차원 배열로 i번째 집의 R(0), G(1), B(2)를 칠할 때 최소 비용을 저장한다.
    dp[i]에 저장된 3가지 값(R, G, B)에서 최솟값, 두번째 최솟값을 찾는다.
    i + 1번째 집에 j번째 색깔을 칠할 때 최소 비용 dp[i + 1][j]
        j가 dp[i]의 최솟값 인덱스와 같음 -> dp[i]의 두번째 최솟값(색깔이 겹치면 안되기 때문) + 해당 인덱스의 비용
        다름 -> dp[i]의 최솟값 + 해당 인덱스의 비용
    최종적으로 dp[N]에서의 최솟값이 최소 비용이 된다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int cost[1001][3];
    int dp[1001][3];

    // 입력
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // dp 초기화
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 1; i < N; i++)
    {
        // 최솟값, 두번째 최솟값 인덱스 구하기
        int min_idx = 0, sec_idx = 1;
        int min_sum = dp[i][0], sec_sum = dp[i][1];
        for (int j = 1; j < 3; j++)
        {
            if (dp[i][j] < min_sum)
            {
                sec_sum = min_sum;
                sec_idx = min_idx;

                min_sum = dp[i][j];
                min_idx = j;
            }
            else if (dp[i][j] < sec_sum)
            {
                sec_sum = dp[i][j];
                sec_idx = j;
            }
        }

        // dp[i + 1][j] 갱신
        for (int j = 0; j < 3; j++)
        {
            if (j == min_idx) // j가 최솟값 인덱스와 같으면 이전에서 최솟값 색깔 칠할 수 없음
            {
                dp[i + 1][j] = dp[i][sec_idx] + cost[i + 1][j]; // 두번째 최솟값 사용
            }
            else // 다르면 이전에서 최솟값 사용하는 것이 최소
            {
                dp[i + 1][j] = dp[i][min_idx] + cost[i + 1][j]; // 최솟값 사용
            }
        }
    }

    // 최종 최소 비용
    cout << min(min(dp[N][0], dp[N][1]), min(dp[N][1], dp[N][2]));

    return 0;
}