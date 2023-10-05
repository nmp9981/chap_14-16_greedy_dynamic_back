#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;//최소힙

//세팅
void Setting(vector<int> B){
    int bSize = B.size();
    for(int i=0;i<bSize;i++) pq.push(B[i]);
}
//대결
int Fight(vector<int> A){
    int aSize = A.size();
    int score = 0;//점수
    for(int i=0;i<aSize;i++){
        while(!pq.empty() && pq.top()<=A[i]) pq.pop();//A[i]이하인것 제거
        
        if(pq.size()==0) break;//비교 완료
        score++;//득점
        pq.pop();
    }
    return score;
}
int solution(vector<int> A, vector<int> B) {
    sort(A.begin(),A.end());//A를 오름차순으로 정렬
    Setting(B);//세팅
    return Fight(A);//대결
}
