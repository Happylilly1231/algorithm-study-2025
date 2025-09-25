/*
    알고리즘 : 그리디 알고리즘
    시간 복잡도 : O(N)
    아이디어 : 5kg 봉지를 최대한 많이 사용하는 것이 유리
              -> 5kg 봉지를 최대로 사용하고 남은 봉지 무게가 3kg으로 나눠지면 출력
              -> 위 방법으로 답을 찾지 못했다면, Nkg이 3kg으로 나눠지는지 확인
              -> 어떤 방법으로도 안 된다면 -1 출력
*/

#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 0;

    cin >> n;

    int i = n / 5 + 1;
    while (i-- > 0)
    {
        if ((n - i * 5) % 3 == 0)
        {
            cout << i + (n - i * 5) / 3;
            return 0;
        }
    }

    if (n % 3 == 0)
        cout << n / 3;
    else
        cout << -1;

    return 0;
}