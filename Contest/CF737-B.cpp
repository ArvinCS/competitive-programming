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
		int n, k;
		cin >> n >> k;
		
		set<int> st;
		int a[n], idx = 0;
		for(int x=0;x<n;x++){
			cin >> a[x];
			st.insert(a[x]);
		}
		
		map<int, int> mp;
		for(auto val : st){
			mp[val] = idx++;
		}
		for(int x=0;x<n;x++){
			a[x] = mp[a[x]];
		}
		
		int last = a[0], cnt = 1;
		for(int x=1;x<n;x++){
			if(last+1 != a[x]){
				cnt++;
			}
			last = a[x];
		}
		
		if(cnt <= k){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

    return 0;
}

