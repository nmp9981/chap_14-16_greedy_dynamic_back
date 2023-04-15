#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 10003;
int factory[maxi];//공장

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> factory[i];
}
//구매
void Buy() {
    int money = 0;
    for (int i = 0; i < n; i++) {
        if (factory[i + 1] > factory[i + 2]) {//한번에 못삼
            //2개씩 구매
            int cnt = min(factory[i], factory[i + 1] - factory[i + 2]);
            factory[i] -= cnt; factory[i+1] -= cnt;
            money += 5 * cnt;

            //이제 3개씩 구매 가능
            int cnt3 = min(factory[i], min(factory[i + 1], factory[i + 2]));
            factory[i] -= cnt3; factory[i + 1] -= cnt3; factory[i + 2] -= cnt3;
            money += 7 * cnt3;
        }
        else {//한번에 삼
            //3개 구매
            int cnt3 = min(factory[i], min(factory[i + 1], factory[i + 2]));
            factory[i] -= cnt3; factory[i+1] -= cnt3; factory[i+2] -= cnt3;
            money += 7 * cnt3;

            //2개 구매
            int cnt2 = min(factory[i], factory[i + 1]);
            factory[i] -= cnt2; factory[i + 1] -= cnt2;
            money += 5 * cnt2;
        }
        //남은거
        money += 3 * factory[i];
        factory[i] = 0;
    }
    cout << money;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Buy();//구매
    return 0;
}
