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
	
	int n;
	cin >> n;
	
	int h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	stack<pair<int, int>> st;
	int a[n], b[n], c[n], d[n];
	for(int x=0;x<n;x++){
		while(!st.empty() && st.top().first > h[x]){
			st.pop();		
		}
		
		if(st.empty()) a[x] = -1;
		else a[x] = st.top().second;
		
		st.push({h[x], x});
	}
	while(!st.empty()) st.pop();
	
	for(int x=0;x<n;x++){
		while(!st.empty() && st.top().first < h[x]){
			st.pop();		
		}
		
		if(st.empty()) b[x] = -1;
		else b[x] = st.top().second;
		
		st.push({h[x], x});
	}
	while(!st.empty()) st.pop();
	
	for(int x=n-1;x>=0;x--){
		while(!st.empty() && st.top().first > h[x]){
			st.pop();		
		}
		
		if(st.empty()) c[x] = -1;
		else c[x] = st.top().second;
		
		st.push({h[x], x});
	}
	while(!st.empty()) st.pop();
	
	for(int x=n-1;x>=0;x--){
		while(!st.empty() && st.top().first < h[x]){
			st.pop();		
		}
		
		if(st.empty()) d[x] = -1;
		else d[x] = st.top().second;
		
		st.push({h[x], x});
	}
	while(!st.empty()) st.pop();
	
	int table[n];
	fill(table, table+n, inf_int);
	
	table[0] = 0;
	
	vector<int> v[n];
	for(int x=0;x<n;x++){
		if(a[x] != -1) v[x].push_back(a[x]);
		if(b[x] != -1) v[x].push_back(b[x]);
		if(c[x] != -1) v[c[x]].push_back(x);
		if(d[x] != -1) v[d[x]].push_back(x);
	}
	
	for(int x=1;x<n;x++){
		table[x] = table[x-1]+1;
		
		for(auto prv : v[x]){
			table[x] = min(table[x], table[prv]+1);
		}
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

