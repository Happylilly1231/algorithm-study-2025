/*
알고리즘: 재귀
시간 복잡도: O(2^N)
참고 링크:
    - 제곱 함수 pow: https://blockdmask.tistory.com/307
    - pow 형변환 문제: https://www.acmicpc.net/board/view/156402
아이디어: 3개의 원판을 start, assist, dest(destination)로 구분하고 재귀로 구한다.
    - 원판 옮기는 과정
        1. 원판 개수 N에 대하여 원판 N-1개를 보조 장대로 이동
        2. 마지막 원판 3번째(목적지) 장대로 옮기기
        3. 보조 장대에 있는 원판 N-1개를 다시 3번째(목적지) 원판에 쌓기
        => 이 과정이 재귀적으로 이루어짐
*/

#include <iostream>
#include <cmath>

using namespace std;

// 하노이 탑 이동 함수
void hanoi_move(int N, int start, int assist, int dest) // N은 원판 개수로 초기화되지만, 이동 출력문이 나올 때 실질적으로 몇번째 원판을 옮기고 있는지를 뜻한다.
{
    // 베이스 케이스: N이 1일 때, 즉 1번 원반을 옮길 때 start에서 dest로 이동하는 것을 출력하고 종료한다.
    if (N == 1)
    {
        cout << start << ' ' << dest << '\n';
        return;
    }

    hanoi_move(N - 1, start, dest, assist); // N-1개의 목적지 -> 보조 장대
    cout << start << ' ' << dest << '\n';   // 첫번째 장대에 남아있는 마지막 원판
    hanoi_move(N - 1, assist, start, dest); // 보조 장대에 있던 N-1개를 다시 목적지에 쌓기
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    cout << int(pow(2, N) - 1) << '\n'; // 원판 이동 수: 2^N - 1

    hanoi_move(N, 1, 2, 3); // start: 1 / assist: 2 / dest(destination) : 3

    return 0;
}