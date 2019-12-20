#include<iostream>
using namespace std;

	int i , j;
	int n , k;
	int time;
	int rc[301][301] = { 0 } ; // 행열 row column
	bool v[301][301]; // true false
	int dir[4] = { (1,0), (0, 1) ,(-1,0) ,(0,-1) } ;// 방향 
	void melt(void);
	void DFS(int x,int y);
	int year =0;
	int cut = 0; // 감소  
		
int main(void){
	

	cin >> n >> k; // 행 크기, 열 크기 

	for (i=0;i<n; i++){
		for(j=0;j<k;j++){
			cin >> rc[n][j]; // 넣는 값 0이상 10 이하 
		}
	}  // 행렬 생성 
while(1){
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			if(v[i][j]==false && rc[i][j]){ // 방문하지 않은 곳 
				cut ++; // 정수 크기 -1 
				DFS(i,j); // DFS
			}
		}
	}
	melt (); // melt 함수 
 
	year ++; // while 문을 한번 돌 때마다 1년 씩 증가 
}
cout << year << endl; // 출력 
return 0 ; 
}

void DFS(int x,int y){
	v[x][y] =true;
	
	for(i = 0; i<4; i++){
		int X = x + dir[i]; // X == next x 
		int Y = y + dir[i]; // Y == next Y
		
		if( X > 0  && X < n && Y > 0 && Y < k){ // 행렬 안에 범위 
			if(rc[X][Y] && !v[X][Y]){ // 방문하지 않았던 곳이 있다면 계속해서 방문 
				DFS(X,Y);
			}
		}
	}
}
void melt(void){
	int x , y;
	int c[301][301];
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			c[i][j]=rc[i][j]; // 복사 
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
		if(c[i][j]){
			for(i = 0; i< 4 ; i++){
			int X = x + dir[i]; // X == next x
			int Y = y + dir[i]; // Y == next Y
			
			if(X == 0 && Y== 0){
				cut ++;
			}
			}
			int cut; 
			if(rc[i][j]>= 0){
			rc[i][j]= c[i][j]- cut ; // 복사 값 - cut 값 = 변화된 빙판 
			}	
		}
		
		}
	}
	
}
	
	
