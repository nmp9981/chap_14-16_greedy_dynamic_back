#include <iostream>
using namespace std;

int c,n;
const int maxi = 21;
const int maxProfit = 100001;
int value[maxi];//가격
int reward[maxi];//가치
int profit[maxProfit];//비용 i를 투자하고 얻은 손님

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> c>>n;
    for (int i = 1; i <= n; i++) cin >> value[i] >> reward[i];
}
//호텔
int Hotel() {
    //고객의 수
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxProfit; j++) {
            if (j-value[i]>=0) {
                profit[j] = max(profit[j], profit[j - value[i]] + reward[i]);
            }
        }
    }
    //고객의 최솟값
    for (int i = 1; i < maxProfit; i++) {
        if (profit[i] >= c) return i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Hotel();//호텔
    return 0;
}
