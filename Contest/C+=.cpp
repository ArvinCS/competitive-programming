#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		long long a,b,n, cnt = 0;
		cin >> a >> b >> n;
		
		while(max(a,b) <= n){
			if(a > b) b += a;
			else a += b;
			cnt++;	
		}
		
		cout << cnt << "\n";
	}
	
    return 0;
}
