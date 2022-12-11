#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 201;
ll board[maxi][maxi];//보드판
ll root[maxi][maxi];//경로의 수

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}
}
//점프
void Jump() {
	root[0][0] = 1;//초기값
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;//0은 제외
			//아래
			if(i + board[i][j]<n) root[i + board[i][j]][j] = root[i][j]+ root[i + board[i][j]][j];
			//오른쪽
			if(j + board[i][j]<n) root[i][j + board[i][j]] = root[i][j]+ root[i][j + board[i][j]];
		}
	}
	cout << root[n - 1][n - 1];
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	Jump();//점프
	return 0;
}
