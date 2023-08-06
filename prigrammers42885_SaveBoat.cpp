#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//구명보트 태우기
int Boat(vector<int> weight, int limit){//2명 고르는 문제이므로 투포인터 사용
    int left = 0;int right = weight.size()-1;
    int cnt = 0;
    while(left<=right){
        if(weight[left]+weight[right]<=limit){//탑승 가능
            left++;
            right--;
        }else right--;//탑승 불가
        cnt++;
    }
    return cnt;
}
int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());//몸부게 순으로 정렬
    return Boat(people,limit);//구명보트 태우기
}
