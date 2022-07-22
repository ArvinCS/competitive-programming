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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		ordered_set st[2][3];
		
		st[0][0].insert(0);
		
		bool neg = false;
		ll ans = 0, sum = 0, cnt = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '+'){
				sum++;
				neg = false;
			} else {
				sum--;
				if(neg){
					cnt++;
				}
				
				neg ^= 1;
			}
			
			ll prv = ans;
			ll par = abs(sum) % 3;
			if(sum >= 0){
				ll sz = st[0][par].size();
				ans += sz-st[0][par].order_of_key(sum);
				
				sz = st[1][(3-par)%3].size();
				ans += sz-st[1][(3-par)%3].order_of_key(sum);
			} else {
				ll sz = st[0][(3-par)%3].size();
				ans += sz-st[0][(3-par)%3].order_of_key(sum);
				
				sz = st[1][par].size();
				ans += sz-st[1][par].order_of_key(sum);
			}
			
			st[(sum < 0)][par].insert(sum);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

