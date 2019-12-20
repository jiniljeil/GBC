#include<iostream>
using namespace std;
int main(void){
	int people;
	int count[10001] = { 0 };
	
	cin >> people ;
	
	count[2] = 1;
	if(people == 2){
		cout << count[2] <<endl;
	}
	count[4] = 2;
	if(people == 4){
		cout << count[4] << endl;
	}
	for(int i =6; i<= people; i+=2){
		count[i]= 2+ people/2 * (people/2 -2);
		if( i == people){
			cout << count[i] << endl;
			break;
		}
	}
	
	
	return 0;
}
