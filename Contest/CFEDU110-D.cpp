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

const int maxN = 262145;

int tree[maxN];
int k, n, m;
string s;

void build(){
	for(int x=n-1;x>=0;x--){
		if(2*x+1 >= n){
			tree[x] = (s[x] == '?' ? 2 : 1);
		} else {
			if(s[x] == '?'){
				tree[x] = tree[2*x+1] + tree[2*x+2];
			} else if(s[x] == '0'){
				tree[x] = tree[2*x+2];
			} else {
				tree[x] = tree[2*x+1];
			}
		}
	}
}

int update(int x){
	if(x >= n) return 0;
	if(2*x+1 >= n){
		return tree[x] = (s[x] == '?' ? 2 : 1);
	}
	
	if(s[x] == '?'){
		return tree[x] = tree[2*x+1] + tree[2*x+2];
	} else if(s[x] == '0'){
		return tree[x] = tree[2*x+2];
	} else {
		return tree[x] = tree[2*x+1];
	}
}

int query(int x){
	return tree[x];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
		
	cin >> k;
	cin >> s;
	
	reverse(s.begin(), s.end());
	n = s.length(); m = inf_int;
	
	build();
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int a;
		char c;
		cin >> a >> c;
		
		a = (n-a);
		
		int bef = query(a);
		s[a] = c;
		int now = update(a);
		
//		cout << bef << " - " << now << " " << query(6) << "\n";
		int x = a;
		while(x > 0){
			int parrent = max(0, (x-1)>>1);
//			cout << i << ": " << x << " " << s[parrent] << "\n";
 			if(s[parrent] == '?' || ((s[parrent] - '0') == x%2)){
// 				cout << "upd " << (bef-now) << "\n";
				tree[parrent] -= (bef-now);
			} else {
				break;
			}
			
			x = parrent;
		}
		
		cout << query(0) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

