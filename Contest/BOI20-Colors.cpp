#include <bits/stdc++.h>

using namespace std;

#define ll long long

set<ll> st;
ll pos = 0, ans = 1e18;

bool ask(ll n){
	cout << "? " << n << endl;
	st.insert(n);
	
	int res;
	cin >> res;
	
	if(res){
		if(pos != 0) ans = min(ans, abs(n-pos));
	}
	pos = n;
	return (res == 1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ans = n;
	if(n <= 64){
		ll l = 1, r = n+1;
		ask(1);
		for(int x=1;x<n;x++){
			if(x&1){
				r--;
				if(ask(r)){
					ans = min(ans, r-l);
				}
			} else {
				l++;
				if(ask(l)){
					ans = min(ans, r-l);
				}
			}
		}
		
		cout << "= " << ans << endl;
		return 0;
	}
	
	ll left = 1, right = 1+(n/2-4)/3;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll pL = (n%2 == 0 ? n/2-1-(mid-1)*3 : (n+1)/2-(mid-1)*3-2);
		ll pR = (n%2 == 0 ? n/2+2+(mid-1)*3 : (n+1)/2+(mid-1)*3+2);
		
		ask(pL);
		if(ask(pR)){
			ans = min(ans, pR-pL);
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	ll pos = -1, extra = -1;
	ll prv = ans;
	for(int i=5;i>=0;i--){
		bool found = false;
		for(ll x=n/2;x>=1;x--){
			if(prv-i <= 0) break;
			if(!st.count(x) && !st.count(x+prv-i) && x+prv-i <= n){
				pos = x;
				extra = i;
				found = true;
				break;
			}
		}
		if(found) break;
	}
	
	auto exist = [&](ll p){
		if(p <= 0 || p > n) return false;
		return !st.count(p);
	};
	
	ask(pos);
	
	for(int i=extra;i>=1;i--){
		bool change = false;
		while(!exist(pos+((prv-i)*(i%2 == extra%2 ? 1 : -1)))){
			pos += -1*(i%2 == extra%2 ? 1 : -1);
			change = true;
		}
		
		cout << i << endl;
		if(change) ask(pos);
		if(ask(pos+((prv-i)*(i%2 == extra%2 ? 1 : -1)))) break;
		pos += ((prv-i)*(i%2 == extra%2 ? 1 : -1));
	}
	cout << "= " << ans << endl;
    return 0;
}

