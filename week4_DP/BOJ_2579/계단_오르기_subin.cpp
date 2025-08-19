/*
    알고리즘 : DP
    시간복잡도 : O(n)
    아이디어 : 한 번에 한 계단 또는 두 계단씩 오를 수 있으며, 세 계단 연속으로 밟을 수 없음
              dp[i][0] : i번째 계단을 밟지 않았을 때
              dp[i][1] : i번째 계단을 밟았고, 직전 계단은 밟지 않은 경우
              dp[i][2] : i번째 계단을 밟았고, 직전 계단도 밟은 경우
*/
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, stair[301];
    int dp[301][3] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stair[i];
    }

    dp[0][1] = stair[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][1] = dp[i - 1][0] + stair[i];         // 직전 계단을 밟지 않고 현재 계단을 밟음
        dp[i][2] = dp[i - 1][1] + stair[i];         // 직전 계단을 밟고 현재 계단도 밟음
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]); // 현재 계단을 안 밟으려면 이전 계단은 반드시 밟아야 함
    }

    cout << max(dp[n - 1][1], dp[n - 1][2]); // 마지막 계단은 반드시 밟아야 함

    return 0;
}