#include<iostream>
#include<algorithm>
using namespace std;

int main(void){ 
	int H[200001];
	int N, C;
	
    cin >> N >> C; // 집 개수 , 공유기 개수  
	if( C >= 2 && C <= N && N >=2){                      // 2 <= N,   2<=C<=N
		for (int i=0; i < N; i++ ){
		cin >> H[i]; // 집 좌표 입력  
	}
    
	sort ( H , H + N );  // 정렬  
	
	int L=1, cir =1; // 최소 거리   
	int R = H[N-1] - H[0]; //  최대거리   
	int output;
		
	while(L<=R){
	int cir =1; //1번에 공유기 설치했으므로 1 추가  
		int mid = (L+R)/2;
		int first = H[0]; // 초기 좌표 
		for(int i=1; i<N; i++){		 
			if(H[i]-H[0]>=mid){ // 현재 좌표 - 이전 좌표로  간격 확인 
				cir ++;  
				first = H[i]; // 공유기를 설치후 집 좌표 찍기 
			}		
		}
		if (cir <= C){ // 입력한 공유기 개수를 만족할 때까지 실행 
		R = mid -1; //왼쪽 파트에서 찾기		
		}else{
		L = mid +1; // 오른쪽파트에서 찾기 
		output = mid;	 
		}
	}
	cout << output << endl;
	} 
	
 	return 0;
}
	
