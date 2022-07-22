#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	
	while(t--){
		unsigned long long n, r;
		cin >> n >> r;
		
		if(n == 1){
			cout << "1\n";
		} else {
			unsigned long long high = n > r ? r : n-1;
			cout << (n > r ? 0 : 1) + (high * (high+1) / 2)<< "\n";
		}
	}
	
    return 0;
}
