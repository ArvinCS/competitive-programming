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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<ll, int> a[n];
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].second = x;
	}
	
	sort(a, a+n);
	
	pair<ll, int> table[n];
	table[0] = {-a[0].first, 0};
	
	int ans[n];
	fill(ans, ans+n, -1);
	
	for(int x=1;x<n;x++){
		table[x] = table[x-1];
		
		ll cur = (x-3 >= 0 ? a[x-1].first-a[x].first+table[x-3].first : inf_ll);
		if(cur < table[x].first){
			table[x] = make_pair(cur, x);
		}
	}
	
	int cur = n, cnt = 1;
	while(cur > 0){
		for(int y=table[cur-3].second;y<cur;y++){
			ans[a[y].second] = cnt;
		}
		cnt++;
		cur = table[cur-3].second;
	}
	
	cout << a[n-1].first+table[n-3].first << " " << cnt-1 << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

