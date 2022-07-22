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
	
	int h, w, n;
	cin >> h >> w >> n;
	
	set<int> st1, st2;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		st1.insert(p[x].first);
		st2.insert(p[x].second);
	}
	
	map<int, int> mp1, mp2;
	int idx = 1;
	for(auto val : st1){
		mp1[val] = idx++;
	}
	idx = 1;
	for(auto val : st2){
		mp2[val] = idx++;
	}
	
	for(int x=0;x<n;x++){
		cout << mp1[p[x].first] << " " << mp2[p[x].second] << "\n";
	}
    return 0;
}

