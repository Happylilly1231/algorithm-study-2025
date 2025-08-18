/*
알고리즘: DP
시간 복잡도: O(N)
참고 링크:
    - 참고한 반례1(3%에서 틀리는 코드) : https://www.acmicpc.net/board/view/157882
    - 참고한 반례2 : https://www.acmicpc.net/board/view/143824
아이디어: 도착 칸에 연속(N-1 -> N)으로 밟고 오느냐, 불연속(N-2 -> N)으로 밟고 오느냐를 나눠서 2번 호출한 다음 그 중에 더 큰 것을 반환하자
    - 로직 :
        0/1 RETURN
        연속 : N - 1 & 불연속
            => score[N] + D[N - 1]
        불연속 : N - 2 & 연속/불연속 둘 다 실행
            => score[N] + (C[N - 2], D[N - 2] 중에 더 큰 것)
        -> 여기서 C, D 배열에 저장되어 있지 않은 것은 재귀로 호출하고 저장되어 있으면 그냥 값을 불러와서 쓰면 됨
*/

#include <iostream>
#include <algorithm>

using namespace std;

int score[301]; // 입력받은 계단의 점수 배열

int C[301]; // C[N]은 N-1칸을 밟고 연속으로 N칸을 밟았을 때 N칸에서의 점수
int D[301]; // D[N]은 N-2칸을 밟고 불연속적으로 N칸을 밟았을 때 N칸에서의 점수

// 점수 계산
void calculateScore(int N, bool isContinuous)
{
    if (N == 0 || N == 1) // 0(시작)은 이미 0 초기화되어 있고, 1은 따로 저장함
        return;

    if (isContinuous) // 연속(N-1 -> N)이면
    {
        // N-1칸을 불연속으로 밟고 온 것임(연속으로 밟고 왔으면 연속이 2번이 되므로, 계단 3개를 연속으로 오를 수 없다는 규칙에 위배)
        // 불연속
        if (D[N - 1] == 0) // 저장되어 있지 않으면 재귀로 계산, 저장되어 있으면 그냥 배열에 있는 것 씀
            calculateScore(N - 1, false);
        C[N] = score[N] + D[N - 1]; // 연속으로 밟고 N칸에 온 경우 C[N] <- 현재 N칸 점수와 N칸까지 불연속으로 밟고 온 점수 더해서 저장
    }
    else // 불연속(N-2 -> N)이면
    {
        // N-2칸을 연속으로 밟고 올 수도 있고, 불연속으로 밟고 올 수도 있음
        // 연속
        if (C[N - 2] == 0)
            calculateScore(N - 2, true);
        // 불연속
        if (D[N - 2] == 0)
            calculateScore(N - 2, false);
        D[N] = score[N] + max(C[N - 2], D[N - 2]); // 불연속으로 밟고 N칸에 온 경우 D[N] <- 현재 N칸 점수와 연속과 불연속의 경우에서 더 큰 점수를 더해서 저장
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    // 계단 수 입력
    cin >> N;

    // 점수 입력
    for (int i = 1; i <= N; i++)
    {
        cin >> score[i];
    }

    // 계단 0개 : C, D 배열이 전역변수이므로 0 초기화됨
    // 계단 1개 : 1번 계단의 점수가 최종 점수이므로 미리 저장
    C[1] = score[1];
    D[1] = score[1];

    // 연속으로 밟고 도착 N칸에 올라왔는지 여부에 따라 나눠서 2번 호출
    calculateScore(N, true);  // 연속(N-1 -> N)
    calculateScore(N, false); // 불연속(N-2 -> N)

    // 연속과 불연속의 경우 중 더 큰 점수 출력
    cout << max(C[N], D[N]);

    return 0;
}