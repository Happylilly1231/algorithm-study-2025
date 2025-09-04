/*
    알고리즘 : 벨만-포드 알고리즘
    시간복잡도 : O(NM)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

int main()
{
    int n, m, f, t, w, INF = 1e8;
    vector<Edge> edges;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> f >> t >> w;
        edges.push_back({f, t, w});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to])
            {
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    // 음수 사이클 체크
    for (auto &e : edges)
    {
        if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to])
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}