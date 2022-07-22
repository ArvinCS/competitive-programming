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
		ll b, c, d;
		cin >> n >> b >> c >> d;
		
		ll ans = 0, cur = 0;
		for(int x=0;x<n;x++){
			if(cur+c <= b){
				cur += c;
				ans += cur;
			} else {
				cur -= d;
				ans += cur;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

