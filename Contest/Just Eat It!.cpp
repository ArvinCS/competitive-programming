#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		long long cupcake[n];
		for(int x=0;x<n;x++) cin >> cupcake[x];
		
		bool ans = true;
		long long left = 0, right = 0;
		for(int x=0;x<n;x++){
			left += cupcake[x];
			right += cupcake[n-x-1];
			if(left <= 0 || right <= 0){
				ans = false;
				break;
			}
		}
		if(ans){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
    return 0;
}
