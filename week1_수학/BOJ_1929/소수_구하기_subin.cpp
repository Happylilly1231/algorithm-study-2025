/*
    알고리즘 : 수학, 에라토스테네스의 체
    시간 복잡도 : O(nloglogn)
    참고 링크 : 에라토스테네스의 체(https://namu.wiki/w/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98%20%EC%B2%B4)
               에라토스테네스의 체(https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)
    아이디어 : 재귀적으로 2부터 √n까지의 수 중 소수인 수(PrimeNumber(i) == 0)로
              n을 나눠보고 나누어떨어지면 합성수로 판단 -> 시간 초과
    해결 방법 : 에라토스테네스의 체
*/

#include <iostream>
#include <cmath>

constexpr int MAX = 1000001;
bool prime_number[MAX];

int main()
{
    int m, n;

    std::cin >> m >> n;
    std::fill_n(prime_number, MAX, true);
    prime_number[0] = prime_number[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = i * i; j <= n; j += i)
            prime_number[j] = false;
    }

    for (int i = m; i <= n; i++)
    {
        if (prime_number[i])
            std::cout << i << '\n';
    }

    return 0;
}