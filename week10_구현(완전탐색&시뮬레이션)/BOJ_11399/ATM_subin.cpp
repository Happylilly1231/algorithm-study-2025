/*
    알고리즘 : 그리디 알고리즘
    시간 복잡도 : O(NlogN)
    아이디어 : 돈을 인출하는데 걸리는 시간이 큰 사람이 먼저 줄을 선다면
              뒤에 오는 사람의 기다림이 길어지므로
              돈을 인출하는데 걸리는 시간이 적은 사람부터 줄을 서게 함
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int p[1001];
    int wait[1001] = {0};
    int min_time = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);

    min_time = wait[0] + p[0];
    for (int i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + p[i - 1];
        min_time += wait[i] + p[i];
    }

    cout << min_time;

    return 0;
}