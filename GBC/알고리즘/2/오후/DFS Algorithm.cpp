#include<iostream>
#include<vector>
using namespace std;

int num;
int connect, i,j ,sum= 0; 
int visit[101]= { 0 };
vector<int> cp[101];

void DFS(int s);
	
int main(void){
int v1 ,v2;	
	
cin >> num >> connect ; // 컴퓨터 숫자 , 네트워크 연결 개수 

for(i=1; i<=connect; i++){	
	cin >> v1 >> v2;
	cp[v1].push_back(v2);
	cp[v2].push_back(v1); // 네트워크 연결 
	}
	DFS(1);
	//cout << sum <<endl;
	return 0;
}

void DFS(int s){
	
	if(visit[s]){
		return; // 방문한 경우 리턴 
	}
	visit[s]= true; // 방문 
	cout << s << endl;
	for(i =1; i<=cp[s].size(); i++){
	 int x =cp[s][i];
		DFS(x);
		if(s!=1){
	     sum ++;
		}
	}	
}

