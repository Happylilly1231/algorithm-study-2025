/*
    알고리즘 : DP
    시간복잡도 : O(n)
    아이디어 : 현재 집을 특정 색으로 칠했을 때, 이전 집은 다른 두 색 중 최소 비용을 더함
              cost[i][0] : i번째 집을 빨강으로 칠하는 비용
              cost[i][1] : i번째 집을 초록으로 칠하는 비용
              cost[i][2] : i번째 집을 파랑으로 칠하는 비용
*/

#include <iostream>

using namespace std;

int main()
{
    int n, cost[1001][4];

    cin >> n;
    cin >> cost[0][0] >> cost[0][1] >> cost[0][2];
    for (int i = 1; i < n; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
        cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
        cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
    }

    cout << min(min(cost[n - 1][0], cost[n - 1][1]), cost[n - 1][2]);

    return 0;
}