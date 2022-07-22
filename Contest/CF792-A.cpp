#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int cnt = 0;
		int ans = 10;
		while(n >= 10){
			ans = min(ans, n%10);
			n /= 10;
			cnt++;
		}
		
		if(cnt+1 > 2){
			ans = min(ans, n);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

