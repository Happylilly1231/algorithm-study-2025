/*
알고리즘: BFS
시간 복잡도: O(NM)
참고 링크:
    - 그래프 인접 리스트(벡터): https://velog.io/@christer10/C%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84Graph
    - BFS: https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
아이디어: 입력은 이차원 벡터에 받되, 한 정점의 인덱스를 i * M + j라고 보고, 그래프(NM)와 방문 벡터(NM)의 형태는 변형하지 않았다. 최단 거리이므로 BFS를 이용한다. 방문 벡터 대신 거리 벡터를 이용한다.
    - BFS 최단 거리 계산
        인접 정점 y에 도달하는 최단 거리 = 현재 기준 정점 x까지 도달하는 최단 거리 + 1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v; // 입력 이차원 벡터

vector<int> d;         // 거리 벡터(미방문 : 0 / 방문 : 1 이상)
vector<vector<int>> G; // 그래프

int N, M;

int bfs(int start)
{
    queue<int> q;

    q.push(start);
    d[start] = 1; // 방문 처리 대신 거리 갱신(시작도 포함이므로 처음 거리는 1)

    while (!q.empty())
    {
        int x = q.front(); // 현재 기준 정점
        q.pop();

        for (int i = 0; i < G[x].size(); i++) // 현재 기준 정점의 인접 정점 순회
        {
            int y = G[x][i]; // 인접 정점
            if (d[y] == 0)   // 방문하지 않았으면(미방문 시 거리 갱신 안돼서 0이므로)
            {
                q.push(y);          // 큐 삽입
                d[y] = d[x] + 1;    // 방문 처리 대신 거리 갱신(인접 정점 y에 도달하는 최단 거리 = 현재 기준 정점 x까지 도달하는 최단 거리 + 1 <- bfs이므로)
                if (y == N * M - 1) // 현재 기준 정점에서 방문한 인접 정점이 마지막 정점이면
                {
                    return d[y]; // 마지막 정점까지의 최단 거리 반환
                }
            }
        }
    }
    return d[start];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // 벡터 크기 초기화
    v.assign(N, vector<int>(M));
    d.resize(N * M); // v를 순회하며 i * M + j를 인덱스로 넣을 것이므로 N * M이 된다.
    G.resize(N * M); // v를 순회하며 i * M + j를 인덱스로 넣을 것이므로 N * M이 된다.

    // 입력
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    // 상/하/좌/우가 1이면 해당 정점의 인접 정점 벡터에 상/하/좌/우 정점 추가
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == 1)
            {
                int a = i * M + j;
                if (i - 1 >= 0 && v[i - 1][j] == 1)
                {
                    int b = (i - 1) * M + j;
                    G[a].push_back(b);
                }
                if (i + 1 < N && v[i + 1][j] == 1)
                {
                    int b = (i + 1) * M + j;
                    G[a].push_back(b);
                }
                if (j - 1 >= 0 && v[i][j - 1] == 1)
                {
                    int b = i * M + j - 1;
                    G[a].push_back(b);
                }
                if (j + 1 < M && v[i][j + 1] == 1)
                {
                    int b = i * M + j + 1;
                    G[a].push_back(b);
                }
            }
        }
    }

    cout << bfs(0); // 0번이 시작 정점이므로 bfs 탐색하여 나온 마지막 정점까지의 최단 거리를 출력한다.

    return 0;
}