/*
    알고리즘 : 다익스트라 알고리즘
    시간복잡도 : O(ElogK)
    아이디어 : 각 정점마다 k개의 최단경로 비용만 유지함(최대힙)
              이 힙의 top()은 현재까지 k개 중 가장 큰 값임
              새로운 경로 비용이 들어오면
                1. 그 정점 힙의 크기가 k 미만이라면 그냥 넣음
                2. k개가 이미 있다면 top()(가장 큰 값)보다 작을 때만 pop()하고 push(next_cost)함
              -> 각 정점의 힙에는 항상 그 정점으로의 k개의 가장 작은 비용이 유지되고, 마지막에 top()이 k번째 최단경로가 됨
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
priority_queue<int> dist[1001];

void dijkstra(int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    dist[1].push(0); // 1->1로 가는 첫 번째 최단경로는 0임

    while (!q.empty())
    {
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next_node = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            if (dist[next_node].size() < k)
            {
                dist[next_node].push(next_cost);
                q.push(make_pair(next_cost, next_node));
            }
            else if (dist[next_node].top() > next_cost)
            {
                dist[next_node].pop();
                dist[next_node].push(next_cost);
                q.push(make_pair(next_cost, next_node));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k, u, v, w;
    cin >> n >> e >> k;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(k);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() < k)
            cout << -1 << '\n';
        else
            cout << dist[i].top() << '\n';
    }

    return 0;
}