/*
    알고리즘 : 수학
    아이디어 : n개의 양의 정수와 m개의 양의 정수를 각각 소인수분해하여
              각 소수의 등장 횟수를 map에 저장한 후,
              공통으로 나오는 소수에 대해 곱해 lcm를 구함
*/

#include <iostream>
#include <map>

using namespace std;

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

void lcm()
{
    long long result = 1;
    for (auto e : a_factors)
    {
        int cnt = max(e.second, b_factors[e.first]);
        while (cnt--)
        {
            result *= e.first;
        }
        b_factors.erase(e.first);
    }
    for (auto e : b_factors)
    {
        int cnt = max(e.second, a_factors[e.first]);
        while (cnt--)
        {
            result *= e.first;
        }
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        a_factors.clear();
        b_factors.clear();
        get_factors(a, a_factors);
        get_factors(b, b_factors);
        lcm();
    }
    return 0;
}