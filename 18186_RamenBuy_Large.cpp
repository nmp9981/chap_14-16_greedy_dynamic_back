#include <iostream>
using namespace std;
typedef long long ll;

ll n,b,c;
const int maxi = 1000003;
ll factory[maxi];//공장

//min
inline ll min(ll x, ll y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>b>>c;
    for (int i = 0; i < n; i++) cin >> factory[i];
}
//구매
void Buy() {
    //하나씩 사는게 이득
    if (b < c) {
        ll total = 0;
        for (int i = 0; i < n; i++) total+= factory[i];
        cout << b * total;
        return;
    }

    //같이 사는게 더 이득일때가 있다.
    ll money = 0;
    for (int i = 0; i < n; i++) {
        if (factory[i + 1] > factory[i + 2]) {//한번에 못삼
            //2개씩 구매
            ll cnt = min(factory[i], factory[i + 1] - factory[i + 2]);
            factory[i] -= cnt; factory[i + 1] -= cnt;
            money += (b+c) * cnt;

            //이제 3개씩 구매 가능
            ll cnt3 = min(factory[i], min(factory[i + 1], factory[i + 2]));
            factory[i] -= cnt3; factory[i + 1] -= cnt3; factory[i + 2] -= cnt3;
            money += (b+2*c) * cnt3;
        }
        else {//한번에 삼
            //3개 구매
            ll cnt3 = min(factory[i], min(factory[i + 1], factory[i + 2]));
            factory[i] -= cnt3; factory[i + 1] -= cnt3; factory[i + 2] -= cnt3;
            money += (b+2*c) * cnt3;

            //2개 구매
            ll cnt2 = min(factory[i], factory[i + 1]);
            factory[i] -= cnt2; factory[i + 1] -= cnt2;
            money += (b+c) * cnt2;
        }
        //남은거
        money += b * factory[i];
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
