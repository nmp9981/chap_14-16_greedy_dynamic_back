#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 100001;
int A[maxi];//수열
int B[maxi];
int changed[maxi];//B[i]는 몇번째 수인가?

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
}
//수열 변환
void Change() {
    for (int i = 0; i < n; i++) changed[B[i]] = i;
    for (int i = 0; i < n; i++) A[i] = changed[A[i]];
}
//LIS 구하기
void Lis() {
    vector<int> Lcs;
    for (int i = 0; i < n; i++) {
        if (Lcs.size() == 0 || Lcs[Lcs.size() - 1] < A[i]) Lcs.push_back(A[i]);
        else {
            int pos = lower_bound(Lcs.begin(), Lcs.end(), A[i]) - Lcs.begin();
            Lcs[pos] = A[i];
        }
    }
    cout << Lcs.size();//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Change();//수열 변환
    Lis();//LIS 구하기
    return 0;
}
