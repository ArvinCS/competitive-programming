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

	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	int block = sqrt(m)+1;
	int a[m], start[n], b[block+1][block+1];
	fill(a, a+m, 0);
	fill(start, start+n, inf_int);
	fill(b[0], b[block+1], 0);
	
	int ans = 0;
	for(int i=0;i<m;i++){
		int op, k;
		cin >> op >> k;
		
		k--;
		if(op == 1){
			if(p[k].first+p[k].second >= block){
				for(int x=i+p[k].first;x<m;x+=p[k].first+p[k].second){
					a[x]++;
					if(x+p[k].second < m) a[x+p[k].second]--;
				}
			} else {
				int sz = p[k].first+p[k].second;
				int left = (i+p[k].first) % sz, right = (i-1) % sz;
				
				if(left <= right){
					for(int x=left;x<=right;x++) b[sz][x]++;
				} else {
					for(int x=left;x<sz;x++) b[sz][x]++;
					for(int x=0;x<=right;x++) b[sz][x]++;
				}
			}
			
			start[k] = i;
		} else {
			if(p[k].first+p[k].second >= block){
				for(int x=start[k]+p[k].first;x<m;x+=p[k].first+p[k].second){
					a[x]--;
					if(x+p[k].second < m) a[x+p[k].second]++;
					if(x < i && i <= x+p[k].second) ans--;
				}
			} else {
				int sz = p[k].first+p[k].second;
				int left = (start[k]+p[k].first) % sz, right = (start[k]-1) % sz;
				
				if(left <= right){
					for(int x=left;x<=right;x++) b[sz][x]--;
				} else {
					for(int x=left;x<sz;x++) b[sz][x]--;
					for(int x=0;x<=right;x++) b[sz][x]--;
				}
			}
			
			start[k] = inf_int;
		}
		
		ans += a[i];
		
		int cnt = 0;
		for(int x=2;x<=block;x++){
			cnt += b[x][i%x];
		}
		
		cout << ans+cnt << "\n";
	}

    return 0;
}

