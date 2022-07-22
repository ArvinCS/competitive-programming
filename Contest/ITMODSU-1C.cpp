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

int parrent[maxN], real_parrent[maxN], sz[maxN], cnt[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

int getCnt(int x){
	if(real_parrent[x] == x) return cnt[x];
	return cnt[x] + getCnt(real_parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
			swap(x, y);
		}
		
		parrent[b] = a;
		real_parrent[b] = a;
		sz[a] += sz[b];
		cnt[b] -= cnt[a];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<=n;x++){
		parrent[x] = real_parrent[x] = x;
		sz[x] = 1;
		cnt[x] = 0;
	}
	
	while(m--){
		string s;
		cin >> s;
		
		if(s == "get"){
			int a;
			cin >> a;
			
			cout << getCnt(a) << "\n";
		} else {
			int a, b;
			cin >> a >> b;
			
			if(s == "join"){
				merge(a, b);
			} else {
				cnt[getParrent(a)] += b;
			}
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

