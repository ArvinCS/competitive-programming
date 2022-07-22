#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	for(int x=0;x<n;x++){
		pq.push({a[x], x});
	}
	
	ordered_set st;
	
	int pos = 0;
	ll ans = 0;
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		int cnt = st.order_of_key(p.second+p.first);
		int left = cnt, right = st.size()-1, pos = -1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if((*st.find_by_order(mid))-(p.second+p.first) == mid-cnt){
				pos = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		if(pos == -1){
			st.insert(p.second+p.first);
			ans = max(ans, p.second+p.first+2);
		} else {
			ll val = *st.find_by_order(pos);
			
			st.insert(val+1);
			ans = max(ans, val+1+2);
		}
	}
	
	cout << ans << "\n";
    return 0;
}
