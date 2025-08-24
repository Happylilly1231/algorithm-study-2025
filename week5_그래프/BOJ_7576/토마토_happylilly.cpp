/*
알고리즘: BFS
시간 복잡도: O(NM)
참고 링크:
    - 그래프 인접 리스트(벡터): https://velog.io/@christer10/C%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84Graph
    - BFS: https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
아이디어:
    - 방문 벡터 대신에 일수(거리) 벡터 이용
        - BFS 최단 거리 계산
            인접 정점 y에 도달하는 최단 거리 = 현재 기준 정점 x까지 도달하는 최단 거리 + 1
    - 그래프 벡터에 인접 정점 저장하는 건 공간 낭비인 것 같아서 BFS 함수 안에서 상하좌우만 검사해줌
    - 시작이 여러 개면 큐를 배열로 만드는 게 아니라 그냥 처음에 시작 원소들을 큐에 차례로 넣으면 됨
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v; // 입력 이차원 벡터
vector<int> d;         // 일수(거리) 벡터(미방문: -1 / 방문: 0 이상)
int M, N;
int day = 0; // 토마토가 모두 익는 최소 날짜(익지 못하면 -1)

// 인접 정점 검사
void checkAdjacencyVertex(queue<int> &q, int x, int r, int c)
{
    if (r < 0 || r >= N || c < 0 || c >= M) // 인덱스 범위 벗어나면
        return;                             // 바로 종료

    int y = r * M + c;               // 일수 벡터 d에서의 인덱스 y 계산
    if (v[r][c] != -1 && d[y] == -1) // 토마토가 있는데 아직 안 익었으면
    {
        // 익게 하기
        q.push(y);       // 큐 삽입
        d[y] = d[x] + 1; // 방문 처리 대신 일수 갱신(인접 정점 y에 도달하는 최단 거리 = 현재 기준 정점 x까지 도달하는 최단 거리 + 1 이용)
        day = d[y];      // day 갱신
    }
}

void bfs(vector<int> s) // 인자: 시작 정점 벡터
{
    // 큐에 시작 정점 벡터 원소들 삽입
    queue<int> q;
    for (int i = 0; i < s.size(); i++)
    {
        q.push(s[i]);
        d[s[i]] = 0; // 방문 처리 대신 일수 0으로 초기화(모든 토마토가 이미 익어있는 상태면 0이 출력되어야 하기 때문)
    }

    // 큐가 빌 때까지 순회
    while (!q.empty())
    {
        int x = q.front(); // 현재 기준 정점
        q.pop();           // 큐에서 꺼내기
        int i = x / M;     // row 번호
        int j = x % M;     // column 번호

        // 현재 기준 정점의 인접 정점(상하좌우) 검사해서 안 익은 토마토 있으면 익게 함
        checkAdjacencyVertex(q, x, i - 1, j);
        checkAdjacencyVertex(q, x, i + 1, j);
        checkAdjacencyVertex(q, x, i, j - 1);
        checkAdjacencyVertex(q, x, i, j + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    // 벡터 초기화
    v.assign(N, vector<int>(M));
    d.assign(N * M, -1); // v를 순회하며 i * M + j를 인덱스로 넣을 것이므로 N * M이 된다. 초기값은 미방문 상태인 -1이다.
    vector<int> s;       // 시작 정점 벡터

    // 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];

            // 1인 정점, 즉 익은 토마토는 시작 정점 벡터에 삽입
            if (v[i][j] == 1)
            {
                int a = i * M + j;
                s.push_back(a);
            }
        }
    }

    // bfs 탐색 진행(익을 토마토 익음)
    bfs(s);

    // 그 뒤 안 익은 토마토 있는지 검사
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] != -1 && d[i * M + j] == -1) // 안 익은 토마토가 있으면
            {
                // -1 출력하고 바로 종료
                cout << -1;
                return 0;
            }
        }
    }

    // 다 익었으면 토마토가 모두 익을 때까지의 최소 날짜 출력
    cout << day;

    return 0;
}