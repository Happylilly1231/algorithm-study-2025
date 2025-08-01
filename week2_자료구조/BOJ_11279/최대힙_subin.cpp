/*
    알고리즘 : 자료구조 - 힙
    시간복잡도 : O(nlogn)
    아이디어 : C++ STL의 vector, push_heap, pop_heap을 이용해 최대힙을 구현함
              (0인 아닌 값에서는 push_heap, 0인 값은 pop_heap 호출)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> v;

    cin >> n;

    while (n--)
    {
        int element;
        cin >> element;

        if (element == 0)
        {
            if (v.empty())
            {
                cout << v.size() << '\n';
            }
            else
            {
                pop_heap(v.begin(), v.end());
                cout << v.back() << '\n';
                v.pop_back();
            }
        }
        else
        {
            v.push_back(element);
            push_heap(v.begin(), v.end());
        }
    }

    return 0;
}