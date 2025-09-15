/*
알고리즘: 분할정복
시간 복잡도: O(N^2logN)
참고 링크:
    - 분할정복
        - https://sectumsempra.tistory.com/93
아이디어:
    - 4등분이므로 4번의 분할 함수 재귀 호출
    - 4등분으로 만들어진 각 구역의 모든 색 탐색(인자는 좌상단 i, j 인덱스와 구역 크기 n만 있으면 됨)
        -> 모두 하얀색이거나 파란색이라면 각 색의 색종이 수 증가 후 반복 종료
*/

#include <iostream>

using namespace std;

int arr[128][128];
int blue_paper_cnt = 0, white_paper_cnt = 0;

// 분할
void divide(int start_i, int start_j, int n)
{
    // 현재 구역의 모든 색 탐색
    int b = 0, w = 0;
    for (int i = start_i; i < start_i + n; i++)
    {
        for (int j = start_j; j < start_j + n; j++)
        {
            if (arr[i][j] == 0)
                w++;
            else
                b++;
        }
    }

    // 반복 종료 조건 확인 - 모두 하얀색이거나 파란색일 때
    if (w == n * n) // 모두 하얀색
    {
        white_paper_cnt++; // 하얀색 색종이 수 증가
        return;            // 반복 종료
    }
    else if (b == n * n) // 모두 파란색
    {
        blue_paper_cnt++; // 파란색 색종이 수 증가
        return;           // 반복 종료
    }

    // 4등분
    divide(start_i, start_j, n / 2);
    divide(start_i + n / 2, start_j, n / 2);
    divide(start_i, start_j + n / 2, n / 2);
    divide(start_i + n / 2, start_j + n / 2, n / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    divide(0, 0, N);

    cout << white_paper_cnt << '\n'
         << blue_paper_cnt;

    return 0;
}