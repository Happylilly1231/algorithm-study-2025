/*
알고리즘 : 수학
시간 복잡도 : O(1)
참고 링크 :
    올림 - https://blockdmask.tistory.com/112
    정수끼리의 나눗셈 - https://eeeun.tistory.com/38
아이디어 : while문으로 하면 시간 초과되니까 공식을 세우자
*/

#include <cmath>  // 올림 함수를 사용하기 위해 cmath 라이브러리 사용
#include <iostream>

using std::cin;
using std::cout;

int main() {
    int A;    // 낮에 올라가는 미터
    int B;    // 밤에 미끄러지는 미터
    int V;    // 나무 높이
    int day;  // 걸린 일수

    cin >> A >> B >> V;  // 입력 받기

    /*
    공식으로 걸린 일수 계산
    (V - A) -> 마지막 전날에 올라갔어야 하는 양
    (A - B) -> 하루에 올라가는 양
    (V - A) / (A - B) + 1 -> 마지막 전날까지의 일수(소수로 나올 수 있음, 무조건 올림) + 마지막 날 하루 = 최종 걸린 일수
    */
    day = ceil((double)(V - A) / (A - B)) + 1;

    cout << day;  // 출력

    return 0;
}