#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}	
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
} dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ifstream fin("input_file.txt", ifstream::in);
    ifstream ans("myAnswer.txt", ifstream::in);
	    
	int n, m;
	fin >> n >> m;
	
	pair<int, int> p[m];
	ll c[m];
	vector<int> v[2];
	for(int x=0;x<m;x++){
		int a, b;
		fin >> a >> b >> c[x];
		
		a--; b--;
		
		c[x] %= 2;
		v[c[x]%2].push_back(x);
		p[x] = {a, b};
	}
	
	string valid = "NO";
	
	for(int state=0;state<(1 << m);state++){
		dsu.reset(n);
		int sum = 0, cnt = n;
		for(int x=0;x<m;x++){
			if(state&(1 << x)){
				if(dsu.merge(p[x].first, p[x].second)){
					sum += c[x];
//					sum %= 2;
					cnt--;
				}
			}
		}
		
		if(cnt == 1 && sum%2 == 0 && __builtin_popcount(state) == n-1){
//			cout << state << " " << sum << "\n";
			valid = "YES";
			break;
		}
	}
	
	string res;
	ans >> res;
	if(res == "NO"){
		if(valid == "YES"){
			cout << "FOUND ANSWER BUT YOU NOT\n";
			return -1;
		}
		return 0;
	}
	
	dsu.reset(n);
	
	int sum = 0;
	for(int x=0;x<n-1;x++){
		int idx;
		ans >> idx;
		
		assert(idx >= 1 && idx <= m);
		if(dsu.merge(p[idx-1].first, p[idx-1].second)){
			sum += c[idx-1];
		} else {
			cout << "MERGED ALREADY MERGED\n";
			return -1;
		}
	}
	
	if(sum%2 == 1){
		cout << "SUM IS STILL ODD\n";
		return -1;
	}
	
	cout << "OK\n";
    return 0;
}

