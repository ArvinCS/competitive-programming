#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const ll mod2 = 1e9 + 7;
const ll key = 101;
const ll keyA = 9;
const ll keyB = 51;

int n, m;
string s;
bool dif[(1 << 19)];

string dfs(int curNode){
	string cur;
	cur.push_back(s[curNode-1]);
	
	if(2*curNode <= m){
		string l = dfs(2*curNode);
		string r = dfs(2*curNode+1);
		
		if(l > r){
			swap(l, r);
		}
		if(l == r){
			dif[curNode] = false;
		}
		
		for(int x=0;x<l.length();x++){
			cur.push_back(l[x]);
		}
		for(int x=0;x<r.length();x++){
			cur.push_back(r[x]);
		}
	} else {
		dif[curNode] = false;
	}
	
	return cur;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	cin >> s;
	
	m = (1 << n)-1;
	
	fill(dif, dif+m+5, true);
	
	dfs(1);
	
	ll ways[m+5];
	fill(ways, ways+m+5, 1);
	
	for(int x=n-2;x>=0;x--){
		for(int y=(1 << x);y<(1 << (x+1));y++){
			if(!dif[y]){
				ways[y] = ways[2*y] % mod * ways[2*y+1] % mod;
			} else {
				ways[y] = 2*ways[2*y] % mod * ways[2*y+1] % mod;
			}
		}
	}
	
	cout << ways[1] % mod << "\n";
    return 0;
}
