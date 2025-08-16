/*
    알고리즘 : DP
    시간복잡도 : O(n^2)
    아이디어 : Top-Down + memoization으로 구현
              int/long long으로 큰 수를 더할 수 없으므로 문자열로 큰 수 덧셈 구현
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> topDown_memo;

string addNum(string a, string b)
{
    string res;

    int maxLen = max(a.length(), b.length());
    a = string(maxLen - a.length(), '0') + a;
    b = string(maxLen - b.length(), '0') + b;

    int carry = 0;
    for (int i = maxLen - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        res += (sum % 10) + '0';
    }

    if (carry > 0)
        res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

string fibonicci(int n)
{
    if (n < 2)
        return to_string(n);
    if (topDown_memo[n] != "")
        return topDown_memo[n];
    topDown_memo[n] = addNum(fibonicci(n - 1), fibonicci(n - 2));
    return topDown_memo[n];
}

int main()
{
    int n;
    cin >> n;

    topDown_memo.assign(n + 1, "");

    cout << fibonicci(n);

    return 0;
}