/*
    알고리즘 : DP
    시간복잡도 : O(n^2)
    아이디어 : LIS + LDS 조합으로 바이토닉 부분 수열 구함
              up_dp[i] : 인덱스 i를 끝으로 하는 가장 긴 증가하는 부분 수열(LIS) 길이
              down_dp[i] : 인덱스 i를 시작으로 하는 가장 긴 감소하는 부분 수열(LDS) 길이
              bitonic_len[i] = up_dp[i] + down_up[i] - 1
    LIS 아이디어 : 앞에서부터 i까지 보면서, 자신보다 작은 값의 위치를 기준으로 해당 dp 중 가장 큰 값+1으로 갱신함
    LDS 아이디어 : 뒤에서부터 i 이후를 보면서, 자신보다 작은 값의 위치를 기준으로 해당 dp 중 가장 큰 값+1으로 갱신함
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max_len = 0;
    int ar[1001], up_dp[1001] = {0}, down_dp[1001] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ar[i] > ar[j])
                up_dp[i] = max(up_dp[i], up_dp[j]);
        }
        up_dp[i] += 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
                down_dp[i] = max(down_dp[i], down_dp[j]);
        }
        down_dp[i] += 1;
        if (max_len < up_dp[i] + down_dp[i] - 1)
            max_len = up_dp[i] + down_dp[i] - 1;
    }
    cout << max_len;

    return 0;
}