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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int cnt[33];
		fill(cnt, cnt+33, 0);
		
		for(int x=0;x<n;x++){
			for(int i=0;i<=30;i++){
				if(a[x]&(1 << i)){
					cnt[i]++;
				}
			}
		}
		
		int ans = -1;
		for(int x=0;x<=30;x++){
			if(cnt[x] > 0){
				if(ans == -1) ans = cnt[x];
				ans = __gcd(ans, cnt[x]);
			}
		}
		
		if(ans == -1){
			for(int x=1;x<=n;x++){
				if(x > 1) cout << " ";
				cout << x;
			}
			cout << "\n";
			continue;
		}
		
		vector<int> v;
		for(int x=1;x*x<=ans;x++){
			if(ans%x == 0){
				v.push_back(x);
				if(ans/x != x) v.push_back(ans/x);
			}
		}
		
		sort(v.begin(), v.end());
		
		for(int x=0;x<v.size();x++){
			if(x > 0) cout << " ";
			cout << v[x];
		}
		cout << "\n";
	}

    return 0;
}

