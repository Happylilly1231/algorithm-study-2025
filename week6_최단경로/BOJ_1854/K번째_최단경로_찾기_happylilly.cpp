/*
알고리즘: 다익스트라
시간 복잡도: O(MKlogMK)
참고 링크:
    - 다익스트라: https://charles098.tistory.com/11
아이디어:
    - 단일-출발(Single-Source) 문제이므로 다익스트라 알고리즘(+우선순위 큐)을 사용한다.
    - 간선 완화 과정에서 아래 두 경우에 해당할 때 k번째까지 최단 거리를 노드별 우선순위 큐에 저장&갱신하고 pq에도 push한다.
        1) 아직 해당 도착 노드에 대해 k번째까지 최단 거리가 저장되지 않았다면
            -> 일단 노드별 우선순위 큐에 저장
        2) k개의 거리가 저장되어 있지만, 저장된 최대 거리보다 작은 거리를 발견했을 때(=현재까지 해당 도착 노드로 가는 경로의 거리 중 k번째 최단 거리 발견)
            -> k번째 최단 거리 갱신
    - 참고: 노드별 우선순위 큐에는 k개까지만 저장되지만, pq에는 노드별로 k번 이상 push될 수 있다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int INF = 100000000; // 무한대 상수(경로 존재 X)

using namespace std;

vector<vector<pair<int, int>>> nodes; // 인접 노드 리스트 - {비용, 목적지 노드}
vector<priority_queue<int>> dist;     // 노드별 k번째까지 최단 거리 저장하는 우선순위 큐 벡터

int N, K;

// 다익스트라 k번째 최단 경로
void dijkstra(int start)
{
    dist.resize(N + 1);                // 노드별 우선순위 큐 벡터 크기 초기화
    priority_queue<pair<int, int>> pq; // (거리 계산할 때 쓰는 기존의)우선순위 큐 {비용, 목적지 노드}

    // 시작 노드 방문
    pq.push({0, start}); // 우선순위 큐에 시작 노드 삽입
    dist[start].push(0); // 시작 노드의 최단 경로 거리는 0으로 설정

    // 우선순위 큐가 빌 때까지
    while (!pq.empty())
    {
        // 우선순위 큐의 front 꺼내기(밑에서 음수로 바꿔서 삽입하므로 내림차순이 오름차순으로 바뀌어서 최소 비용을 가진 노드가 매번 꺼내짐)
        int cost = -pq.top().first; // 다시 -붙여서 양수로 원상 복구
        int here = pq.top().second;
        pq.pop();

        // 현재 노드 here의 인접 노드 탐색(간선 완화)
        for (int i = 0; i < nodes[here].size(); i++)
        {
            int via_cost = cost + nodes[here][i].first; // here을 거쳐서 가는 here의 인접 노드로 가는 비용
            int dest_node = nodes[here][i].second;      // 목적지 노드(here의 인접 노드)

            // k번째까지 거리 저장&갱신(우선순위 큐에 push)
            if (dist[dest_node].size() < K) // 아직 해당 도착 노드에 대해 k번째까지 최단 거리가 저장되지 않았다면
            {
                // 일단 노드별 우선순위 큐에 저장
                dist[dest_node].push(via_cost);  // here를 거쳐가는 거리(계산한 거리)를 해당 도착 노드 거리 저장 우선순위 큐에 집어넣기
                pq.push({-via_cost, dest_node}); // 우선순위 큐에서 꺼낼 때 오름차순으로 꺼내기 위해 음수로 바꿈
            }
            else if (via_cost < dist[dest_node].top()) // k개의 거리가 저장되어 있지만, 저장된 최대 거리보다 작은 거리를 발견했을 때(=현재까지 해당 도착 노드로 가는 경로의 거리 중 k번째 최단 거리 발견)
            {
                // k번째 최단 거리 갱신
                dist[dest_node].pop();           // 저장된 최대 거리 삭제
                dist[dest_node].push(via_cost);  // 계산한 거리, 즉 k번째 최단 거리 삽입
                pq.push({-via_cost, dest_node}); // 우선순위 큐에서 꺼낼 때 오름차순으로 꺼내기 위해 음수로 바꿈
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int M;
    cin >> N >> M >> K;

    // 벡터 크기 초기화
    nodes.resize(N + 1);

    // 인접 노드 삽입
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        nodes[u].push_back({w, v});
    }

    // 다익스트라 k번째 최단 경로 구하기(음수 가중치 없으므로)
    dijkstra(1);

    // 시작점에서 모든 정점으로의 k번째 최단 거리 출력
    for (int i = 1; i <= N; i++)
    {
        if (dist[i].size() < K)
            cout << -1 << '\n';
        else
            cout << dist[i].top() << '\n';
    }

    return 0;
}