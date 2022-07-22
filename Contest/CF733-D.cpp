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
	
	int t;	
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		bool done[n], give[n];
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
		}
		
		fill(done, done+n, false);
		fill(give, give+n, false);
		
		int ans[n], cnt = 0;
		fill(ans, ans+n, -1);
		
		vector<int> v, w, z, mark; // can gifted, cannot gifted, hasn't gifted
		for(int x=0;x<n;x++){
			if(!give[x]){
				if(!done[a[x]]){
					ans[x] = a[x];
					b[a[x]] = x;
					done[a[x]] = true;
					give[x] = true;
					cnt++;
					mark.push_back(x);
				}
			}
		}
		for(int x=0;x<n;x++){
			if(!give[x]){
				if(done[x]){
					w.push_back(x);
				} else {
					v.push_back(x);
				}
			} else {
				if(!done[x]){
					z.push_back(x);
				}
			}
		}
	
		while(!w.empty() && !z.empty()){
			ans[w.back()] = z.back();
			z.pop_back();
			w.pop_back();
		}
					
		if(v.size() == 1){
			int nxt = a[v[0]];
			int nxt2 = b[nxt];
			
			ans[nxt2] = v[0];
			ans[v[0]] = nxt;
		} else {
			for(int x=0;x<v.size();x++){
				int cur = v[x], nxt = v[(x+1)%v.size()];
//				cout << cur << " " << nxt << "\n";
				give[cur] = give[nxt] = true;
				done[cur] = done[nxt] = true;
				
				ans[cur] = nxt;
			}
		}
		
		cout << cnt << "\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

