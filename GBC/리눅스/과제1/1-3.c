#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int parseCmd(char *cmd,char *argList[]);
void execCmd(char *argList[], int bg);
int main(int argc, char *argv[])
{
    char command[256];
    char *argList[256];
    int argCount = 0;
    int i =0;

    while(1){
        printf("myshell >");
       fgets(command,256,stdin);
        argCount = parseCmd(command,argList);

	if(strcmp(argList[0],"exit")==0)//사용자가 exit를 입력하면 종료됨 
		{
			break;
		}
        printf("%d arguments.\n",argCount);
        for(i=0; argList[i] != NULL; i++){
            printf("\n argList[%d] = %s\n",i,argList[i]);
        }
	printf("Goodbye!\n");
        return 0;
    }
}
int parseCmd(char *cmd,char *argList[])//문자열을 입력받아서 띄어쓰기에 따라서 나누는 함수
{
	int i=0;
	int j=0;
	int count=0;
	argList[i++]=&cmd[j];
	while(cmd[j] != '\0')//문자열이 끝날때 까지 반복한다
	{
		if(cmd[j]==' ')//만약 스페이스를 만나면 
		{
			cmd[j] = '\0';//문자열의 끝으로 만들고
			argList[i++]=&cmd[++j];//다음 문자를 시작으로 넣는다 
			count++;
		}
		else//만약 스페이스를 만나지 않으면 다음으로 넘어간다 
		{
			j++;
		}
	}
	 argList[i]=NULL;
	 count++;
	 
	 return count;
}
void execCmd(char *argList[], int bg)//명령어를 실행하는 함수   (명령어들, back ground 프로세서의 상태를 나타낸다 0이면 child가 끝날때 까지 wait를 해야한다 )
{
	pid_t state=0;
	state=fork(); //실패 -1, 부모: 자식 state, 자식: 0 
	int error=0;
	
	if(state==-1)//만들기 실패시 
	{
		printf("프로세서 생성에 실패했습니다\n");
		return ;
	}else if(state==0)//만약 자식이면 프로그램을 바꾼다 
	{
		error=execvp(argList[0],argList);
		if(error== -1)//프로그램을 바꾸는데 실패했으면 
		{
			printf("Invalid command!\n");
			return ;
		}
	}else//만약 부모면 기다린다, but bg=1이면 기다리지 않고 back ground프로그램으로 실행한다 
	{
		if(bg==1)
			return;
		
		state=wait(NULL);//반환형 pid_t타입형 변수, 성공시 자식 프로레서 id 실패시 -1 리턴, parameter값은 자식프로세서 종료시 return 값이 저장됨 
		if(state != -1)//자식이 비정상적으로 종료 되었으면
		{
			printf("프로그램이 비정상적으로 종료되었습니다.\n");
			exit(0);
		}
		else//자식이 정상적으로 종료 되었으면
			return;
	} 
	
}

