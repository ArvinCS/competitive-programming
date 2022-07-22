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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		vector<int> v;
		for(int x=0;x<n;x++){
			v.push_back(a[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		for(int x=0;x<n;x++){
			a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
		}
		
		int l[v.size()], r[v.size()], cnt[v.size()], cnt2[v.size()];
		fill(cnt, cnt+v.size(), 0);
		fill(cnt2, cnt2+v.size(), 0);
		
		for(int x=n-1;x>=0;x--){
			l[a[x]] = x;
		}
		for(int x=0;x<n;x++){
			r[a[x]] = x;
			cnt2[a[x]]++;
		}
		
		int table[n][2];
		fill(table[0], table[n], 0);
		
		int ans = 0;
		for(int x=0;x<n;x++){
			cnt[a[x]]++;
			if(l[a[x]] == x){
				table[a[x]][0] = (a[x] > 0 ? max(cnt[a[x]-1], table[a[x]-1][1]) : 0) + 1;				
				ans = max(ans, table[a[x]][0]);
			} else {
				table[a[x]][0] = table[a[x]][0]+1;
				ans = max(ans, table[a[x]][0]);
			}
			
			if(r[a[x]] == x){
				table[a[x]][1] = table[a[x]][0];
				ans = max(ans, table[a[x]][1]);
			}
			ans = max(ans, (a[x] > 0 ? max(cnt[a[x]-1], table[a[x]-1][1]) : 0)+(cnt2[a[x]]-cnt[a[x]]+1));
		}
		
		cout << n-ans << "\n";
	}
	
    return 0;
}

