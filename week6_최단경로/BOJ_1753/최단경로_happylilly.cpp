/*
알고리즘: 다익스트라
시간 복잡도: O(MlogN)
참고 링크:
    - 다익스트라: https://charles098.tistory.com/11
아이디어:
    - 단일-출발(Single-Source) 문제고, 음수 가중치가 없으므로 다익스트라 알고리즘이 가장 효율적이다. 다익스트라에서 시간 복잡도를 더 줄이기 위해 우선순위 큐를 사용하여 최단 거리 노드를 찾아 꺼낼 때 비용을 줄인다.
*/

#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 100000000; // 무한대 상수(경로 존재 X)

using namespace std;

vector<vector<pair<int, int>>> nodes; // 인접 노드 리스트 - {비용, 목적지 노드}
vector<int> dist;                     // 최단 경로 거리 벡터

// 다익스트라 최단 경로
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq; // 우선순위 큐 {비용, 목적지 노드} -> 최단

    // 시작 노드 방문
    pq.push({0, start}); // 우선순위 큐에 시작 노드 삽입
    dist[start] = 0;     // 시작 노드의 최단 경로 거리는 0으로 설정

    // 우선순위 큐가 빌 때까지
    while (!pq.empty())
    {
        // 우선순위 큐의 front 꺼내기(밑에서 음수로 바꿔서 삽입하므로 내림차순이 오름차순으로 바뀌어서 최소 비용을 가진 노드가 매번 꺼내짐)
        int cost = -pq.top().first; // 다시 -붙여서 양수로 원상 복구
        int here = pq.top().second;
        pq.pop();

        // 이미 최단 경로 거리가 저장되어 있으면 건너뛰기(우선순위 큐에서 꺼낸 거리(비용)가 저장된 거리보다 크다면 이건 최단 거리 갱신되기 전 오래된 값임)
        if (dist[here] < cost)
            continue;

        // here의 인접 노드 중에서
        for (int i = 0; i < nodes[here].size(); i++)
        {
            int via_cost = cost + nodes[here][i].first; // here을 거쳐서 가는 here의 인접 노드로 가는 비용
            int dest_node = nodes[here][i].second;      // 목적지 노드(here의 인접 노드)

            // here을 거쳐서 가는게 빠르면 거리 갱신 후 push
            if (via_cost < dist[dest_node])
            {
                dist[dest_node] = via_cost;      // 최단 경로 거리 갱신
                pq.push({-via_cost, dest_node}); // 우선순위큐에서 꺼낼 때 오름차순으로 꺼내기 위해 음수로 바꿈
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int N, M, K;
    cin >> N >> M;
    cin >> K;

    // 벡터 크기 초기화
    nodes.resize(N + 1);
    dist.assign(N + 1, INF); // 거리 벡터 초기값은 무한대 INF

    // 인접 노드 삽입
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        nodes[u].push_back({w, v});
    }

    // 다익스트라 최단 경로 구하기(음수 가중치 없으므로)
    dijkstra(K);

    // 시작점에서 모든 정점으로의 최단 경로 출력
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}