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

int parrent[maxN], last[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

int getLast(int x){
	if(last[x] == x) return x;
	return last[x] = getLast(last[x]);
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

bool check(int x, int y){
	return (getParrent(x) == getParrent(y));
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
		last[x] = parrent[x] = x;
		sz[x] = 1;
	}
	
	for(int x=0;x<m;x++){
		int t, a, b;
		cin >> t >> a >> b;
		
		a--; b--;
		
		if(t == 3){
			if(check(a, b)) cout << "YES\n";
			else cout << "NO\n";
		} else {
			if(t == 1){
				merge(a, b);
			} else {
				int pos = getLast(a);
				while(pos < b){
					merge(pos, b);
					last[pos] = b;
					
					pos = last[pos+1];
				}
			}
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

