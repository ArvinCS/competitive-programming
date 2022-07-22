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

const int maxN = 2e5 + 5;

int n;
vector<int> adj[maxN];

int getLeftBit(int n, int m){
	for(int x=m;x>=0;x--){
		if(n&(1<<x)){
			return x;
		}
	}
	return -1;
}

int solve(int i, vector<int> data){
	if(i <= 0) return data.size();
	if(data.size() <= 1) return data.size();
	
	int table[33], empty = 0;
	fill(table, table+33, 0);
	
	vector<int> v[33];
	for(int x=0;x<data.size();x++){
		int tmp = getLeftBit(data[x], i);
		if(tmp < 0) empty++;
		else v[tmp].push_back(data[x]);
	}
	
	for(int x=0;x<=i;x++){
		table[x] = solve(x-1, v[x]);
	}
	
	vector<int> ok;
	for(int x=0;x<=i;x++){ // case 2 collect 1 element from all set + empty bit
		if(v[x].size() > 0) ok.push_back(x);
	}
	
	int ans = 0;
	for(int x=0;x<=i;x++){ // case 1 (take a set that has >1 elements with/out 1 element from set less than bit x and with 1 element from all set greater than bit x)
		auto it = lower_bound(ok.begin(), ok.end(), x);
		auto it2 = upper_bound(ok.begin(), ok.end(), x);
		
		int take = table[x], take2 = table[x]+empty;
		if(it != ok.begin()){
			take++;
		}
		if(it2 != ok.end()){
			take += ((int) ok.size()) - (it2 - ok.begin());
			take2 += ((int) ok.size()) - (it2 - ok.begin());
		}
		ans = max(ans, max(take, take2));
	}
	
	return max(ans, ((int)ok.size())+empty);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	vector<int> data;
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp;
		
		data.push_back(tmp);
	}
	
	sort(data.begin(), data.end());
	
	cout << ((int) data.size())-solve(31, data) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

