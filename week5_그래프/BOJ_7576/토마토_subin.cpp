#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, min_day = 0;
vector<int> tomato;
vector<bool> is_visited;
vector<int> day;
vector<int> start_idx;

void BFS()
{
    queue<int> visit;
    for (int idx : start_idx)
    {
        visit.push(idx);
        is_visited[idx] = true;
        day[idx] = 0;
    }

    while (!visit.empty())
    {
        int cur = visit.front();
        visit.pop();
        min_day = day[cur];

        // cout << cur << " : " << day[cur] << '\n';

        int row = cur / n;
        int col = cur % n;
        // cout << row << " " << col << '\n';
        //   좌
        if (col > 0 && tomato[cur - 1] == 0 && !is_visited[cur - 1])
        {
            visit.push(cur - 1);
            is_visited[cur - 1] = true;
            day[cur - 1] = day[cur] + 1;
            // cout << cur - 1 << " ";
        }
        // 우
        if (col < n - 1 && tomato[cur + 1] == 0 && !is_visited[cur + 1])
        {
            visit.push(cur + 1);
            is_visited[cur + 1] = true;
            day[cur + 1] = day[cur] + 1;
            // cout << cur + 1 << " ";
        }
        // 상
        if (row > 0 && tomato[cur - n] == 0 && !is_visited[cur - n])
        {
            visit.push(cur - n);
            is_visited[cur - n] = true;
            day[cur - n] = day[cur] + 1;
            // cout << cur - n << " ";
        }
        // 하
        if (row < m - 1 && tomato[cur + n] == 0 && !is_visited[cur + n])
        {
            visit.push(cur + n);
            is_visited[cur + n] = true;
            day[cur + n] = day[cur] + 1;
            // cout << cur + n << " ";
        }
        // cout << '\n';
    }
}

int main()
{
    cin >> n >> m;

    tomato.assign(n * m, 0);
    is_visited.assign(n * m, false);
    day.assign(n * m, -1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i * n + j;
            cin >> tomato[idx];
            if (tomato[idx] == 1)
                start_idx.emplace_back(idx);
        }
    }

    BFS();

    for (int i = 0; i < day.size(); i++)
    {
        if (tomato[i] == 0 && day[i] < 0)
        {
            cout << -1;
            return 0;
        }
    }

    cout << min_day;

    return 0;
}