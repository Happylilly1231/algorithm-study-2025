/*
    알고리즘 : DP
    시간복잡도 : O(n^2)
    아이디어 : bottom-Up + tabulation으로 구현
              int/long long으로 큰 수를 더할 수 없으므로 문자열로 큰 수 덧셈 구현
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> bottom_table;

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
        res += sum % 10 + '0';
    }
    if (carry > 0)
        res += carry + '0';
    reverse(res.begin(), res.end());

    return res;
}

string fibonicci(int n)
{
    bottom_table.reserve(n + 1);
    bottom_table.push_back("0");
    bottom_table.push_back("1");

    for (int i = 2; i <= n; i++)
    {
        bottom_table.push_back(addNum(bottom_table[i - 1], bottom_table[i - 2]));
    }
    return bottom_table[n];
}

int main()
{
    int n;
    cin >> n;

    cout << fibonicci(n);

    return 0;
}