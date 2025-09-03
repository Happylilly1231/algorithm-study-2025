/*
알고리즘: 벨만 포드
시간 복잡도: O(NM)
참고 링크:
    - 벨만 포드: https://yabmoons.tistory.com/365
    - 출력 초과 관련 내용: https://www.acmicpc.net/board/view/141726
아이디어:
    - 단일-출발(Single-Source) 문제고, 음수 가중치가 있으므로 벨만 포드 알고리즘을 사용한다.
        - 벨만 포드 알고리즘
            1. N-1번 모든 간선 탐색하며 거리 갱신
            2. 음수 사이클 검사를 위해 한 번 더 모든 간선 탐색
                -> 거리 갱신 필요 => 음수 사이클 존재
    - 문제에서 가능한 최소 거리 = 최대 정점 수(N-1번 반복 후 1번 더 반복) * 최대 간선 수(모든 간선 탐색, 사이클 존재) * 최소 가중치 = 500 * 6000 * (-10000) = -30억
    => 따라서 최단 거리 벡터 dist와 via_cost의 자료형은 long long이어야 한다.
*/

#include <iostream>
#include <vector>

constexpr int INF = 100000000; // 무한대 상수(경로 존재 X)

using namespace std;

// 간선 구조체
struct Edge
{
    int from, to, w;

    Edge(int u, int v, int w) : from(u), to(v), w(w) {}
};

vector<Edge> edges;     // 간선 벡터
vector<long long> dist; // 최단 경로 거리 벡터(최악의 경우 500 * 6000 * (-10000) = -30억까지 가능하기 때문)

int N; // 정점 수

// 벨만 포드 최단 경로
bool bellmanFord(int start)
{
    dist.assign(N + 1, INF); // 거리 벡터 초기값은 무한대 INF

    // 시작 노드 방문
    dist[start] = 0; // 시작 노드의 최단 경로 거리는 0으로 설정

    // 모든 간선 탐색하며 거리 갱신을 N-1번 반복
    for (int i = 0; i < N - 1; i++)
    {
        // 모든 간선 탐색
        for (int j = 0; j < edges.size(); j++)
        {
            int from = edges[j].from;
            int to = edges[j].to;
            int cost = edges[j].w;

            // 간선의 출발정점이 한번도 계산되지 않았으면 건너뛰기
            if (dist[from] == INF)
                continue;

            // 거리 갱신 판단
            long long via_cost = dist[from] + cost; // 출발정점을 거쳐서 to로 가는 거리 via_cost 계산
            if (dist[to] > via_cost)                // via_cost가 to에 저장된 최단 거리보다 작으면
                dist[to] = via_cost;                // 거리 갱신
        }
    }

    // 음수 사이클 검사를 위해 한 번 더 모든 간선 탐색하며 거리 갱신
    for (int i = 0; i < edges.size(); i++)
    {
        int from = edges[i].from;
        int to = edges[i].to;
        int cost = edges[i].w;

        // 간선의 출발정점이 한번도 계산되지 않았으면 건너뛰기
        if (dist[from] == INF)
            continue;

        // 거리 갱신 판단
        long long via_cost = dist[from] + cost; // 출발정점을 거쳐서 to로 가는 거리 via_cost 계산
        if (dist[to] > via_cost)                // via_cost가 to에 저장된 최단 거리보다 작으면
        {
            // 거리 갱신 필요 -> 음수 사이클 존재!(음수 사이클이 아니라면 이미 N-1번 반복 탐색을 마쳤기 때문의 모든 정점의 최단 거리가 구해져 있으므로 갱신이 되지 않기 때문)
            return false; // 최단 경로 계산 불가능
        }
    }
    return true; // 최단 경로 계산 가능
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int M;
    cin >> N >> M;

    // 간선 삽입
    int A, B, C;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        edges.push_back(Edge(A, B, C));
    }

    // 벨만 포드 최단 경로
    if (!bellmanFord(1)) // 음의 사이클을 가진 경우
    {
        cout << -1;
    }
    else // 음의 사이클이 없어서 최단 경로를 구할 수 있는 경우
    {
        // 시작점에서 모든 정점으로의 최단 경로 출력
        for (int i = 2; i <= N; i++) // 시작점인 1번 제외 후 2번부터 출력
        {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}