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
const int logN = log2(maxN) + 1;

int table[logN][maxN];

void build(){
	for(int i=1;i<logN;i++){
		int length = (1 << i);
		for(int x=0;x+length<=maxN;x++){
			table[i][x] = max(table[i-1][x], table[i-1][x+length/2]);
		}
	}
}

int rmq(int left, int right){
	int lg = log2(right-left+1);
	int length = 1 << lg;
	
	return max(table[lg][left], table[lg][right-length+1]);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int p, q, k;
	cin >> p >> k >> q;
	
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
		table[0][x] = a[x];
	}
	for(int y=0;y<m;y++){
		cin >> b[y];
	}
	
	build();
	
	int j = 0;
	for(int i=0;i<n;i++){
		if(j < m && a[i] == b[j]){
			j++;
		}
	}
	
	if(j != m){
		cout << "-1\n";
		return 0;
	}
	
	vector<pair<int, int>> v;
	int last = 0;
	j = 0;
	for(int i=0;i<n;i++){
		if(j < m && a[i] == b[j]){
			if(last <= i-1) v.push_back({last, i-1});
			j++;
			last = i+1;
		}
	}
	if(last <= n-1) v.push_back({last, n-1});
	
	ll ans = 0;
	for(auto e : v){
		int left = e.first, right = e.second;
		int length = right-left+1;
		int mx = rmq(left, right);
		
		bool useQ = false;
		if((left > 0 && mx < a[left-1]) || (right < n-1 && mx < a[right+1])){
			useQ = true;
		}
		
		if(length >= k){
			int tmp = length/k;
			ll mn = inf_ll;
			for(int i=(useQ ? 0 : 1);i*k<=length;i++){
				if(length-i*k < 0) break;
				mn = min(mn, i*1ll*p + (length-i*k)*1ll*q); 
			}
			if(mn == inf_ll){
				cout << "-1\n";
				return 0;
			}
			ans += mn;
		} else {
			if(useQ){
				ans += length*1ll*q;
			} else {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

