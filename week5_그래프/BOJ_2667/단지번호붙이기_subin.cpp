/*
    알고리즘 : 그래프(DFS, BFS)
    시간복잡도 : O(n^2)
    아이디어 : nxn 격자를 그래프 형태로 구성하여 집(1)인 칸들을 노드로 취급
              각 칸에 대해 상하좌우가 집이면 간선을 연결
              DFS를 돌면서 하나의 연결된 집의 모임을 찾고, 해당 단지의 집 개수를 house에 저장
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> is_visited;
vector<int> house;

void DFS(int cur, int house_num)
{
    is_visited[cur] = true;
    house[house_num]++;

    for (int next : graph[cur])
    {
        if (!is_visited[next])
            DFS(next, house_num);
    }
}

int main()
{
    cin >> n;
    graph.assign(n * n + 1, vector<int>(0, 0));
    is_visited.assign(n * n + 1, false);

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            // 집이 있는 곳을 graph에 삽입
            if (line[j] == '1')
            {
                int idx = i * n + j + 1;
                graph[idx].emplace_back(idx);
            }
        }
    }

    // 현재 집(i)과 연결된 집을 graph[i]에 삽입
    for (int i = 1; i <= n * n; i++)
    {
        int row = (i - 1) / n;
        int col = (i - 1) % n;

        if (graph[i].empty())
            continue;

        // 좌
        if (col > 0 && !graph[i - 1].empty())
            graph[i].push_back(i - 1);
        // 우
        if (col < n - 1 && !graph[i + 1].empty())
            graph[i].push_back(i + 1);
        // 상
        if (row > 0 && !graph[i - n].empty())
            graph[i].push_back(i - n);
        // 하
        if (row < n - 1 && !graph[i + n].empty())
            graph[i].push_back(i + n);
    }

    for (int i = 1; i <= n * n; i++)
    {
        if (!graph[i].empty() && !is_visited[i])
        {
            house.push_back(0);
            DFS(i, house.size() - 1);
        }
    }

    cout << house.size() << '\n';
    sort(house.begin(), house.end());

    for (int h : house)
        cout << h << '\n';

    return 0;
}