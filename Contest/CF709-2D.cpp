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

const int maxN = 1e5 + 5;

ll data[maxN], nxt[maxN], prv[maxN], ans[maxN];

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

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
		
		for(int x=0;x<n;x++){
			cin >> data[x];
			nxt[x] = (x+1)%n;
		}
		for(int x=1;x<n;x++){
			prv[x] = x-1;	
		}
		prv[0] = n-1;
		
		int ans[n];
		int sz = 0, idx = 0;
		set<int> st;
		for(int x=1;x<n;x++){
			if(__gcd(data[x-1], data[x]) == 1){
				st.insert(x-1);
			}
		}
		if(__gcd(data[n-1], data[0]) == 1){
			st.insert(n-1);
		}
		
		while(true){
			if(nxt[idx] == idx){
				if(data[idx] == 1){
					ans[sz++] = idx+1;
				}
				break;
			}
			
			auto it = st.lower_bound(idx);
			if(it == st.end()){
				if(st.size() == 0){
					break;
				}
				it = st.begin();
			}
			int val = nxt[*it];
			st.erase(it);
			
			if(st.count(val)){
				st.erase(val);
			}
			ans[sz++] = val+1;
			nxt[prv[val]] = nxt[val];
			prv[nxt[val]] = prv[val];
			
			if(__gcd(data[nxt[val]], data[prv[val]]) == 1){
				st.insert(prv[val]);
			}
			idx = nxt[val];
		}
		
		cout << sz;
		for(int x=0;x<sz;x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

