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

const int maxK = (1 << 11);
const int maxD = 12;

int k;
ll table[maxK][maxD][2], pw[maxD];
vector<int> v;

ll solve(int idx, int mask, int cnt, bool great){ // O(2^K.N.2)
	if(idx >= v.size()) return table[mask][idx][great] = 0;
	if(table[mask][idx][great] != -1) return table[mask][idx][great];
		
	ll ans = inf_ll;
	for(int x=(great ? 0 : v[idx]);x<10;x++){
		int bit = (1 << x);
		if(mask&bit || cnt < k){
			ans = min(ans, x*pw[v.size()-idx-1] + solve(idx+1, mask|bit, cnt+(mask&bit ? 0 : 1), great||(x > v[idx])));
		}
	}
	
	return table[mask][idx][great] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	pw[0] = 1ll;
	for(int x=1;x<maxD;x++){
		pw[x] = 10ll*pw[x-1];
	}
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n >> k;
		
		v.clear();
		
		while(n > 0){
			v.push_back(n%10);
			n /= 10;
		}
		
		reverse(v.begin(), v.end());
		
		bool great = false;
		
		vector<int> ans, w;
		set<int> st;
		
		st.insert(v[0]);
		ans.push_back(v[0]);
		w.push_back(0);
		
		for(int x=1;x<v.size();x++){
			if(great){
				if(st.size() < k){
					w.push_back(x);
					st.insert(0);
				}
				ans.push_back(*(st.begin()));
				continue;
			}
			
			if(st.count(v[x])){
				ans.push_back(v[x]);
			} else {
				if(st.size() < k){
					st.insert(v[x]);
					w.push_back(x);
					ans.push_back(v[x]);
				} else {
					auto it = st.lower_bound(v[x]+1);
					
					if(it == st.end()){
						int pos = -1;
						for(int y=x-1;y>w.back();y--){
							auto it2 = st.lower_bound(ans[y]+1);
							
							if(it2 != st.end()){
								pos = y;
								ans[y] = *it2;
								break;
							}
						}	
						
						if(pos == -1){	
							pos = w.back();
							int old = ans[w.back()];
							st.erase(old);
							
							ans[w.back()]++;
							st.insert(ans[w.back()]);
						}
						
						if(st.size() < k && !st.count(0)){
							w.push_back(x);
							st.insert(0);
						}
						
						for(int y=pos+1;y<x;y++){
							ans[y] = *(st.begin());
						}
						
						ans.push_back(*(st.begin()));
					} else {
						ans.push_back(*it);
					}
					great = true;
				}
			}
		}
		
		for(int x=0;x<ans.size();x++){
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}
 
