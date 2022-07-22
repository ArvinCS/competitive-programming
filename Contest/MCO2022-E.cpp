#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3005;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	string s;
	cin >> s;
	
	if(n > 3000){
		priority_queue<int> pq;
		ll sum = 0;
		for(int x=1;x<n;x++){
			pq.push(a[x]-a[x-1]);
			sum += a[x]-a[x-1];
		}	
		
		int cnt = 0;
		while(sum > k){
			sum -= pq.top();
			pq.pop();
			cnt++;
		}
		
		cout << cnt << " " << sum << "\n";
		return 0;
	}
	
	ll table[n+1][n];
	fill(table[0], table[n+1], 1e18);
	
	for(int x=0;x<n;x++){
		table[1][x] = a[x]-a[0];
	}
	
	for(int i=1;i<n;i++){
		ll mn[2];
		mn[0] = mn[1] = 1e18;
		
		for(int x=0;x<n;x++){
			if(s[x] == 'L'){
				mn[0] = min(mn[0], (x > 0 ? table[i][x-1] : 0)-a[x]);
			} else {
				mn[1] = min(mn[1], (x > 0 ? table[i][x-1] : 0)-a[x]);
			}
			
			if(s[x] == 'L'){
				table[i+1][x] = min(table[i+1][x], min(mn[0],mn[1])+a[x]);
			} else {
				table[i+1][x] = min(table[i+1][x], mn[1]+a[x]);
			}
		}
	}
	
	pair<int, ll> mn = {1e9, 1e18};
	for(int x=1;x<=n;x++){
		if(table[x][n-1] <= k){
			mn = min(mn, {x, table[x][n-1]});
		}
	}
	
	cout << mn.first-1 << " " << mn.second << "\n";
    return 0;
}

