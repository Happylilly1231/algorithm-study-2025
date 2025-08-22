#include <iostream>
#include <vector>

using namespace std;

int v, e;
int infected_cnt = 0;
vector<vector<int>> graph;
vector<int> is_visited;

void DFS(int cur)
{
    is_visited[cur] = true;
    infected_cnt++;

    for (int next : graph[cur])
    {
        if (!is_visited[next])
            DFS(next);
    }
}

int main()
{
    cin >> v;
    cin >> e;

    graph.assign(v + 1, vector<int>(0, 0));
    is_visited.assign(v + 1, false);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    DFS(1);

    cout << infected_cnt - 1;

    return 0;
}
