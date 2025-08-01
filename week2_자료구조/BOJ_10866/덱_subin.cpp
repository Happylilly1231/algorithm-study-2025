#include <iostream>
#include <deque>

using namespace std;

constexpr unsigned int HashCode(const char *str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    deque<int> d;

    cin >> n;

    while (n--)
    {
        char operation[15];
        cin >> operation;

        switch (HashCode(operation))
        {
        case HashCode("push_front"):
        {
            int value;
            cin >> value;
            d.push_front(value);
            break;
        }
        case HashCode("push_back"):
        {
            int value;
            cin >> value;
            d.push_back(value);
            break;
        }
        case HashCode("pop_front"):
        {
            if (d.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << d.front() << '\n';
                d.pop_front();
            }
            break;
        }
        case HashCode("pop_back"):
        {
            if (d.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << d.back() << '\n';
                d.pop_back();
            }
            break;
        }
        case HashCode("size"):
        {
            cout << d.size() << '\n';
            break;
        }
        case HashCode("empty"):
        {
            if (d.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
            break;
        }
        case HashCode("front"):
        {
            if (d.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << d.front() << '\n';
            }
            break;
        }
        case HashCode("back"):
        {
            if (d.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << d.back() << '\n';
            }
            break;
        }
        }
    }

    return 0;
}