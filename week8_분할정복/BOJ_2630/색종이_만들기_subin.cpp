#include <iostream>

using namespace std;

int n, white_cnt = 0, blue_cnt = 0;
int paper[129][129];

void mergeSort(int si, int sj, int n)
{
    int blue = 0, white = 0;
    for (int i = si; i < si + n; i++)
    {
        for (int j = sj; j < sj + n; j++)
        {
            if (paper[i][j] == 1)
                blue++;
            else
                white++;
        }
    }

    if (blue == n * n)
    {
        blue_cnt++;
        return;
    }
    if (white == n * n)
    {
        white_cnt++;
        return;
    }

    mergeSort(si, sj, n / 2);
    mergeSort(si + n / 2, sj, n / 2);
    mergeSort(si, sj + n / 2, n / 2);
    mergeSort(si + n / 2, sj + n / 2, n / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    }

    mergeSort(0, 0, n);

    cout << white_cnt << '\n'
         << blue_cnt;
}