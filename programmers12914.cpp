#include <string>
#include <vector>

using namespace std;
const int maxi = 2001;
const long long mod = 1234567;
long long dp[maxi];//경우의 수

long long solution(int n) {
    long long answer = 0;
    dp[1] = 1;dp[2] = 2;
    for(int i=3;i<=n;i++) dp[i] = (dp[i-1]+dp[i-2])%mod;//피보나치 수
    answer = dp[n];
    return answer;
}
