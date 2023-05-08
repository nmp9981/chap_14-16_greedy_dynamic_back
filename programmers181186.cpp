#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
const int maxi = 100001;
ll dp[maxi];//경우의 수
ll dpAdd[maxi];//추가량

//타일 채우기
void Tile(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = dp[2]+2*dp[1]+5*dp[0];
    for(int i=4;i<maxi;i++){
        //기본 케이스
        dp[i] = dp[i-1]+2*dp[i-2]+5*dp[i-3];
        //추가 케이스
        if(i>=6) dpAdd[i] = dpAdd[i-3]+2*dp[i-4]+2*dp[i-5]+4*dp[i-6];
        else{
            if(i==4) dpAdd[4] = 2;
            else if(i==5) dpAdd[5] = 4;
        }
        //테이스 개수
        dp[i]+=dpAdd[i];
        dp[i]%=mod;
    }
}
int solution(int n) {
    int answer = 0;
    Tile();//타일 채우기
    return dp[n];
}
