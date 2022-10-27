#include <string>
#include <vector>
#include <queue>
using namespace std;
const int maxi = 26;
const int inf = 500000000;
int n;//board크기
int cost[maxi][maxi][4];//(i,j), k방향일때의 최소 비용
queue<pair<pair<int,int>,int>> q;//위치, 방향
//동남서북
int dx[4]=  {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//초기화
void init(int n,vector<vector<int>> board){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++) cost[i][j][k] = inf;
        }
    }
    //초기값
    for(int k=0;k<4;k++){
        cost[0][0][k] = 0;
        q.push({{0,0},k});
    }
}
//길찾기
int road(int n,vector<vector<int>> board){
    int total = inf;
    while(!q.empty()){
        int x = q.front().first.first;//현재 위치
        int y = q.front().first.second;
        int dir = q.front().second;//현재 방향
        q.pop();
        
        //도착
        if(x==n-1 && y==n-1){
            for(int k=0;k<4;k++){
                if(total>cost[x][y][k]) total = cost[x][y][k];
            }
        }
        //다음 지점
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            
            //범위조건, 방문조건
            if(nx<0 || nx>=n ||ny<0 ||ny>=n)continue;
            if(board[nx][ny]==1) continue;
            
            //직선
            if((dir+k)%2==0){
                //더 작은 값이 오면
                if(cost[nx][ny][k]>cost[x][y][dir]+100){
                    cost[nx][ny][k] = cost[x][y][dir]+100;
                    q.push({{nx,ny},k});
                }
            }
            //커브
            if((dir+k)%2==1){
                //더 작은 값이 오면
                if(cost[nx][ny][k]>cost[x][y][dir]+600){
                    cost[nx][ny][k] = cost[x][y][dir]+600;
                    q.push({{nx,ny},k});
                }
            }
        }
    }
    return total;
}
int solution(vector<vector<int>> board) {
    n = board.size();//보드 크기
    init(n,board);//초기화
    int answer = road(n,board);//길찾기
    return answer;
}
