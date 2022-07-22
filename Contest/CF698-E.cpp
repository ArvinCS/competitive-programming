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

const int maxN = 200010;
const int logN = 18;

int table[logN][maxN];

void build(int n){
	int lg = log2(n);
	for(int x=1;x<=lg;x++){
		int length = 1 << x;
		for(int y=0;y+length-1<n;y++){
			table[x][y] = table[x-1][y] + table[x-1][y+(length/2)];
		}
	}	
}

int query(int left, int right){
	int lg = log2(right-left+1), cur = left;
	int ans = 0;
	
	for(int x=lg;x>=0;x--){
		int length = 1 << x;
		if(left+length-1 <= right){
			ans += table[x][left];
			left += length;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		string s, f;
		cin >> s >> f;
		
		pair<int, int> p[m];
		for(int x=0;x<m;x++){
			cin >> p[x].first >> p[x].second;
			p[x].first--; p[x].second--;
		}
		
		if(m == 0){
			if(s == f) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		
		for(int x=0;x<n;x++){
			table[0][x] = (f[x] - '0');
		}
		build(n);
		
		bool possible = true;
		for(int x=m-1;x>=0;x--){
			int one = query(p[x].first, p[x].second);
			int zero = (p[x].second-p[x].first+1)-one;
			
			if(zero == one){
				possible = false;
				break;
			}
			if(abs(one-zero) == p[x].second-p[x].first+1) continue;
			if(zero > one){
				for(int y=p[x].first;y<=p[x].second;y++){
					table[0][y] = 0;
				}
			} else {
				for(int y=p[x].first;y<=p[x].second;y++){
					table[0][y] = 1;
				}
			}
			build(n);	
		}
		
//		for(int x=0;x<n;x++){
//			cout << table[0][x];
//		}
//		cout << "\n";
		for(int x=0;x<n;x++){
			if((s[x]-'0') != table[0][x]){
				possible = false;
				break;
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
    
	return 0;
}

// Santai
// Pikirin dengan benar-benar

