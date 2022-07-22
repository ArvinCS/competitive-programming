#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}	
	
	ll prefix[n];
	prefix[0] = p[0].second;
	
	for(int x=1;x<n;x++){
		if(p[x].first == 1){
			prefix[x] = p[x].second;
		} else {
			prefix[x] = prefix[x-1] + p[x].second;
		}
	}
	
	ll ans = prefix[n-1];
	
	ll sum = 0;
	ordered_set st;
	for(int x=n-1;x>=0;x--){
		if(k < 0) break;
		if(p[x].first == 1){
			ans = max(ans, prefix[x]+sum);
			
			k--;
			if(st.size() > k){
				auto it = st.find_by_order(st.size()-k-1);
				sum += *it;
			}
		} else {
			ans = max(ans, prefix[x]+sum);
			if(p[x].second < 0){
				if(st.size() >= k){
					auto it = st.find_by_order(st.size()-k);
					
					if(p[x].second <= *it){
						sum += p[x].second;
					} else {
						sum += *it;
					}
				}
				
				st.insert(p[x].second);
			} else {
				sum += p[x].second;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

