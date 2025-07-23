/*
    알고리즘 : 수학
    시간 복잡도 : O(1)
    참고 링크 : 부동 소수점 숫자(https://boycoding.tistory.com/152)
               iomanip 헤더(https://byeong9935.tistory.com/90)
    아이디어 : 정상에 도달한 날은 미끄러지지 않기 때문에, 마지막 날은 낮에 올라가는 것으로 끝난다.
              따라서 전체 높이에서 낮에 올라가는 높이만큼을 제외한 뒤(v - a),
              하루 동안 올라가는 높이(a - b)로 나눈다.
              이후 마지막 날을 더해 전체 소요 일수를 계산한다.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int v; // 나무 높이
    int a; // 낮에 올라가는 높이
    int b; // 밤에 미끄러지는 높이

    cin >> a >> b >> v;

    cout << fixed << setprecision(0) << ceil((double)(v - a) / (a - b)) + 1;

    return 0;
}