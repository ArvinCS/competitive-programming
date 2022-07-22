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
		
		string s;
		cin >> s;
		
		map<int, int> mp;
		ll ans = 0;
		for(int x=0;x<n;x++){
			ll sum = 0, cnt = 0;
			bool neg = false;
			for(int y=x;y<n;y++){
				if(s[y] == '+'){
					sum++;
					neg = false;
				} else {
					if(neg){
						cnt++;
					}
					
					neg ^= 1;
					sum--;
				}
				
				if(sum == 0 || (sum < 0 && sum % 3 == 0 && sum <= cnt*3)){
					mp[y]++;
					ans++;
				}
			}
		}
		
		for(auto p : mp){
			cout << p.first << " -> " << p.second << "\n";
		}
		cout << ans << "\n";
	}
	
    return 0;
}

