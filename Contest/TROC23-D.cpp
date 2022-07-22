#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	ll k;
	cin >> k;
	
	vector<tuple<int, int, int>> v;
	int node = 1;
	while(k > 0){
		ll left = 4, right = 5e4, ans = -1;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll ways = mid*(mid-1)*(mid-2)*(mid-3)/6;
//			cout << k << " " << mid << " " << ways << " " << mn << " " << val << "\n";
			if(ways <= k){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		if(ans == -1){
			break;
		}
		
		ll ways = ans*(ans-1)*(ans-2)*(ans-3)/6;

		for(int x=1;x<=ans;x++){
			v.push_back(make_tuple(node+x-1, node, node+ans-1));
		}
		
		node += ans;
		k -= ways;
	}
	
	while(k > 0){
		ll left = 3, right = 1e4, ans = -1;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll val = mid*(mid-1)*(mid-2)/6;
			if(val <= k){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		if(ans == -1){
			break;
		}
		
		v.push_back(make_tuple(node, node+1, node+ans));

		node += ans+1;
		k -= ans*(ans-1)*(ans-2)/6;
	}
	
//	cout << k << "\n";
	cout << v.size() << "\n";
	for(auto t : v){
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
	}
    return 0;
}

