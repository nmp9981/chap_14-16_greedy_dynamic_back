#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 120;
ll dp[maxi];

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    cin>>n;
    for(int i=4;i<=n;i++) dp[i] = dp[i-1]+dp[i-3];
    cout<<dp[n];
    return 0;
}
