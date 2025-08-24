/*
알고리즘: DFS와 BFS
시간 복잡도:
    - DFS & BFS: O(N + M)
    - 인접 리스트 오름차순 정렬 : O(MlogM)
참고 링크:
    - 그래프 인접 리스트(벡터): https://velog.io/@christer10/C%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84Graph
    - DFS & BFS: https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
아이디어: 정점별 인접 리스트 sort 함수로 오름차순 정렬 + DFS, BFS 탐색
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> G;

void dfs(int x)
{
    visited[x] = true; // 방문 처리
    cout << x << ' ';

    for (int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i];
        if (!visited[y])
        {
            dfs(y);
        }
    }
}

void bfs(int start)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, V;

    cin >> N >> M >> V;

    // 벡터 사이즈 할당
    visited.resize(N + 1);
    G.resize(N + 1);

    // 그래프 입력
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 정점별 인접 리스트 오름차순 정렬(작은 순 탐색이므로)
    for (int i = 1; i <= N; i++)
    {
        sort(G[i].begin(), G[i].end());
    }

    dfs(V);
    cout << '\n';

    visited.assign(N + 1, false); // 방문 배열 초기화

    bfs(V);

    return 0;
}