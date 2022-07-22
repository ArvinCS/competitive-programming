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

int table[101][101][10001];
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int sum = 0;
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
		sum += data[x].second;
	}
	
	for(int x=0;x<=n;x++){
		for(int y=0;y<=n;y++){
			for(int z=0;z<=10000;z++){
				table[x][y][z] = -inf_int;
			}
		}
	}
	
	for(int x=0;x<=n;x++){
		table[x][0][0] = 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int a=0;a<=10000;a++){
			for(int x=0;x<n;x++){
				if(data[x].first <= a) table[x+1][i][a] = max(table[x][i][a], table[x][i-1][a-data[x].first] + data[x].second);
				else table[x+1][i][a] = table[x][i][a];
//				cout << a << " " << x << " " << table[x+1][i][a] << "\n";
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(i > 1) cout << " ";
		double ans = 0;
		for(int a=1;a<=10000;a++){
			for(int x=1;x<=n;x++){
				ans = max(ans, min(a*1.0, table[x][i][a]/2.0 + sum/2.0));
			}
		}
		cout << fixed << setprecision(10) << ans;
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

