#include <iostream>

using std::cin;
using std::cout;

int main() {
    float x;

    cin >> x;

    cout << std::fixed;
    cout.precision(6);
    cout << x;

    return 0;
}
