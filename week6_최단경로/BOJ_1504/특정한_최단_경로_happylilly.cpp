/*
알고리즘: 다익스트라
시간 복잡도: O(MlogN)
참고 링크:
    - 다익스트라: https://charles098.tistory.com/11
아이디어:
    - 단일-쌍(Single-Pair) 문제고, 음수 가중치가 없으므로 다익스트라 알고리즘(+우선순위 큐)이 가장 효율적이다.
    - 특정한 정점 v1, v2를 반드시 거쳐야 하므로 두 가지 경우를 모두 확인한 뒤 더 짧은 거리를 출력해야 한다.
        1) 1 -> v1 -> v2 -> N의 경우
        2) 1 -> v2 -> v1 -> N의 경우
    - 우선순위 큐에서 처음으로 노드를 pop하는 시점에 해당 노드의 최단 경로가 확정되므로 해당 노드가 end노드일 때 바로 end의 최단 경로 거리를 반환한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int INF = 100000000; // 무한대 상수(경로 존재 X)

using namespace std;

vector<vector<pair<int, int>>> nodes; // 인접 노드 리스트 - {비용, 목적지 노드}
vector<int> dist;                     // 최단 경로 거리 벡터

int N; // 정점 수

// 다익스트라 최단 경로
int dijkstra(int start, int end)
{
    dist.assign(N + 1, INF); // 거리 벡터 초기값은 무한대 INF

    priority_queue<pair<int, int>> pq; // 우선순위 큐 {비용, 목적지 노드}

    // 시작 노드 방문
    pq.push({0, start}); // 우선순위 큐에 시작 노드 삽입
    dist[start] = 0;     // 시작 노드의 최단 경로 거리는 0으로 설정

    // 우선순위 큐가 빌 때까지
    while (!pq.empty())
    {
        // 우선순위 큐의 front 꺼내기(밑에서 음수로 바꿔서 삽입하므로 내림차순이 오름차순으로 바뀌어서 최소 비용을 가진 노드가 매번 꺼내짐)
        int cost = -pq.top().first; // 다시 -붙여서 양수로 원상 복구
        int here = pq.top().second;
        pq.pop(); // pop하는 시점에 해당 노드 최단 경로 확정됨
        if (here == end)
        {
            return dist[end]; // end의 최단 거리 반환
        }

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
    return dist[end];
}

// 특정한 최단 경로 구하기
int specificShortestPath(int v1, int v2)
{
    int arr[] = {1, v1, v2, N};
    int d, sum = 0;
    for (int i = 0; i < 3; i++)
    {
        d = dijkstra(arr[i], arr[i + 1]);
        if (d == INF)
            return -1;
        sum += d;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int M;
    cin >> N >> M;

    // 간선이 0이면 바로 -1 출력 후 종료
    if (M == 0)
    {
        cout << -1;
        return 0;
    }

    // 벡터 크기 초기화
    nodes.resize(N + 1);

    // 인접 노드 삽입
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        // 양방향이므로 양쪽 노드에 인접 노드 추가
        nodes[a].push_back({c, b});
        nodes[b].push_back({c, a});
    }

    // 받드시 거쳐야 하는 특정한 두 정점 입력
    int v1, v2;
    cin >> v1 >> v2;

    // 특정한 최단 경로 구하기
    // 1) 1 -> v1 -> v2 -> N의 경우
    int dist1 = specificShortestPath(v1, v2);
    if (dist1 == -1) // 경로 없으면 -1 출력 후 종료
    {
        cout << -1;
        return 0;
    }
    // 2) 1 -> v2 -> v1 -> N의 경우
    int dist2 = specificShortestPath(v2, v1);
    if (dist2 == -1) // 경로 없으면 -1 출력 후 종료
    {
        cout << -1;
        return 0;
    }

    // 둘 중 더 짧은 거리 출력
    cout << min(dist1, dist2);

    return 0;
}