#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 101;
const int maxPay = 100001;
const int mod = 1000000007;
int caseNum[maxi][maxPay];//i번까지 돈으로 j원을 주는 경우의 수

//초기화
void init(int n, vector<int> money){
    sort(money.begin(),money.end());//오름차순 정렬
    for(int j=0;j<=n;j++){
        if(j%money[0]==0) caseNum[0][j] = 1;//money[0]으로 몰아주기
    }
}
//거스름 돈
int Change(int n,vector<int> money){
    int moneySize = money.size();
    for(int i=1;i<moneySize;i++){
        for(int j=0;j<=n;j++){
            if(j<money[i]) caseNum[i][j] = caseNum[i-1][j];//돈 부족
            else caseNum[i][j] = (caseNum[i][j-money[i]]+caseNum[i-1][j])%mod; //money[i]를 사용O 경우 + 사용X 경우
        }
    }
    return caseNum[moneySize-1][n];
}
int solution(int n, vector<int> money) {
    init(n,money);//초기화
    return Change(n,money);//거스름 돈;
}
