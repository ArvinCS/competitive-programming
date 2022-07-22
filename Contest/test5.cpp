#include <iostream>

using namespace std;

int counter = 0;
int f(int n){
	int result = 0;
	counter++;
	if(n >= 0){
		result += 2*f(n-1);
		for(int x=0;x<=n-1;x++) result++;
		result += f(n-2);
	}
	return result;
}
int main(){
	cout << f(8);
}
