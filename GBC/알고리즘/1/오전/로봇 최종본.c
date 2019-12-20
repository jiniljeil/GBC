#include<stdio.h>
int main(void){
int TURN ; // 0 or 1 
int MOVE ; // 0<= MOVE <=1000
int M, n ,i;
int dir;
int x, y, dx=1 , dy=0 ;
scanf("%d",&M);
scanf("%d",&n);
for(i=0; i<n;i++){
	if(dir==1){
	printf("MOVE");
	scanf(" %d", &MOVE );
    
	x += MOVE *dx;
	y += MOVE *dy;
	dir =0;		
	}else if(dir ==0){
		printf("TURN");
		scanf(" %d",&TURN);
		if(TURN==0){
			if(dx ==1){
				dy =1;
				dx =0;
			}
			else if(dx ==-1){
				dy =-1;
				dx =0;
			}
			else if(dy ==1){
				dx =-1;
				dy =0;
			}
			else if(dy =-1){
				dx =1;
				dy =0;
			}
		}else{
			if(dx ==1){
				dy =-1;
				dx =0;
			}
			else if(dx ==-1){
				dy =1;
				dx =0;
			}
			else if(dy ==1){
				dx =1;
				dy =0;
			}
			else if(dy =-1){
				dx =-1;
				dy =0;
			}
		}
		dir =1;
	}
}

if (x>0 && x < M && y >0 && y < M) {
	printf("%d %d", x, y); // 최종 좌표 출력
}else{
    printf("-1");
}
return 0;
}

