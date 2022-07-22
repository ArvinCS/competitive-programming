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

const int maxN = 1e5 + 50;

int n;
ll tree[maxN][4];

void update(int id, int pos, ll val){
	pos++;
	pos = n+2-pos;
	
	while(pos <= n+5){
		tree[pos][id] += val;
		
		pos += pos & (-pos);
	}
}

ll query(int id, int pos){
	pos++;
	pos = n+2-pos;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos][id];
		
		pos -= pos & (-pos);
	}
	return ans;
}

int transform(char c){
	if(c == 'A') return 0;
	else if(c == 'N') return 1;
	else if(c == 'T') return 2;
	else return 3;
}

char inv(int x){
	if(x == 0) return 'A';
	else if(x == 1) return 'N';
	else if(x == 2) return 'T';
	else return 'O';
}

vector<int> v[4];
int ans[4], cur[4];
ll best = -1;

void solve(int i){
	if(i == 4){
		ll cnt = 0;
		for(int x=3;x>=0;x--){
			for(int y=0;y<x;y++){
				for(auto pos : v[cur[x]]){
					cnt += query(cur[y], pos+1);
				}
			}
		}
		
		if(cnt > best){
			best = cnt;
			for(int x=0;x<4;x++) ans[x] = cur[x];
		}
		return;
	}
	
	for(int x=i;x<4;x++){
		swap(cur[x], cur[i]);
		
		solve(i+1);
		
		swap(cur[x], cur[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		string a;
		cin >> a;
		
		best = -1;
		n = a.length();
		
		for(int x=0;x<4;x++){
			v[x].clear();
			cur[x] = x;
		}
		fill(tree[0], tree[n+10], 0);
		
		for(int x=0;x<a.length();x++){
			v[transform(a[x])].push_back(x);
			update(transform(a[x]), x, 1);
		}
		
		solve(0);
		
		for(int x=0;x<4;x++){
			for(int y=0;y<v[ans[x]].size();y++){
				cout << inv(ans[x]);
			}
		}
		cout << "\n";
	}

    return 0;
}

