#include <iostream>

using namespace std;

void reverseNum(int num, int base){
	static int base_pos = 1;
	if(num > 0){
		reverseNum(num/10, base);
		cout << (num%10)*base_pos; 
    	base_pos *= 10; 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n;
	cin >> n;
	
	int data[n];
	for(short x=0;x<n;x++){
		cin >> data[x];
	}
	
	for(short x=0;x<n;x++){
		cout << reverseNum(data[x]) << "\n";
	}
    return 0;
}
