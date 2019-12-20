#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int parseCmd(char *cmd,char *argList[]);
int main(int argc, char *argv[])
{
    char command[256];
    char *argList[256];
    int argCount = 0;
    int i =0;

    while(1){
        printf("Input a command: ");
       fgets(command,256,stdin);
        argCount = parseCmd(command,argList);

        printf("%d arguments.\n",argCount);
        for(i=0; argList[i] != NULL; i++){
            printf("\n argList[%d] = %s\n",i,argList[i]);
        }
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
