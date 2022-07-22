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

const int maxN = 2e5 + 5;

pair<ll, ll> data[maxN];
ll prefix[maxN], suffix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			cin >> data[x].first >> data[x].second;
		}
		
		sort(data, data+n);
		
		ll left = inf_ll, right = 0;
		vector<pair<ll, ll>> start, end;
		for(int x=0;x<n;x++){
			start.push_back({data[x].first, x});
			end.push_back({data[x].second, x});
			left = min(left, data[x].first);
			right = max(right, data[x].second);
		}
		
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		
		prefix[0] = data[end[0].second].first;
		suffix[n-1] = data[start[n-1].second].first;
		for(int x=1;x<n;x++){
			prefix[x] = data[end[x].second].first + prefix[x-1]; 
		}
		for(int x=n-2;x>=0;x--){
			suffix[x] = data[start[x].second].first + suffix[x+1];
		}
	
		ll ans = -1;
		
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			auto bef = lower_bound(end.begin(), end.end(), make_pair(mid, -1ll));
			auto af = lower_bound(start.begin(), start.end(), make_pair(mid+1, -1ll));
			
			ll leftCnt = 0, rightCnt = n-(af - start.begin());
			if(bef != end.begin()){
				leftCnt = (bef - end.begin());
			}
			ll cur = n-(leftCnt+rightCnt);
			
			if(leftCnt > n/2){
				right = mid-1;
				continue;
			}
			if(leftCnt+cur < (n+1)/2){
				left = mid+1;
				continue;
			}
			
			ll cost = 0;
			if(leftCnt > 0){
				cost += prefix[leftCnt-1];
			}
			if(rightCnt > 0){
				cost += suffix[(n-rightCnt)];
			}
			
			ll need = leftCnt;
//			cout << "bef: " << mid << " " << cost << " " << leftCnt << "," << leftCnt-1 << " " << rightCnt << "," << (n-rightCnt) << "," << suffix[n-rightCnt] << "\n";
			for(int x=0;x<n;x++){
				if(data[x].first <= mid && mid <= data[x].second){
					if(need < n/2){
						cost += data[x].first;
						need++;
					} else {
						cost += max(mid, data[x].first);
						need++;
					}
				}
			}
			
			if(cost <= m){
				left = mid+1;
				ans = max(ans, mid);
			} else {
				right = mid-1;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

