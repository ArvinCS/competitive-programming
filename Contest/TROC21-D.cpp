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

const int maxN = 1e5 + 5;

ll cnt[3];
ll table[maxN][3]; // 0 normal 1 decrease 2 increase
int op[3] = {0, -1, 1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	fill(table[0], table[maxN], inf_ll);
	
	table[0][0] = 0;
	table[0][1] = table[0][2] = 1;
	
	cnt[0]++;
	cnt[1]++;
	cnt[2]++;
	
	for(int x=1;x<n;x++){
		ll cnt2[3];
		for(int y=0;y<3;y++){
			int idx = -1;
			for(int z=0;z<3;z++){
				if(data[x]+op[y] < data[x-1]+op[z]) continue;
				
				ll tmp = (y != 0 ? 1 : 0) + table[x-1][z];
				if(data[x]+op[y]-1 == data[x-1]+op[z]) tmp += cnt[z];
				if(table[x][y] > tmp){
					table[x][y] = tmp;
					idx = z;
				}
			}
			
			if(data[x]+op[y] == data[x-1]+op[idx]){
				cnt2[y] = cnt[idx]+1;
			} else {
				if(data[x]+op[y] < data[x-1]+op[idx]){
					cnt2[y] = cnt[idx];
				} else {
					cnt2[y] = 1;
				}
			}
		}
		
		for(int y=0;y<3;y++){
			cnt[y] = cnt2[y];
		}
	}
	
	ll ans = inf_ll;
	for(int x=0;x<3;x++){
		ans = min(ans, table[n-1][x]);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

