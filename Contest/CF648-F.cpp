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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		bool possible = true;
		vector<int> v;
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			v.push_back(a[x]);
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			v.push_back(b[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		map<int, int> mp;
		for(int x=0;x<v.size();x++){
			mp[v[x]] = x+1;
		}
		
		for(int x=0;x<n;x++){
			a[x] = mp[a[x]];
			b[x] = mp[b[x]];
		}
		
		if(n % 2 == 1 && a[n/2] != b[n/2]){
			possible = false;
		}
		
		int cnt[2*n+1][2*n+1];
		fill(cnt[0], cnt[2*n+1], 0);
		
		for(int x=0;x<n/2;x++){
			cnt[a[x]][a[n-1-x]]++;
		}
		
		for(int x=0;x<n/2;x++){
			if(cnt[b[x]][b[n-1-x]] > 0){
				cnt[b[x]][b[n-1-x]]--;
			} else if(cnt[b[n-1-x]][b[x]] > 0){
				cnt[b[n-1-x]][b[x]]--;
			} else {
				possible = false;
			}
		}
		
		if(possible){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

    return 0;
}

