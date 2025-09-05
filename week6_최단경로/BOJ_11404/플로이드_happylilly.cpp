/*
알고리즘: 플로이드 워셜
시간 복잡도: O(N^3)
참고 링크:
    - 플로이드 워셜
        - https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
        - https://ansohxxn.github.io/algorithm/floyd/
아이디어:
    - 전체-쌍(All-Pair) 문제이므로 플로이드 워셜 알고리즘을 사용한다.
        - 플로이드 워셜 알고리즘
            1. 최소 비용 벡터 값을 가중치 벡터 값으로 초기화
            2. 한 정점을 거쳐가는 노드로 삼고, 모든 가중치와 거쳐갈 때 비용을 비교하여 최소 비용 갱신 -> 이를 모든 정점에 걸쳐 반복
*/

#include <iostream>
#include <vector>

constexpr int INF = 100000000; // 무한대 상수(경로 존재 X)

using namespace std;

vector<vector<int>> w; // 가중치 벡터
vector<vector<int>> d; // 최소 비용 벡터

int N; // 정점 수

// 플로이드 워셜 최단 경로
void floydWarshall()
{
    // 최소 비용 벡터 크기 초기화
    d.assign(N + 1, vector<int>(N + 1));

    // 최소 비용 벡터 값을 가중치 벡터 값으로 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            d[i][j] = w[i][j];
        }
    }

    // 한 정점을 거쳐가는 노드로 삼고, 모든 가중치와 거쳐갈 때 비용을 비교하여 최소 비용 갱신 -> 이를 모든 정점에 걸쳐 반복
    for (int k = 1; k <= N; k++) // k = 거쳐가는 노드
    {
        for (int i = 1; i <= N; i++) // i = 출발 노드
        {
            for (int j = 1; j <= N; j++) // j = 도착 노드
            {
                int via_cost = d[i][k] + d[k][j]; // k 노드를 거쳐갈 때의 비용
                if (via_cost < d[i][j])           // 거쳐갈 때 비용이 현재 비용보다 작으면
                {
                    d[i][j] = via_cost; // 최소 비용 갱신
                }
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
    cin >> N;
    cin >> M;

    // 가중치 벡터 INF로 초기화
    w.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++)
    {
        w[i][i] = 0;
    }

    // 가중치 정보 저장
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (c < w[a][b])
        {
            w[a][b] = c;
        }
    }

    // 플로이드 워셜 최단 경로 구하기
    floydWarshall();

    // 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (d[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}