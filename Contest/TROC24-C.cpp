#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int ans = 0;
	int one = 0, zero = 0;
	
	int suffix[n+1], prefix[n];
	fill(suffix, suffix+n+1, 0);
	fill(prefix, prefix+n, 0);
	
	for(int x=0;x<n;x++){
		if(s[x] == '1'){
			one++;
		} else {
			ans += one;
			suffix[x] = one;
			zero++;
		}
	}
	one = 0; zero = 0;
	for(int x=n-1;x>=0;x--){
		if(s[x] == '1'){
			prefix[x] = zero;
			one++;
		} else {
			zero++;
		}
	}
	
	suffix[n] = 0;
	for(int x=1;x<n;x++){
		prefix[x] += prefix[x-1];
	}
	for(int x=n-2;x>=0;x--){
		suffix[x] += suffix[x+1];	
	}
	
	int best = ans;
	{
		int cnt = 0;
		for(int x=n-1;x>=0;x--){
			if(s[x] == '0'){
				cnt++;
			}
			
			if(x == 0 || cnt == k){
				best = min(best, ans-suffix[x]);
				break;
			}
		}
	}
	
	int cnt = 0;
	for(int l=0;l<n;l++){
		if(s[l] == '1'){
			cnt++;
		}
		
		if(l == n-1 || cnt == k){
			best = min(best, ans-prefix[l]);
			break;
		}
		
		int cnt2 = 0;
		for(int r=n-1;r>l;r--){
			if(s[r] == '0'){
				cnt2++;
			}
			
			if(r == l+1 || cnt+cnt2 == k){
				best = min(best, ans-prefix[l]-suffix[r]+cnt*cnt2);
				break;
			}
		}
	}
	
	cout << best << "\n";
	return 0;
}
