/*
    알고리즘 : BFS
    시간복잡도 : O(n^2)
    아이디어 : nxm 격자를 그래프 형태로 구성하여 미로에서 1인 칸들을 노드로 취급
              각 칸에 대해 상하좌우가 1이면 간선을 연결
              BFS를 돌면서 (1, 1)에서 (n, m)까지의 최단경로 길이를 구함
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> is_visited;
int disitance[10001];

void BFS(int start)
{
    queue<int> visit;
    visit.push(start);
    is_visited[start] = true;
    disitance[start] = 1;

    while (!visit.empty())
    {
        int cur = visit.front();
        visit.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!is_visited[next])
            {
                is_visited[next] = true;
                disitance[next] = disitance[cur] + 1;
                visit.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n * m + 1, vector<int>(0, 0));
    is_visited.assign(n * m + 1, false);

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            int idx = i * m + j + 1;
            if (line[j] == '1')
                graph[idx].emplace_back(idx);
        }
    }

    for (int i = 1; i <= n * m; i++)
    {
        if (graph[i].empty())
            continue;
        int row = (i - 1) / m;
        int col = (i - 1) % m;

        // 좌
        if (col > 0 && !graph[i - 1].empty())
            graph[i].emplace_back(i - 1);
        // 우
        if (col < m - 1 && !graph[i + 1].empty())
            graph[i].emplace_back(i + 1);
        // 상
        if (row > 0 && !graph[i - m].empty())
            graph[i].emplace_back(i - m);
        // 하
        if (row < n - 1 && !graph[i + m].empty())
            graph[i].emplace_back(i + m);
    }

    BFS(1);
    cout << disitance[n * m];
}