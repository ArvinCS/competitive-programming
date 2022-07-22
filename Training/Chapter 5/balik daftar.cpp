#include <iostream>

using namespace std;

int main(){
	int size = 0;
	int bilangan[104];
	
	while(cin >> bilangan[size]) size++;
	
	for(int x=size;x>0;x--) cout << bilangan[x-1] << "\n";
	
	return 0;
}
