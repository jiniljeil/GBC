/*
1 // 구멍의 넓이 x (단위 : 센티미터)
4 // 레고 조각의 수 n(0~1000000)
9999998 // 레고 조각의 길이 (<= 100000000 나노미터) = 10 센티미터
1
2 
9999999
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> section ;
int bs (int N );
int x, n , len ;
int k;

int main(void){

while(1){
	
	if(scanf("%d ", &x ) != 1){
		break;
	}
	cin >> n ; // 입력  
	
	if(n == 0){
		cout << "danger" << endl; // 막지 못하는 경우  	
	}
	for(int i = 0 ; i< n ; i++){
	    cin >> len ;
	    section.push_back(len); // 배열에 길이 값 할당  
	}	
	
	x *= 10000000; // 단위가 나노 미터이므로 cm 단위로 바꿔주기  
    sort ( section.begin(), section.end() );// 벡터배열 정렬  
	
    for(int i= 0; i< section.size() ; i++){
        k = bs (x-section[i]);
        
    if (k != -1 ){ // 조각으로 막을 수 있는 경우  
   	
    printf("yes %d %d\n", section[i], section[k]); // 최댓값 출력  
	break; 
    }else{
    	cout << "danger" << endl; // 막지 못하는 경우  
    	break;
	}
	}
	section.clear();
}

    return 0;
}

int bs (int N ){
    int mid, L , R ;
    
   	L = 1;
   	R = section.size()-1;
    
	while (L <= R){
    mid = (L + R)/2;
    if(section[mid]== N){
        return mid;
    }else if (section[mid] > N){
        R = mid -1 ;
    }else{
        L = mid +1 ;
    }
    }
   
    return -1;
}
