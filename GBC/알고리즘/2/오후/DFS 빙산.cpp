#include<iostream>
using namespace std;

	int n , k;
	int rc[301][301] = { 0 } ; // 행열 row column
	bool v[301][301]; // true false
	int dir[4][2] = { (1,0), (-1,0) ,(0,1) ,(0,-1) } ;// 방향 X , Y
	void melt(void);
	void DFS(int x,int y);
	int year =0;
	int cut = 0; // 감소  
	bool result =false;	
int main(void){
	
	cin >> n >> k; // 행 크기, 열 크기 

	for (int i=0;i<n; i++){
		for(int j=0;j<k;j++){
			cin >> rc[i][j]; // 넣는 값 0이상 10 이하 
		}
	}  // 행렬 생성 
while(1){
	
	for(int i =0; i<n; i++){
		for(int j=0; j<k; j++){
			v[i][j]= false; // 방문 초기화 
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(v[i][j]==false && rc[i][j] != 0){ // 방문하지 않은 곳 
				if( cut == 2 ){
					result = true; 
					break;
				}
				cut ++; // 정수 크기 -1 
				DFS(i,j); // DFS
			}
		}
	}
	if(result){
		break;
	}
	
	melt (); // melt 함수 
	year ++; // while 문을 한번 돌 때마다 1년 씩 증가 
}
cout << year << endl; // 출력 
return 0 ; 
}

void DFS(int x,int y){
	v[x][y] =true;
	for(int i = 0; i<4; i++){
		int X = x + dir[i][0]; // X == next x 
		int Y = y + dir[i][1]; // Y == next Y
		
		if( X > 0  && X < n && Y > 0 && Y < k){ // 행렬 안에 범위 
			if(rc[X][Y] && !v[X][Y]){	 // 방문하지 않았던 곳이 있다면 계속해서 방문 
				DFS(X,Y);
			}
		}
	}
}	
void melt(void){
	int x , y;
	int c[301][301];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			c[i][j]=rc[i][j]; // 복사 
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
		if(c[i][j]){
			for(i = 0; i< 4 ; i++){
				int X = x + dir[i][0]; // X == next x
				int Y = y + dir[i][1]; // Y == next Y
			int cut; 
			if(c[X][Y] == 0){
				cut ++;
			}
			}					
			rc[i][j]= c[i][j]- cut ; // 복사 값 - cut 값 = 변화된 빙판
			if(rc[i][j]<0){
			rc[i][j] = 0;
			}  				
		}		
		}
	}	
}
	
	
