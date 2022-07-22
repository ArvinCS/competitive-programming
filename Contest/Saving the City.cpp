#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		string s;
		cin >> s;
		
		int last[s.length()+1];
		last[0] = (s[0] == '1' ? 0 : -1);
		for(int x=1;x<s.length();x++){
			if(s[x] == '1'){
				last[x] = x;
			} else {
				last[x] = last[x-1];
			}
		}
		
		ll ans = 0;
		int index = s.length()-2;
		while(index >= 0){
			if(s[index] == '0' && s[index+1] == '1'){
				if(last[index] == -1) break;
				int dist = index-last[index];
				if(dist * b < a){
					for(int i=last[index]+1;i<=index;i++){
						last[i] = i;
						s[i] = '1';
					}
					ans += dist*b;
				}
			}
			index--;
		}
		
		bool skipPay = false;
		for(int x=0;x<s.length();x++){
			if(s[x] == '1'){
				if(!skipPay) ans += a;
				skipPay = true;
			} else {
				skipPay = false;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

