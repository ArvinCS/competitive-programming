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

const int maxN = 5e4 + 5;

int parrent[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		parrent[b] = a;
		sz[a] += sz[b];
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<=n;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
	}
	
	tuple<int, int, int> data[k];
	for(int x=0;x<k;x++){
		string s;
		int a, b;
		cin >> s >> a >> b;
		
		if(s == "ask"){
			data[x] = make_tuple(0, a, b);
		} else {
			data[x] = make_tuple(1, a, b);
		}
	}
	
	vector<bool> ans;
	for(int x=k-1;x>=0;x--){
		int t = get<0>(data[x]), a = get<1>(data[x]), b = get<2>(data[x]);
		
		if(t){
			merge(a, b);
		} else {
			if(getParrent(a) == getParrent(b)){
				ans.push_back(true);
			} else {
				ans.push_back(false);
			}
		}
	}
	
	for(int x=ans.size();x>=1;x--){
		if(ans[x-1])cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

