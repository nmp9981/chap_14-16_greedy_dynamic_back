#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
const int maxi = 301;
vector<pair<int,int>> lecture;//강의

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        lecture.push_back({ s,t });
    }
    sort(lecture.begin(),lecture.end());//오름차순 정렬
}

//교실 배정
void ClassRoom() {
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙, 종료시간
    pq.push(lecture[0].second);

    for (int i = 1; i < n; i++) {
        int startTime = lecture[i].first;
        int endTime = lecture[i].second;

        if (startTime >= pq.top()) {//빈교실
            pq.pop();
            pq.push(endTime);
        }
        else {//교실을 늘림
            pq.push(endTime);
            cnt = max(cnt, pq.size());
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ClassRoom();//교실 배정
    return 0;
}
