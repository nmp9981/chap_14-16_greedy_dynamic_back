#include <iostream>
using namespace std;

string l,r;
//입력
void input() {
    cin >> l >> r;
    if (l.size() != r.size()) {//자릿수가 같게
        for (int i = 0; i < r.size() - l.size(); i++) l = '0' + l;
    }
}
//8탐색
void Search8() {
    //맨앞자리부터 비교
    int cnt = 0;
    for (int i = 0; i < r.size(); i++) {
        if (l[i] != r[i]) break;
        if (l[i] == '8' && r[i] == '8') cnt++;
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Search8();//8탐색
    return 0;
}
