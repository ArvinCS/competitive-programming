#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<int, int> a[n];
		for(int x=0;x<n;x++){
			cin >> a[x].first;
			a[x].first--;
			a[x].second = x;
		}
		
		sort(a, a+n);
		
		int cnt[n];
		fill(cnt, cnt+n, 0);
		
		vector<pair<int, int>> v[n];
		for(int x=0;x<n;x++){
			v[cnt[a[x].first]].push_back({a[x].second, a[x].first});
			cnt[a[x].first]++;
		}
		
		int ans[n];
		for(int x=0;x<n;x++){
			for(int y=0;y<v[x].size();y++){
				ans[v[x][y].first] = v[x][(y-1+v[x].size())%v[x].size()].second;
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

