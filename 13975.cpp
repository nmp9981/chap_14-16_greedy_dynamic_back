#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int k;
priority_queue<ll, vector<ll>, greater<ll>> pq;//최소힙

//입력
void input() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
}
//파일 합치기
void SumFile() {
    ll cost = 0;
    while (pq.size() > 1) {
        ll firstCost = pq.top();
        pq.pop();
        ll secondCost = pq.top();
        pq.pop();

        ll newCost = firstCost + secondCost;//두 파일을 합친 가격
        cost += newCost;
        pq.push(newCost);
    }
    pq.pop();
    cout << cost << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        SumFile();//파일 합치기
    }
    return 0;
}
