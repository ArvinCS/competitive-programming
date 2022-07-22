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

const int maxN = 1e5 + 5, maxK = 15;

int n, k;
ull tree[maxN][maxK];

ull query(int index, int length){
	ull ans = 0;
	while(index > 0){
		ans += tree[index][length];
		index -= index & (-index);
	}
	return ans;
}

void update(int index, int length, ull val){
	while(index <= n){
		tree[index][length] += val;
		index += index & (-index);
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> k;
	
	ull data[n];
	set<ull> s;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
		s.insert(data[x]);
	}
	
	int index = 1;
	unordered_map<ull, int> mp;
	set<ull>::iterator it;
	for(it = s.begin();it != s.end();it++){
		mp[*it] = index++;
	}
	
	for(int x=0;x<n;x++){
		data[x] = mp[data[x]];
	}
	
	for(int x=0;x<n;x++){
		update(data[x], 1, 1);
		for(int y=2;y<=k+1;y++){
			update(data[x], y, query(data[x]-1, y-1));
		}
	}

	cout << query(n, k+1) << "\n";
    return 0;
}

