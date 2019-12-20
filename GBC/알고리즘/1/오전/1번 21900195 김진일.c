#include<stdio.h>
int main(void){
// 정사각형 좌표 입력 
// 방향 입력 
// Final 좌표가 -값을 가질 경우 return -1 
// Final 좌표 출력 
int x,y ; 
int fx,fy;
int xd ,yd;
int M,n; 

int direction =1 ;
yd =-1;
int turn =0;
int i;

printf("Enter the r,m size : ");
scanf ("%d", &M);
scanf ("%d", &n);

for(i = 0; i < n; i++){
	if (direction ==1 ){ 
		printf("MOVE");
		if (turn== 0){ //LEFT
			if(xd ==1){
			scanf("%d",&y);
			fy +=y;
			direction =-direction;
			
			}else if(xd ==-1){
		    scanf("%d",&y);
			fy -= y;
			direction =-direction;
			
			}else if(yd ==1){
			scanf("%d",&x);
			fx -=x;
			direction =-direction;
			
			}else if (yd ==-1){
			scanf("%d",&x);
			fx +=x;
			direction =-direction;
			} 
		
		}else if (turn == 1){ //turn ==1 RIGHT
			if(xd ==1){
			scanf("%d",&y);
			fy -=y;
			direction =-direction;
			
			}else if(xd ==-1){
			scanf("%d",&y);
			fy += y;
			direction =-direction;
			
			}else if(yd ==1){
			scanf("%d",&x);
			fx +=x;
			direction =-direction;
			
			}else if(yd ==-1){
			scanf("%d",&x);
			fx -=x;
			direction =-direction;
			}
			}
	     direction = -direction;

	}else  { //방향 오른쪽 0 일때  
		printf("TURN");
		scanf("%d", turn); 
		if (turn ==0){
			if(xd ==-1){
			  yd = 1;
		    }else if (xd ==-1){
		      yd = -1;
			}else if (yd ==1){
				xd =-1;
			}else if (yd == -1){
				xd = 1;//위로 증가 
			}
			
		}
		else{
			if(xd ==-1){ // y 증가하고 있던 중 
			  yd = -1;
		    }else if (xd ==-1){
		      yd = 1;
			}else if (yd ==1){
				 xd =1;
			}else if (yd == -1){
				 xd =-1;//아래로 증가 
			}
		}
		direction -=direction;
	
}


if (fx<0 || fy <0  || fx>M ||fy>M) {
	return -1;
} else {
	printf("%d %d", fx, fy); // 최종 좌표 출력 
}


return 0;
}
}

