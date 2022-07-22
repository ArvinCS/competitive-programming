#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll key = 31;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	string s;
	cin >> s;
	
	ll val = 0;
	for(int x=0;x<s.length();x++){
		val *= key;
		val += (s[x] - 'a' + 1);
		val %= mod;
	}
	
	ll ans = 1e18;
	
	ll left = 1, right = 1e18;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
		pq.push(make_tuple(0, "", ""));
		
		bool found = false;
		while(!pq.empty()){
			ll cost = get<0>(pq.top());
			ll cur = get<1>(pq.top());
			ll clip = get<2>(pq.top());
			pq.pop();
			
			if(cost > mid) continue;
			if(cur == s){
				found = true;
				break;
			}
			
			for(char c='a';c<='z';c++){
				ll nw = cur;
				nw *= key;
				nw += (c - 'a' + 1);
				nw %= mod;
				
				pq.push(make_tuple(cost+a, nw, clip));
			}
			
			ll nw = cur;
			nw *= pw[clip.length()];
			pq.push(make_tuple(cost+c, cur, clip));
			for(int x=0;x<clip.length();x++){
				cur.pop_back();
			}
			
			clip = cur;
			cur.clear();
			
			pq.push(make_tuple(cost+b, cur, clip));
		}
		
		if(found){
			ans = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

