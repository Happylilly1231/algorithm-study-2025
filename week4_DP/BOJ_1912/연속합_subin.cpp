/*
    알고리즘 : DP
    시간복잡도 : O(n)
    아이디어 : 정수(num)를 입력받아서
              이전까지의 부분합에 이어서 더하는게 큰지(sum+num)
              지금 원소부터 새로 더하는게 큰지(num)
              비교한 후, 지금까지의 최댓값(max_sum)을 갱신한다.
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;

    cin >> n;
    cin >> num;

    int sum = num, max_sum = num;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        sum = max(sum + num, num);
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;

    return 0;
}