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

pair<ll, ll> better(pair<ll, ll> a, pair<ll, ll> b){
	if(a.first-a.second <= b.first-b.second) return a;
	else return b;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int senar[6];
	for(int x=0;x<6;x++){
		cin >> senar[x];
	}
	
	sort(senar, senar+6);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	pair<int, int> table[n+1][10][10];
	pair<int, int> tmp = {inf_int, -inf_int};
	
	for(int x=0;x<=n;x++){
		for(int y=0;y<6;y++){
			for(int z=0;z<6;z++) table[x][y][z] = tmp;
		}
	}
	
	for(int x=0;x<6;x++){
		table[0][x][0] = {0, 0};
		table[1][x][0] = {data[0]-senar[x], data[0]-senar[x]};
//		cout << table[1][x].first << "," << table[1][x].second << " ";
	}
//	cout << "\n";
	for(int x=1;x<n;x++){
		for(int y=0;y<6;y++){
			for(int z=0;z<6;z++){
				for(int i=0;i<6;i++){
					int dist = table[x+1][y][z].first-table[x+1][y][z].second;
					int a = max(data[x]-senar[y], table[x][z][i].first), b = min(data[x]-senar[y], table[x][z][i].second);
					if(dist >= inf_ll){
						table[x+1][y][z] = {a, b};
					} else if(dist > a-b){
						table[x+1][y][z] = {a, b};
					}
				}
			}
//			cout << table[x+1][y].first << "," << table[x+1][y].second << " ";
		}
//		cout << "\n";
	}
	
	int ans = inf_int;
	for(int x=0;x<6;x++){
		for(int y=0;y<6;y++) ans = min(ans, table[n][x][y].first-table[n][x][y].second);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

