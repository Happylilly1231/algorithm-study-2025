/*
알고리즘: DP
시간 복잡도: O(N)
참고 링크:
    - 참고한 반례1 : https://www.acmicpc.net/board/view/86384
    - 참고한 반례2 : https://www.acmicpc.net/board/view/77320
아이디어:
    dp 배열로 i번째 칸을 마지막으로 포함하는 구간의 최대 합을 저장한다.
    현재 구간의 최대 합 dp[i]는 이전 구간의 최대 합 dp[i - 1]과 현재 원소 arr[i]의 합이 현재 원소 arr[i]보다 크면 그 합을 저장하고(이전 구간까지 현재 구간에 합치기),
    그렇지 않으면 arr[i]만을 저장한다.
    dp[i]를 저장한 뒤, dp[i]가 max보다 크면 max를 dp[i]로 갱신한다.
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    int *arr = new int[n];
    int *dp = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int max = dp[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] + arr[i] > arr[i])
        {
            dp[i] = dp[i - 1] + arr[i];
        }
        else
        {
            dp[i] = arr[i];
        }

        if (dp[i] > max)
        {
            max = dp[i];
        }
    }

    cout << max << '\n';

    return 0;
}