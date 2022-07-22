#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string subsoal;
	cin >> subsoal;
	
	string s;
	cin >> s;
	
	ll k;
	int q;
	cin >> k >> q;
	
	ll n = s.length()*k;
	ll a = 0, b = 0;
	for(int x=0;x<s.length();x++){
		if(s[x] == 'A'){
			b++;
		} else {
			a++;
		}
	}
	
	pair<ll, ll> prefix[s.length()+1];
	prefix[0] = {0, 0};
	for(int x=1;x<=s.length();x++){
		prefix[x] = prefix[x-1];
		
		if(s[x-1] == 'A'){
			prefix[x].second++;
		} else {
			prefix[x].first++;
		}
	}
	
	while(q--){
		ll l, r;
		cin >> l >> r;
		
		l--; r--;
		
		ll left = 0, right = k, bound = 0, bound2 = 0;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll curL = a*mid, curR = n-b*mid;
			if(min(curR, r)-max(curL, l)+1 >= 1){
				bound = max(bound, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		left = 0, right = s.length();
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll curL = a*bound + prefix[mid].first, curR = n-b*bound-prefix[mid].second;
			
			if(min(curR, r)-max(curL, l)+1 >= 1){
				bound2 = max(bound2, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		cout << bound*s.length() + bound2 + 1 << "\n";
	}
	
    return 0;
}

