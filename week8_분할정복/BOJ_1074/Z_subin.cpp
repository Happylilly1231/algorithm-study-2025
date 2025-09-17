/*
    알고리즘 : 분할정복
    시간복잡도 : O(N)
    아이디어 : (r, c)가 속한 사분면으로 한 번에 건너뛰기 위해 (r, c)가 속하지 않은 사분면은 재귀 호출하지 말고 cnt를 한 번에 증가
                - 1사분면 : 1사분면 재귀호출
                - 2사분면 : 1사분면 건너뜀(cnt+=half*half) -> 2사분면 재귀호출
                - 3사분면 : 1,2사분면 건너뜀(cnt+=2*half*half) -> 3사분면 재귀호출
                - 4사분면 : 1,2,3사분면 건너뜀(cnt+=3*half*half) -> 4사분면 재귀호출
              => 매 단계에서 크기를 절반으로 줄이고 단 한개의 사분면만 재귀 호출
*/

#include <iostream>

using namespace std;

int n, r, c;
int cnt = 0;

void z(int si, int sj, int size)
{
    if (size == 1)
    {
        if (si == r && sj == c)
        {
            cout << cnt;
            exit(0);
        }
        cnt++;
        return;
    }

    int half = size / 2;
    // r, c가 어느 사분면에 있는지 체크
    if (r < si + half && c < sj + half) // 1사분면
    {
        z(si, sj, half);
    }
    else if (r < si + half && c >= sj + half) // 2사분면
    {
        cnt += half * half; // 1사분면 건너뜀
        z(si, sj + half, half);
    }
    else if (r >= si + half && c < sj + half) // 3사분면
    {
        cnt += 2 * half * half; // 1,2사분면 건너뜀
        z(si + half, sj, half);
    }
    else // 4사분면
    {
        cnt += 3 * half * half; // 1,2,3사분면 건너뜀
        z(si + half, sj + half, half);
    }
}

int main()
{
    cin >> n >> r >> c;

    int size = 1 << n;
    z(0, 0, size);

    return 0;
}