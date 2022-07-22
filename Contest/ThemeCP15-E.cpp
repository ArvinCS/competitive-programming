#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string d[n];
	for(int x=0;x<n;x++){
		cin >> d[x];
	}
	
	ll table[n][4][4]; // [cur_idx][start_state][cur_state]
	fill(*table[0], *table[n], 0);
	
	for(int x=0;x<4;x++){
		if(d[0][0] != '?'){
			if(d[0][0] == 'B' && x % 2 == 0) continue;
			else if(d[0][0] == 'W' && x % 2 == 1) continue;
		}
		if(d[0][1] != '?'){
			if(d[0][1] == 'B' && (x&2) == 0) continue;
			else if(d[0][1] == 'W' && (x&2) == 2) continue;
		}
		
		table[0][x][x]++;
	}
	
	for(int x=1;x<n;x++){
		for(int s=0;s<4;s++){
			for(int p=0;p<4;p++){
				for(int c=0;c<4;c++){
					if(d[x][0] != '?'){
						if(d[x][0] == 'B' && (c&1) == 0) continue;
						else if(d[x][0] == 'W' && (c&1) == 1) continue;
					}
					if(d[x][1] != '?'){
						if(d[x][1] == 'B' && (c&2) == 0) continue;
						else if(d[x][1] == 'W' && (c&2) == 2) continue;
					}
					if(((p&2) != 0) == ((c&1) != 0)) continue;
					
					chadd(table[x][s][c], table[x-1][s][p]);
				}
			}
		}
	}
	
	ll ans = 0;
	for(int s=0;s<4;s++){
		for(int c=0;c<4;c++){
			if(((c&2) != 0) == ((s&1) != 0)) continue;
			
			chadd(ans, table[n-1][s][c]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

