/*
알고리즘: 분할정복
시간 복잡도: O(log(2^N)) = O(N)
참고 링크:
    - 분할정복
        - https://sectumsempra.tistory.com/93
아이디어:
    - 4등분이므로 4개의 구역으로 나눠서 재귀 호출
    - 현재 구역 탐색(인자는 좌상단 i, j 인덱스와 구역 크기 n만 있으면 됨)
        - 목표 r, c가 현재 구역 범위 내에 없다면(재귀로 탐색 필요 x) -> 현재 구역 전체 cnt 더하고 탐색 종료 => 시간 초과 해결
        - base: N = 2 -> r, c 찾으면 cnt 출력 후 탐색 종료
*/

#include <iostream>
#include <cmath>

using namespace std;

int r, c, cnt = 0;

// 목표 r, c가 범위 내에 있는지 확인하는 함수
bool isInRange(int start_i, int start_j, int N)
{
    if (start_i <= r && r < start_i + N && start_j <= c && c < start_j + N)
        return true; // 범위 내 존재
    else
        return false; // 미존재
}

// Z 패턴 방문
void visit(int start_i, int start_j, int N)
{
    if (!isInRange(start_i, start_j, N)) // 현재 구역 범위 내에 존재하지 않으면
    {
        cnt += N * N; // 현재 구역 전체 cnt 더해주기
        return;       // 바로 현재 구역 탐색 종료(어차피 이 구역에 없으므로)
    }

    // 기본 상태 N = 2
    if (N == 2)
    {
        for (int i = start_i; i < start_i + N; i++)
        {
            for (int j = start_j; j < start_j + N; j++)
            {
                if (i == r && j == c) // 목표를 찾으면
                {
                    cout << cnt; // cnt 출력
                    return;      // 찾았으니 종료
                }
                cnt++; // cnt 증가
            }
        }
        return; // 종료
    }

    // 4등분 탐색
    visit(start_i, start_j, N / 2);
    visit(start_i, start_j + N / 2, N / 2);
    visit(start_i + N / 2, start_j, N / 2);
    visit(start_i + N / 2, start_j + N / 2, N / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N >> r >> c;

    // Z 패턴 방문 - 함수에서 N은 편의를 위해 2^N으로 한다.
    visit(0, 0, pow(2, N));
}