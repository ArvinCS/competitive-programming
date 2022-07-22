#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	ll ans[n+2];
	fill(ans, ans+n+2, 0);
	
	bool possible = true;
	for(int x=0;x+1<n;x++){
		ans[x+3] += max(s[x+1]-s[x]+ans[x], 0ll);
	}
	for(int x=n-1;x>=0;x--){
		ll sum = ans[x]+ans[x+1]+ans[x+2];
		
		ans[x] += s[x]-sum;
		if(ans[x] < 0){
			possible = false;
			break;
		}
	}
	
	if(possible){
		cout << "No\n";
		return 0;
	}
	
	cout << "Yes\n";
	for(int x=0;x<n+2;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}
