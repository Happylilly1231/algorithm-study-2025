/*
알고리즘: 분할정복
시간 복잡도: O(N^2logN)
참고 링크:
    - 분할정복
        - https://sectumsempra.tistory.com/93
아이디어:
    - 원래는 문자 3개씩 끊어서 생각했지만 안 풀려서 문자 하나씩 출력하기로 함
    - base: N = 3
        - 현재 i와 j를 N = 3인 정사각형의 위치로 변환 -> 나머지 연산 이용
            -> i % 3과 j % 3이 모두 1일 때, 즉 가운데일 때는 공백 출력
            -> 그렇지 않은 테두리에는 '*' 출력
    - 현재 i와 j가 N*N 정사각형 기준으로 위치 변환되었을 때, 현재 탐색 중인 N*N 정사각형 가운데 N/3*N/3 범위 안에 든다면 -> 공백 출력
    - 그렇지 않으면 -> 재귀 함수 호출 => N/3*N/3 정사각형 탐색
*/

#include <iostream>

using namespace std;

// 별 한 문자 찍기
void printStar(int i, int j, int N)
{
    if (N == 3) // base
    {
        if (i % 3 == 1 && j % 3 == 1) // N=3 정사각형의 가운데면(N=3 정사각형 기준으로 위치 변환을 위해 i와 j를 3으로 나머지 연산함)
        {
            cout << ' '; // 공백 출력
        }
        else // 테두리면
        {
            cout << '*'; // 별 출력
        }
        return; // 종료
    }

    // N이 3보다 큰 경우
    if ((i % N) / (N / 3) == 1 && (j % N) / (N / 3) == 1) // 현재 N*N 정사각형 가운데 N/3*N/3 범위 안에 들면(현재 N*N 정사각형 기준으로 위치 변환을 위해 i와 j를 N으로 나머지 연산함)
    {
        cout << ' '; // 공백 출력
    }
    else                        // 테두리 부분이면
        printStar(i, j, N / 3); // N을 3으로 나눠서 N/3*N/3 정사각형 범위 탐색
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    // 별 한 문자씩 찍음
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printStar(i, j, N); // 별 한 문자 찍기
        }
        cout << '\n';
    }
}