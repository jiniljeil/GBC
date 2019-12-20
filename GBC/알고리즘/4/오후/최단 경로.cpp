/* 
7 9 // ��� ���� , ���� ���� 
0 6 // ����� , ������
0 1 1 // 0���� 1�� ���� ������ ���� : 1
0 2 1 // 0���� 2�� ���� ������ ���� : 1
0 3 2
0 4 3
1 5 2
2 6 4
3 6 2
4 6 4
5 6 1*/ 
#include<iostream>
#include<vector>
using namespace std;

 // �ִ� ����

#define INF 100000000   // ���Ѵ� (������ ���� ���)


int place, route; // ��ҿ� ���� ���� �Է¹ޱ� ����.
int first , end ;
int routelen;
int visit[10001];
vector<int> p[501];
int lenstore[501];

void DFS ( int s );
int choose(int lenstore[], int n, int visit[]);
int shortest_path(int start, int n, int place);

int main(void){ //�ʿ��� ���� = ���, ���� , �����, ������, ������ ����
    
    cin >> place >> route;  // ��ҿ� ���� ���� �Է�
    cin >> first >> end ;   // ������� ������ ����

    for(int i =0; i< route ; i++){
        int v1 ,v2;
        cin ;v1 >> v2 >> routelen; // ��� �Է� 
        p[v1].push_back(v2); // ���� ���� ���� 
        
    }
    DFS(first);
    int x =shortest_path(first,route, place);
    cout << x << endl;
    
    return 0;
}

void DFS ( int s ){
    visit[s] = true ; // �湮 
    for(int i = 0; i< p[s].size(); i++){
        int x = p[s][i];
        if(visit[x] == false){
            DFS( x ); 
        }
        }
    }

int shortest_path(int start, int n, int place)
// start �������� n ���������� �ִ� ��θ� ã�� �˰�����
{
  int i, u, w;
  int lenstore[place];	
  int weight[place][place];
  
  for (i = 0; i < n; i++)
  {
    lenstore[i] = weight[start][i]; // �ʱ�ȭ 
 
    visit[i] = FALSE;
  }
  
  visit[start] = true; // �湮 == TRUE 
  lenstore[start]= true;
  for (i = 0; i< n-1; i++) // ���� ����  n-1 
  {
    u = choose(lenstore, n, visit);	// �ּҰ��� �ִ� �ε����� ������ u�� �����Ѵ�.
								
    visit[u] = true;
 
    for (w = 0; w < n; w++)
    {
      if (visit[w] ==false)
      {
        // ���� �� ���������� �Ÿ� (distance[u]) + ���� w������ �Ÿ���
        // ������ w���������� �Ÿ����� �����ٸ� �� ������ �������ش�.
        if (lenstore[u] + weight[u][w] < lenstore[w])
        {
          lenstore[w] = lenstore[u] + weight[u][w];
        }
      }
    }
  }
}
int choose(int lenstore[], int n, int visit[])
{
  // ���� distance �迭���� ���� ���� ����ġ ���� ��ġ�ϰ� �ִ�
  // �迭�� �ε����� ã�� ��ȯ�ϴ� �Լ�
 
  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;
 
  for (i = 0; i < n; i++)
  {
   
    if (lenstore[i] < min && visit[i] == false)
    {
      min = lenstore[i];
      minpos = i;
    }
  }
//�ּҰ��� ��ġ�ϰ� �ִ� �ε����� ��ȯ
  return minpos;
}



