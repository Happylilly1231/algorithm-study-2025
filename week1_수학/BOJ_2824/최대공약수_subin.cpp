/*
    알고리즘 : 수학
    참고 링크 : map 사용법(https://life-with-coding.tistory.com/305)
    아이디어 : n개의 양의 정수와 m개의 양의 정수를 각각 소인수분해하여
              각 소수의 등장 횟수를 map에 저장한 후,
              공통으로 나오는 소수에 대해 곱해 gcd를 구함
*/

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

constexpr long long MAX = 1000000000;
map<int, int> a_factors, b_factors;

void get_factors(int n, map<int, int> &factors)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, num;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        get_factors(num, a_factors);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        get_factors(num, b_factors);
    }

    long long result = 1;
    bool overflow = false;

    for (auto e : a_factors)
    {
        if (!b_factors[e.first])
            continue;
        int cnt = min(e.second, b_factors[e.first]);
        while (cnt--)
        {
            result *= e.first;
            if (result >= MAX)
            {
                result %= MAX;
                overflow = true;
            }
        }
    }

    if (overflow)
        cout << setw(9) << setfill('0') << result;
    else
        cout << result;
}