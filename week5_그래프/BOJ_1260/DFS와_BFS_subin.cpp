/*
    알고리즘 : 그래프(DFS, BFS)
    시간복잡도 : O(n+m)
    아이디어 : 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문해야 하므로
              노드 i에 연결된 노드들을 원소로 갖는 연결리스트 graph[i]를 오름차순으로 정렬함
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> is_visited;

void DFS(int cur)
{
    is_visited[cur] = true;
    cout << cur << ' ';

    for (int next : graph[cur])
    {
        if (!is_visited[next])
            DFS(next);
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    is_visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : graph[cur])
        {
            if (!is_visited[next])
            {
                q.push(next);
                is_visited[next] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v;

    graph.assign(n + 1, vector<int>(0, 0));
    is_visited.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, e;
        cin >> u >> e;
        graph[u].emplace_back(e);
        graph[e].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(v);
    cout << '\n';

    is_visited.assign(n + 1, false);
    BFS(v);

    return 0;
}