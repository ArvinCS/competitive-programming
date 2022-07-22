#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

ui tree[100001];

void compression(ui data[], ui n){
	set<ui> s;
	for(ui x=0;x<n;x++) s.insert(data[x]);
	
	ui index = 1;	
	unordered_map<ui, ui> mp;
	set<ui>::iterator it;
	
	for(it = s.begin();it != s.end();it++){
		mp[*it] = index++;
//		cout << *it << " -> " << index << "\n";
	}
	
	for(ui x=0;x<n;x++){
		data[x] = mp[data[x]];
	}
}

ui query(ui index){	
	ui ans = 0;
	while(index > 0){
		ans += tree[index];
		ans %= mod;
		index -= index & (-index);
	}	
	return ans;
}

void update(ui index, ui n){
	ui value = (query(index) + 1) % mod;
	while(index <= n){
		tree[index] += value;
		tree[index] %= mod;
		index += index & (-index);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	fill(tree, tree+n+1, 0);
	
	ui data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	compression(data, n);

	for(ui x=0;x<n;x++){
		update(data[x], n);
		for(ui x=1;x<=n;x++){
			cout << tree[x] << " ";
		}
		cout << "\n";
	}
	cout << query(n) % mod << "\n";
    return 0;
}

