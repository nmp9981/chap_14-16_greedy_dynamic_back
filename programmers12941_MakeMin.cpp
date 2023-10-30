#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//내림 차순
bool cmp(int i,int j){
    return j<i;
}
//최솟값 만들기
int MakeMin(vector<int> A, vector<int> B){
    int Asize = A.size();
    int total = 0;
    for(int i=0;i<Asize;i++) total+=(A[i]*B[i]);
    return total;
}
int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(),A.end());//오름차순 정렬
    sort(B.begin(),B.end(),cmp);//내림차순 정렬
    return MakeMin(A,B);//최솟값 만들기
}
