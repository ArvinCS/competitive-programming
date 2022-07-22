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

set<vector<int>> st;

void solve(vector<int> &v, int move){
	if(st.count(v)) return;
	st.insert(v);
	
	cout << "(" << move << ") open\n";
	for(auto val : v) cout << val << " ";
	cout << "\n";
	for(int x=0;x<v.size()/2;x++){
		for(int y=0;y<=x;y++){
			swap(v[y], v[v.size()-1-x+y]);
		}
		solve(v, x);
		for(int y=0;y<=x;y++){
			swap(v[y], v[v.size()-1-x+y]);
		}
	}
	cout << "close\n";
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int x=0;x<n;x++){
		v[x] = x+1;
	}
	
	solve(v, 0);
	
	cout << "-----------\n\n";
	for(auto w : st){
		for(auto val : w) cout << val << " ";
		cout << "\n";
	}
    return 0;
}

