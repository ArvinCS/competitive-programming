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

const int maxM = 1e5 + 5;

int n, m;
int arr[8], mnW[maxM];
pair<ll, int> part[maxM];

ll solve(int i, int idx[]){
	if(i >= n-1){
		int prefix[n];
		prefix[0] = arr[idx[0]];
		for(int x=1;x<n;x++){
			prefix[x] = arr[idx[x]] + prefix[x-1];
		}
		
		vector<ll> v;
		ll dist = 0;
		
		v.push_back(0);
		for(int x=1;x<n;x++){
			ll left = 0, right = 1e8, ans = -1;
			while(left <= right){
				ll mid = (left+right) >> 1;
				
				bool valid = true;
				
				ll sum = 0;
				for(int y=x-1;y>=0;y--){
					if(y == x-1) sum += mid;
					else sum += v[y+1];
					
					auto it = lower_bound(part, part+m, make_pair(sum+1, -1));
					
					int idx = (it - part);
					if(idx >= m){
						continue;
					}
					
					if(mnW[idx] < (prefix[x] - (y > 0 ? prefix[y-1] : 0))){
						valid = false;
						break;
					}
				}
				
				if(valid){
					ans = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
	 		}
			
			if(ans == -1){
				return inf_ll;
			}
			
			dist += ans;
			v.push_back(ans);
		}
		
		return dist;
	}
	
	ll ans = inf_ll;
	for(int x=i;x<n;x++){
		swap(idx[i], idx[x]);
		ans = min(ans, solve(i+1, idx));
		swap(idx[i], idx[x]);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> arr[x];
	}
		
	int prefix[n];
	prefix[0] = arr[0];
	for(int x=1;x<n;x++){
		prefix[x] = arr[x] + prefix[x-1];
	}
	
	int mn = inf_int;
	for(int x=0;x<m;x++){
		cin >> part[x].first >> part[x].second;
		mn = min(mn, part[x].second);
	}
	
	for(int x=0;x<n;x++){
		if(arr[x] > mn){
			cout << "-1\n";
			return 0;
		}
	}
	
	sort(part, part+m);
	
	mnW[m-1] = part[m-1].second;
	for(int x=m-2;x>=0;x--){
		mnW[x] = min(part[x].second, mnW[x+1]);	
	}
	
	int idx[8];
	for(int x=0;x<8;x++) idx[x] = x;
	
	ll ans = solve(0, idx);
	
	cout << (ans == inf_ll ? -1 : ans) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

