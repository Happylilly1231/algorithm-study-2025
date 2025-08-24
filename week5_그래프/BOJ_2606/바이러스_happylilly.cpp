/*
알고리즘: DFS
시간 복잡도: O(N + M)
참고 링크:
    - 그래프 인접 리스트(벡터): https://velog.io/@christer10/C%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84Graph
    - DFS: https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
아이디어: DFS 재귀로 간단하게 그래프 탐색
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> G;

int cnt = 0;

void dfs(int x)
{
    visited[x] = true; // 방문 처리
    cnt++;

    for (int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i];
        if (!visited[y])
        {
            dfs(y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;

    cin >> N;
    cin >> M;

    visited.resize(N + 1);
    G.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);

    cout << cnt - 1; // 1번 컴퓨터 제외

    return 0;
}