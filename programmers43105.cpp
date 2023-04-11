#include <string>
#include <vector>
using namespace std;

const int maxi = 500;
int dp[maxi][maxi];//최댓값

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//삼각형 합
int TriangleSum(vector<vector<int>> &triangle){
    int maxSum = 0;
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0) dp[i][j] = triangle[i][j]+dp[i-1][j];
            else if(j==triangle[i].size()-1) dp[i][j] = triangle[i][j]+dp[i-1][j-1];
            else dp[i][j] = triangle[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            
            maxSum = max(dp[i][j],maxSum);
        }
    }
    return maxSum;
}
int solution(vector<vector<int>> triangle) {
    return TriangleSum(triangle);
}
