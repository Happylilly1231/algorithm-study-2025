/*
알고리즘: DFS
시간 복잡도: O(N^2logN)
참고 링크:
    - 그래프 인접 리스트(벡터): https://velog.io/@christer10/C%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84Graph
    - DFS: https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
아이디어: 입력은 이차원 벡터에 받되, 한 정점의 인덱스를 i * N + j라고 보고, 그래프(N^2)와 방문 벡터(N^2)의 형태는 변형하지 않았다. DFS를 이용한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v; // 입력 이차원 벡터

vector<bool> visited;  // 방문 벡터
vector<vector<int>> G; // 그래프

int cnt = 0;   // 단지 내 집 수
vector<int> r; // 단지 내 집 수 벡터

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

    int N;
    cin >> N;

    // 벡터 크기 초기화
    v.assign(N, vector<int>(N));
    visited.resize(N * N); // v를 순회하며 i * N + j를 인덱스로 넣을 것이므로 N * N이 된다.
    G.resize(N * N);       // v를 순회하며 i * N + j를 인덱스로 넣을 것이므로 N * N이 된다.

    // 입력
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    // 상/하/좌/우가 1이면 해당 정점의 인접 정점 벡터에 상/하/좌/우 정점 추가
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[i][j] == 1)
            {
                int a = i * N + j;
                if (i - 1 >= 0 && v[i - 1][j] == 1)
                {
                    int b = (i - 1) * N + j;
                    G[a].push_back(b);
                    // G[b].push_back(a); // 어차피 중복되므로 넣지 않는다.
                }
                if (i + 1 < N && v[i + 1][j] == 1)
                {
                    int b = (i + 1) * N + j;
                    G[a].push_back(b);
                    // G[b].push_back(a);
                }
                if (j - 1 >= 0 && v[i][j - 1] == 1)
                {
                    int b = i * N + j - 1;
                    G[a].push_back(b);
                    // G[b].push_back(a);
                }
                if (j + 1 < N && v[i][j + 1] == 1)
                {
                    int b = i * N + j + 1;
                    G[a].push_back(b);
                    // G[b].push_back(a);
                }
            }
        }
    }

    // 0인 정점이나 이미 방문했던 정점(이미 단지에 들어감) 제외 순회하며 dfs로 단지 계산
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[i][j] != 0 && !visited[i * N + j]) // 새로운 1인 정점(아직 단지에 들지 않음)
            {
                // 단지 계산 시작
                dfs(i * N + j);   // 단지 내 집 수 계산
                r.push_back(cnt); // 단지 내 집 수 결과 벡터에 추가
                cnt = 0;          // 단지 내 집 수 초기화
            }
        }
    }

    // 단지 내 집 수 오름차순 정렬 -> O(N^2logN)
    sort(r.begin(), r.end());

    // 출력
    cout << r.size() << '\n'; // 단지 수
    for (auto cnt : r)
    {
        cout << cnt << '\n'; // 단지 내 집 수
    }

    return 0;
}