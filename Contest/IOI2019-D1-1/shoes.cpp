#include "shoes.h"
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

const int maxN = 2e5 + 50;

vector<int> v[maxN][2]; // 0 (+) 1 (-)
ll tree[maxN];

ll query(int pos){
	pos = maxN-pos-2;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos];
		
		pos -= pos & (-pos);
	}
	return ans;
}

void update(int pos, ll val){
	pos = maxN-pos-2;
	
	while(pos < maxN){
		tree[pos] += val;
		
		pos += pos & (-pos);
	}
}

ll count_swaps(vector<int> s){
	fill(tree, tree+maxN, 0);
	
	for(int x=s.size()-1;x>=0;x--){
		if(s[x] > 0){
			v[s[x]][0].push_back(x);
		} else {
			v[abs(s[x])][1].push_back(x);
		}
	}
	
	int a[s.size()], pos = 0;
	fill(a, a+s.size(), -1);
	
	for(int x=0;x<s.size();x++){
		if(a[x] == -1){
			if(s[x] > 0){
				a[v[s[x]][1].back()] = pos++;
				a[x] = pos++;
			} else {
				s[x] = abs(s[x]);
				
				a[x] = pos++;
				a[v[s[x]][0].back()] = pos++;
			}
			
			v[s[x]][0].pop_back();
			v[s[x]][1].pop_back();
		}
	}
	
	ll ans = 0;
	for(int x=0;x<s.size();x++){
		ans += query(a[x]+1);
		
		update(a[x], 1);
	}
	return ans;
}
//
//int main(){
//	int n;
//	cin >> n;
//	
//	vector<int> s;
//	for(int x=0;x<2*n;x++){
//		int tmp;
//		cin >> tmp;
//		
//		s.push_back(tmp);
//	}
//	
//	cout << count_swaps(s) << "\n";
//}
