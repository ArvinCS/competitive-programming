#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[m];
	for(int x=0;x<m;x++){
		cin >> a[x];
	}
	
	vector<pair<int, int>> v;
	ll cnt[n+1], sum[n+1];
	fill(sum, sum+n+1, 0);
	fill(cnt, cnt+n+1, 0);
	
	for(int x=0;x<m;x++){
		if(x > 0){
			if(a[x-1] < a[x]){
				cnt[a[x]] += a[x-1]-(a[x]-a[x-1]);
			} else if(a[x-1] > a[x]){
				cnt[a[x]] += a[x-1]-1-(a[x-1]-a[x]);
			}
		}
		if(x+1 < m){
			if(a[x+1] < a[x]){
				cnt[a[x]] += a[x+1]-(a[x]-a[x+1]);
			} else if(a[x+1] > a[x]){
				cnt[a[x]] += a[x+1]-1-(a[x+1]-a[x]);
			}
			
			if(a[x] != a[x+1]){
				sum[min(a[x], a[x+1])+1]++;
				sum[max(a[x], a[x+1])]--;
			}
		}
	}
	
	for(int x=1;x<=n;x++){
		sum[x] += sum[x-1];
	}
	
	ll ans[n+1];
	ll cur = 0;
	for(int x=1;x<m;x++){
		cur += abs(a[x]-a[x-1]);
	}
	
	ans[1] = cur;
	
	for(int x=2;x<=n;x++){
		ans[x] = cur+cnt[x]-sum[x];
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

