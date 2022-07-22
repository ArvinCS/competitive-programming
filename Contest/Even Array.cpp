#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	short n;
	while(t--){
		cin >> n;
		
		short data[n];
		for(short x=0;x<n;x++){
			cin >> data[x];
		}
		
		int odd = 0, even = 0;
		for(short x=0;x<n;x++){
			if(data[x] % 2 != (x % 2)){
				if(x%2 == 0) even++;
				else odd++;
			}
		}
		
		if(even == odd){
			cout << even << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
    return 0;
}
