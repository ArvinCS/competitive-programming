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

const int maxN = 205;

pair<int, int> table[maxN][maxN][maxN];
pair<int, int> backtrack[maxN][maxN][maxN];
	
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	string s, t;
	cin >> s >> t;
	
	int n = s.length(), m = t.length();
	fill(*table[0], *table[205], make_pair(inf_int, inf_int));
	table[0][0][0] = {0, 0};
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int x=0;x<=200;x++){
				if(table[x][i][j].first == inf_int) continue;
				
//				cout << x << " " << i << " " << j << " -> " << table[x][i][j].first << "\n";
				int add1 = (i < n && s[i] == '('), add2 = (j < m && t[j] == '(');
				pair<int, int> p = make_pair(table[x][i][j].first+1, 1);
				
				if(table[x+1][i+add1][j+add2] > p){
					table[x+1][i+add1][j+add2] = p;
					backtrack[x+1][i+add1][j+add2] = make_pair(i, j);
				}
				
				add1 = (i < n && s[i] == ')'), add2 = (j < m && t[j] == ')');
				p = make_pair(table[x][i][j].first+1, -1);
				
				if(x > 0 && table[x-1][i+add1][j+add2] > p){
					table[x-1][i+add1][j+add2] = p;
					backtrack[x-1][i+add1][j+add2] = make_pair(i, j);
				}
			}
		}
	}
	
	int mx = inf_int;
	string ans;
	for(int rem=0;rem<=200;rem++){
		if(table[rem][n][m].first+rem < mx){
			int x = rem, i = n, j = m;
			while(table[x][i][j].first > 0){
				char c = (table[x][i][j].second == 1 ? '(' : ')');
				ans.push_back(c);
				
				pair<int, int> prv = backtrack[x][i][j];
				i = prv.first; j = prv.second;
				if(c == '('){
					x--;
				} else {
					x++;
				}
			}
			
			reverse(ans.begin(), ans.end());
			for(int y=0;y<rem;y++) ans.push_back(')');
			
			mx = ans.length();
		}
	}
	
	cout << ans << "\n";
    return 0;
}

