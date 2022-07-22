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
	
	string n;
	ll m;
	cin >> n >> m;
	
	ll d = 0, length = 0;
	vector<ll> num;
	
	while(n.size() > 0){
		num.push_back(n.back() - '0');
		d = max(d, num.back());
		length++;
		n.pop_back();
	}
	d++;
	
	
	ll left = d, right = m+1, last = 0;
	while(left <= right){
		ll mid = (left+right) >> 1;
		ll cur = 0;
		for(ll x=0;x<length;x++){
			ll tmp = pow(mid, x);
			if(tmp > m){
				cur = m+1;
				break;
			}
			cur += num[x] * tmp;
			if(cur > m) break;
		}
		cout << left << " " << right << " " << mid << " " << cur << "\n";
		if(cur <= m){
			left = mid+1;
		} else {
			right = mid-1;
			last = mid;
		}
	}
	cout << last << "\n";
	cout << last-d << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

