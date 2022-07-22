#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string tmp;
	short list[n];
	for(int x=0;x<n;x++){
		cin >> tmp;
		if(tmp == "JUJUR"){
			list[x] = 1;
		} else {
			list[x] = 0;
		}
	}
	
	for(int x=n-1;x>=1;x--){
		if(list[x] == 0){
			list[x-1] = abs(list[x-1] - 1);
		}
	}
	
	if(list[0] == 0){
		cout << "BOHONG\n";
	} else {
		cout << "JUJUR\n";
	}
    return 0;
}
