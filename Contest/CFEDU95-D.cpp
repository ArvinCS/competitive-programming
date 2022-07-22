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

priority_queue<pair<int, int>> pq;
set<int> st;

int solve(){
	if(st.size() == 0) return 0;
	
	int ans = *(st.rbegin()) - *(st.begin());
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(!st.count(p.second)) continue;
		
		auto it = st.find(p.second);
		
		if(it == st.begin()){
			continue;
		}
		
		int mx = p.second;
		it--;
		int mn = *it;
		
		if(p.first != (mx - mn)) continue;
		
		ans -= mx-mn;
		pq.push(p);
		break;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp;
		
		st.insert(tmp);
	}
	
	for(auto it=st.begin();it != st.end();it++){
		if(it == st.begin()) continue;
		
		auto it2 = it;
		it2--;
		 
		int mx = *it;
		int mn = *it2;
		
		pq.push({mx-mn, mx});
	}
	
	cout << solve() << "\n";
	
	for(int x=0;x<q;x++){
		int t, m;
		cin >> t >> m;
		
		if(t == 1){
			st.insert(m);
			
			auto it = st.find(m);
			auto it2 = it;
			it2++;
			
			if(it != st.begin()){
				it--;
				int mn = *it;
				
				pq.push({m-mn, m});
			}			
			if(it2 != st.end()){
				int mx = *it2;
				
				pq.push({mx-m, mx});
			}
		} else {
			auto it = st.find(m);
			auto it2 = it;
			it++;
			
			if(it != st.end() && it2 != st.begin()){
				it2--;
				
				int mx = *it, mn = *it2;
				pq.push({mx-mn, mx});
			}
			
			st.erase(m);
		}
		
		cout << solve() << "\n";
	}
    return 0;
}

