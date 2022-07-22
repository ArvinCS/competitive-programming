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
		string s;
		cin >> s;
		
		int len = s.length();
		vector<int> v[26];
		for(int x=0;x<len;x++){
			v[(s[x] - 'a')].push_back(x);
		}
		
		vector<int> ans;
		set<int> st;
		int cur = 0;
		while(cur < len){
			int pos = len;
			for(int x=25;x>=0;x--){
				if(st.count(x)) continue;
				if(v[x].size() == 0) continue;
				
				if(v[x].back() >= cur) pos = min(pos, v[x].back());
			}
			
			if(pos == len) break;
			
			int idx = -1, c = -1;
			for(int x=25;x>=0;x--){
				if(st.count(x)) continue;
				
				auto it = lower_bound(v[x].begin(), v[x].end(), cur);
				if(it != v[x].end() && *it <= pos){
					idx = *it;
					c = x;
					break;
				}
			}
			
			ans.push_back(c);
			st.insert(c);
			cur = idx+1;
		}
		
		for(int x=0;x<ans.size();x++){
			char c = ('a' + ans[x]);
			cout << c;
		}
		cout << "\n";
	}

    return 0;
}

