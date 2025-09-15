/*
    알고리즘 : 다익스트라 알고리즘
    시간복잡도 : O((V+E)logV)
    아이디어 : 1. 다익스트라(Dijstra) 알고리즘을 3번 실행
                1) 1번 정범에서 출발 -> dist[dt1], dist[dt2] 구하기
                2) dt1에서 출발 -> dist[dt2], dist[n] 구하기
                3) dt2에서 출발 -> dist[n] 구하기
              2. 두 가지 경로 길이 계산
                1) 경로 1 : 1 -> dt1 -> dt2 -> n (to_dt1 + dt1_to_dt2 + dt2_to_n)
                2) 경로 2 : 1 -> dt2 -> dt1 -> n (to_dt2 + dt1_to_dt2 + dt1_to_n)
              3. 두 개의 정점을 지나는 최단 경로 길이 출력
                min(INF, min(경로 1, 경로 2)) -> 두 경로 모두 불가능하면 -1 출력
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[801];
vector<int> dist;
int n, e, INF = 1e8;

void dijkstra(int start)
{
    dist.assign(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, start));
    dist[start] = 0;

    while (!q.empty())
    {
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();

        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next_node = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            if (dist[next_node] > next_cost)
            {
                q.push({next_cost, next_node});
                dist[next_node] = next_cost;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v, w;

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int dt1, dt2;
    cin >> dt1 >> dt2;

    dijkstra(1);
    int to_dt1 = dist[dt1];
    int to_dt2 = dist[dt2];

    dijkstra(dt1);
    int dt1_to_dt2 = dist[dt2];
    int dt1_to_n = dist[n];

    dijkstra(dt2);
    int dt2_to_n = dist[n];

    int result = min(INF, min(to_dt1 + dt1_to_dt2 + dt2_to_n, to_dt2 + dt1_to_dt2 + dt1_to_n));

    if (result == INF)
        cout << -1;
    else
        cout << result;

    return 0;
}