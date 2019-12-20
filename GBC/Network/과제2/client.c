#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
	
#define BUF_SIZE 100
#define NAME_SIZE 20
	
void * send_msg(void * arg); // 송신 함수 / arg 위 함수에 넘길 인자
void * recv_msg(void * arg); // 수신 함수
void error_handling(char * msg); // 에러발생시 알리는 함수
	
char name[NAME_SIZE]="[DEFAULT]"; // 이름 변수
char msg[BUF_SIZE]; // 받을 데이터 변수 
	
int main(int argc, char *argv[])
{
	int sock; // 소켓의 파일 디스크립터를 저장할 변수
	struct sockaddr_in serv_addr;  //서버 소켓의 정보를 저장할 구조체
	pthread_t snd_thread, rcv_thread; // 송신 ,수신 쓰레드 생성
	void * thread_return;
	if(argc!=4) {// 실행에 필요한 정보를 입력하지 않았을 경우 경고문
		printf("Usage : %s <IP> <port> <name>\n", argv[0]); // IP PORT NAME 순으로 다시 입력하라는 메세지 출력
		exit(1);
	 }
	
	sprintf(name, "[%s]", argv[3]);// 문자열 저장하는 곳, 문자열이 저장될 (char 배열을 가리키는) 포인터
	sock=socket(PF_INET, SOCK_STREAM, 0);//소켓 생성(IPv4 , TCP/IP 방식)
	
	memset(&serv_addr, 0, sizeof(serv_addr));// 서버소켓의 정보를 저장할 구조체를 초기화 한다.
    //서버 소켓의 정보를 저장하는 구조체의 멤버변수 값 입력 (사이)
	serv_addr.sin_family=AF_INET;// IPv4 를 사용
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);//모든 아이피의 접근을 허용. 16진수로 변경해서 저장
	serv_addr.sin_port=htons(atoi(argv[2]));//프로그램 실행시 입력된 포트번호를 10진수로 변경해서 저장
                                            //// 소켓의 주소 할당을 위해 구조체 변수를 초기화함.
	  
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)// 소켓을 이용해 서버의 정보를 지닌 구조체를 가지고 접속 요청을 한다.
		error_handling("connect() error");
	
	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock); // 송신 쓰레드 생성
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock); // 수신 쓰레드 생성
	pthread_join(snd_thread, &thread_return); //송신 쓰레드가 종료될 때까지 함수를 호출한 프로세스(또는 쓰레드)를 대기상태에 두기 위해
	pthread_join(rcv_thread, &thread_return); //수신 쓰레드가 종료될 때까지 함수를 호출한 프로세스(또는 쓰레드)를 대기상태에 두기 위해
	close(sock);   //소켓을 닫는다.
	return 0;
}
	
void * send_msg(void * arg)   // 메인 쓰레드 전송 함수 /arg : 위 함수에 넘길 인자
{
	int sock=*((int*)arg); // 소켓 생성
	char name_msg[NAME_SIZE+BUF_SIZE]; // 클라이언트 접속자 이름
	while(1) 
	{
		fgets(msg, BUF_SIZE, stdin); //입력한 데이터를 message에 넣는다.
		if(!strcmp(msg,"q\n")||!strcmp(msg,"Q\n")) //문자열 비교함수
		{
			close(sock);//소켓 종료
			exit(0);
		}
		sprintf(name_msg,"%s %s", name, msg); // 문자열을 저장하기 위해(문자열 저장하는 곳) /문자열 저장 포인터
		write(sock, name_msg, strlen(name_msg)); // 문자열 전송 
	}
	return NULL;
}
	
void * recv_msg(void * arg)   // 메인 쓰레드 수신(읽기)함수
{
	int sock=*((int*)arg); //소켓 생성
	char name_msg[NAME_SIZE+BUF_SIZE]; //클라이언트 접속자 이름
	int str_len; // 크기 변수 
	while(1)
	{
		str_len=read(sock, name_msg, NAME_SIZE+BUF_SIZE-1); //읽고 문자열 길이 확인
		if(str_len==-1) 
			return (void*)-1;
		name_msg[str_len]=0;
		fputs(name_msg, stdout); // 클라이언트 접속자 이름을 파일에 쓰는(나타내주는) 역할
	}
	return NULL;
}
	
void error_handling(char *msg)// 에러 메세지 전달
{
	fputs(msg, stderr);//fputs 메세지(문자열)를 파일에 쓰는 것 /에러 메세지 전달
	fputc('\n', stderr); // 메세지 쓰기 
	exit(1);
}