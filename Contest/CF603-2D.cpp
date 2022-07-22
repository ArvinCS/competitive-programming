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

int parrent[30], sz[30];

void make_set(int x){
	parrent[x] = x;
}

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void join(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]) swap(a, b);
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	string s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	for(int x=0;x<=27;x++){
		parrent[x] = -1;
		sz[x] = 1;
	}
	
	for(int x=0;x<n;x++){
		if(parrent[s[x][0] - 'a'] == -1){
			make_set(s[x][0]-'a');
		}
		
		for(int y=1;y<s[x].length();y++){
			if(parrent[s[x][y]-'a'] == -1) make_set(s[x][y] - 'a');
			if(parrent[s[x][0]-'a'] != getParrent(s[x][y] - 'a')){
				join(s[x][0] - 'a', s[x][y] - 'a');
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<27;x++){
		if(x == parrent[x]){
			ans++;
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

