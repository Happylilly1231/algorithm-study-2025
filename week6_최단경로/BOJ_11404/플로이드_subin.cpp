/*
    알고리즘 : 플로이드 워셜 알고리즘
    시간복잡도 : O(N^3)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, f, t, w, INF = 1e8;
    vector<vector<int>> cost;

    cin >> n;
    cin >> m;

    cost.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> f >> t >> w;
        cost[f][t] = min(cost[f][t], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] == INF)
                cout << "0 ";
            else
                cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}