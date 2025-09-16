/*
    알고리즘 : 분할정복
    시간복잡도 : O(N^2)
    아이디어 : 가운데 칸은 비우고, 나머지 8칸만 재귀 호출
              base case에서 한 칸만 * 찍음
*/

#include <iostream>
using namespace std;

char star[2188][2188];

void printStar(int si, int sj, int n)
{
    if (n == 1)
    {
        star[si][sj] = '*';
        return;
    }

    int div = n / 3;
    // 3x3 블록 탐색
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != 1 || j != 1)
                printStar(si + i * div, sj + j * div, div);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 전체를 공백으로 초기화
    for (int i = 0; i < n; i++)
        fill_n(star[i], n + 1, ' ');

    printStar(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << star[i][j];
        cout << '\n';
    }
}
