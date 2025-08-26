/*
    알고리즘 : 다익스트라 알고리즘
    시간복잡도 : O(ElogV)
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}

    bool operator<(const Edge &ref) const
    {
        return weight > ref.weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, k, from, to, weight;
    priority_queue<Edge> q;
    vector<pair<int, int>> graph[20001];
    vector<int> dist(20001, INT_MAX);

    cin >> v >> e;
    cin >> k;
    for (int i = 0; i < e; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    q.push(Edge(k, 0));
    dist[k] = 0;

    while (!q.empty())
    {
        int cur = q.top().to;
        int weight = q.top().weight;
        q.pop();

        if (weight > dist[cur])
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int next_weight = weight + graph[cur][i].second;

            if (dist[next] > next_weight)
            {
                dist[next] = next_weight;
                q.push(Edge(next, next_weight));
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << '\n';
    }

    return 0;
}