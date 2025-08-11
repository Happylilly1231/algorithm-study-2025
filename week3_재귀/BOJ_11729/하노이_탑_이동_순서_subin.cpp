/*
    알고리즘 : 재귀
    시간복잡도 : O(2^n)
    아이디어 : 첫 번째 장대에 있는 n-1개의 원판들을 두 번째 장대에 옮기고
              첫 번째 장대에 남아있는 원판을 세 번째 장대에 옮긴다.
              그리고 두 번째 장대에 있는 n-1개의 원판들을 세 번째 장대로 옮긴다.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int hanoi_num = 0;
string str = "";

void towerOfHanoi(int n, int prev, int by, int next)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, prev, next, by);
    hanoi_num++;
    str += to_string(prev) + " " + to_string(next) + "n";
    towerOfHanoi(n - 1, by, prev, next);
}

int main()
{
    int n;

    cin >> n;

    towerOfHanoi(n, 1, 2, 3);

    cout << hanoi_num << '\n';

    istringstream ss(str);
    string substr;
    while (getline(ss, substr, 'n'))
    {
        cout << substr << '\n';
    }

    return 0;
}