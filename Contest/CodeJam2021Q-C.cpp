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

bool solve(int n, int cost, int index, vector<int> data, bool exist[10]){
	if(index == n){
		int ans = 0;
		vector<int> tmp = data;
		for(int x=0;x<n-1;x++){
			int min = x;
			for(int y=x+1;y<n;y++){
				if(data[y] < data[min]){
					min = y;
				}
			}
			reverse(data.begin()+x, data.begin()+min+1);
			ans += min-x+1;
		}
		if(cost == ans){
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << tmp[x];
			}
			cout << "\n";
			return true;
		}
		return false;
	}
	
	for(int x=1;x<=n;x++){
		if(!exist[x]){
			exist[x] = true;
			data.push_back(x);
			if(solve(n, cost, index+1, data, exist)) return true;
			data.pop_back();
			exist[x] = false;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		cout << "Case #" << i << ": ";
		int n, m;
		cin >> n >> m;
		
		if(m < n-1 || m >= n*(n+1)/2){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		pair<int, int> data[n];
		for(int x=0;x<n;x++){
			data[x] = {-1, x};
		}
		
		for(int x=0;x<n-1;x++){
			int pos = x;
			for(int y=x;y<n;y++){
				if(data[y].first != -1) continue;
				if(y-x+1 >= m-(n-2-x)){
					pos = y;
					break;
				} else {
					pos = y;
				}
			}	
			
			
			m -= pos-x+1;
			data[pos].first = x+1;
			reverse(data+x, data+pos+1);
		}
		
		if(m != 0){
			cout << "IMPOSSIBLE\n";
		} else {
			for(int x=0;x<n;x++){
				if(data[x].first == -1) data[x].first = x+1;
			}
			int ans[n];
			for(int x=0;x<n;x++){
				ans[data[x].second] = data[x].first;
			}
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

