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

int dsu[maxN], sz[maxN], cnt = 0;
bool pick[maxN];

void new_set(int x){
	dsu[x] = x;
	sz[x] = 1;
	cnt++;
}

int getParrent(int x){
	if(dsu[x] == x) return x;
	return dsu[x] = getParrent(dsu[x]);
}

void merge(int a, int b){
	a = getParrent(a);
	b = getParrent(b);
	
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	
	dsu[b] = a;
	cnt -= (sz[a]+1)/2 + (sz[b]+1)/2;
	cnt += (sz[a]+sz[b]+1)/2;
	sz[a] += sz[b];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> v;
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		v.push_back({data[x], x});
	}

	sort(v.begin(), v.end());
	fill(pick, pick+n, false);
	
	int ans = -1;
	for(int x=0;x<n;x++){
		int idx = v[x].second;
		
		if(cnt == k/2){
			if(k&1){
				if((!pick[0] || sz[getParrent(0)]%2 == 0) && (!pick[n-1] || sz[getParrent(n-1)]%2 == 0)){
					break;
				}
			} else {
				if((!pick[0] || sz[getParrent(0)]%2 == 0) || (!pick[n-1] || sz[getParrent(n-1)]%2 == 0)){
					break;
				}
			}
		}
		if(cnt > k/2) break;
		
		pick[idx] = true;
		new_set(idx);
		if(idx-1 >= 0 && pick[idx-1]){
			merge(idx-1, idx);
		}
		if(idx+1 < n && pick[idx+1]){
			merge(idx, idx+1);
		}
		ans = data[idx];
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

