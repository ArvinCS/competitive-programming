#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	ll ans = 0;
	int pos = 0;
	for(int x=0;x<n;x++){
		if(s[pos] != s[x]){
			int cnt = x-pos;
			ans += cnt*1ll*(cnt-1)/2;
			
			pos = x;
		}
	}
	
	int cnt = n-pos;
	ans += cnt*1ll*(cnt-1)/2;
	
	cout << ans << "\n";
    return 0;
}

