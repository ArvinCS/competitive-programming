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
		
		set<ll> st;
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		bool valid = true;
		st.insert(data[0]);
		for(int x=1;x<n;x++){
			auto it = st.find(data[x-1]);
			auto prv = it;
			auto nxt = it;
			prv--;
			nxt++;
			
			int a = (it == st.begin() ? -inf_ll : *prv), b = (nxt == st.end() ? inf_ll : *nxt);
			if(a > data[x] || data[x] > b){
				valid = false;
				break;
			}
			st.insert(data[x]);
		}
		
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

