#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxQ = 1e6 + 5;

string s[maxQ], t[maxQ];
int ans[maxQ];

void solve(int idx, vector<int> &v, vector<int> &w){
	if(v.size() == 0 || w.size() == 0) return;
	for(int x=0;x<w.size();x++){
		if(t[w[x]].length() <= idx){
			ans[w[x]] = v.size();
		}
	}
	
	vector<int> new_v, new_w;
	for(int c=0;c<26;c++){
		for(int x=0;x<v.size();x++){
			if(s[v[x]].length() > idx && (s[v[x]][idx] - 'a') == c){
				new_v.push_back(v[x]);
			}
		}
		for(int x=0;x<w.size();x++){
			if(t[w[x]].length() > idx && (t[w[x]][idx] - 'a') == c){
				new_w.push_back(w[x]);
			}
		}
		
		solve(idx+1, new_v, new_w);
		new_v.clear(); new_w.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v, w;
	for(int x=0;x<n;x++){
		cin >> s[x];
		v.push_back(x);
	}
	for(int x=0;x<q;x++){
		cin >> t[x];
		w.push_back(x);
	}
	
	fill(ans, ans+maxQ, 0);
	solve(0, v, w);
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

