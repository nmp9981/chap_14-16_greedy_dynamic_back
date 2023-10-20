#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//영양분
struct Nutrient {
    int protein, fat, carbohydrate, vitamin, price;
};
int n,mp,mf,ms,mv;
const int inf = 750000;
int minCost = inf;//최소 비용
vector<Nutrient> Food;//음식
vector<int> selectFoodNum;//선택한 음식 번호
vector<int> resultFood;//최종 선택 음식
//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        Food.push_back({ p,f,s,v,c });
    }
}
//최소 영양소 조건
bool isMinNutrient() {
    int totalNutrient[4] = { 0,0,0,0 };//단백질, 지방 ,탄수화물,비타민
    for (int i : selectFoodNum) {
        totalNutrient[0] += Food[i].protein;
        totalNutrient[1] += Food[i].fat;
        totalNutrient[2] += Food[i].carbohydrate;
        totalNutrient[3] += Food[i].vitamin;
    }
    //조건 만족
    if (totalNutrient[0] >= mp && totalNutrient[1] >= mf && totalNutrient[2] >= ms && totalNutrient[3] >= mv) return true;

    return false;//하나라도 불만족
}
//총 비용
int TotalPrice() {
    int total = 0;
    for (int i : selectFoodNum) total += Food[i].price;
    return total;
}
//음식 선택
void SelectFood(int idx,int cnt) {
    if (cnt >= 1) {
        if(isMinNutrient()){
            int totalPrice = TotalPrice();
            if (minCost > totalPrice) {
                minCost = totalPrice;
                resultFood.clear();
                resultFood = selectFoodNum;
            }
            return;//이미 조건을 만족하므로 더 추가할 이유가 없다.
        }
    }
    if (cnt == n) return;

    //다음 음식
    for (int i = idx; i < n; i++) {
        selectFoodNum.push_back(i);
        SelectFood(i + 1, cnt + 1);
        selectFoodNum.pop_back();
    }
}
//출력
void Output() {
    if (minCost == inf) cout << -1;
    else {
        cout << minCost << "\n";
        for (int i : resultFood) cout << i + 1 << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SelectFood(0, 0);//음식 선택
    Output();//출력
    return 0;
}
