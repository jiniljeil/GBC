// 몇 잔의 포도주를 순서대로 놓을 것인가? 
// 정해진 잔의 수 만큼 값을 지정
// 지정한 값들 간에 연속으로 놓인 3잔은 마실 수 없음
// 최대로 마실 수 있는 포도주의 양 
#include<stdio.h>
int max (int a, int b, int c );
int main(void){
    int count;
    int glass[10001]= { 0 }; //1<=glass<= 10000 0으로 초기화 
    int until[10001]= { 0 }; 
    int i; 
	scanf("%d",&count); // 포도주 몇잔 놓을 것인가? 
	for(i =1; i<=count; i++){
		scanf("%d", &glass[i]);
	}
	until[1] = glass[1];
	until[2] = glass[1] + glass [2];
	for(i =3 ; i<= count ; i++){
		until[i]= max(until[i-1] , until[i-2] + glass[i] ,until[i-3]+glass[i-1]+glass[i]);		
	} // 현재 포도주를 안마심 , 현재 포도주를 마시지만 그 전 포도주를 안마심,현재와 그 전 둘다 마심 
	printf("%d", until[count]);
	return 0;
}
int max (int a, int b, int c ){
	int temp;
	int i;
	for(i =0; i<3; i++){
		for(i =0; i<2; i++){
			if (a >b){
			temp =b;
			b=a;
			a = temp;
			}	
			if (b>c){
			temp=c;
			c= b;
			b = temp;
			}
		}
	}
	return c;
}
 
