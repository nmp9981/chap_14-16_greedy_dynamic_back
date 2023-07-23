#include <iostream>
#include <vector>
using namespace std;

const int maxi = 100001;
int score[maxi][4];
int landSize;

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//초기화
void init(vector<vector<int> > land){
    landSize = land.size();
    for(int i=0;i<landSize;i++){
        for(int j=0;j<4;j++) score[i][j] = land[i][j];
    }
}
//점수 얻기
int GetScore(vector<vector<int>> land){
    for(int i=1;i<landSize;i++){
        score[i][0] = land[i][0]+max(score[i-1][1],max(score[i-1][2],score[i-1][3]));
        score[i][1] = land[i][1]+max(score[i-1][0],max(score[i-1][2],score[i-1][3]));
        score[i][2] = land[i][2]+max(score[i-1][0],max(score[i-1][1],score[i-1][3]));
        score[i][3] = land[i][3]+max(score[i-1][0],max(score[i-1][1],score[i-1][2]));
    }
    int maxScore = 0;
    for(int j=0;j<4;j++){
        if(maxScore < score[landSize-1][j]) maxScore = score[landSize-1][j];
    }
    return maxScore;
}
int solution(vector<vector<int> > land)
{
    init(land);//초기화
    return GetScore(land);//점수 얻기
}
