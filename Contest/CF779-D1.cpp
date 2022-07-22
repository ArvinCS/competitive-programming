#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxR = (1 << 17);

int cnt[maxR][20];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<20;x++){
		cnt[0][x] = 0;
	}
	for(int x=1;x<maxR;x++){
		for(int y=0;y<20;y++){
			cnt[x][y] = cnt[x-1][y];
			if(x&(1 << y)){
				cnt[x][y]++;
			}		
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int l, r;
		cin >> l >> r;
		
		int n = r-l+1;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int table[20];
		fill(table, table+20, 0);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<20;y++){
				if(a[x]&(1 << y)){
					table[y]++;
				}
			}
		}
		
		int ans = 0;
		for(int y=0;y<20;y++){
			if(table[y] != cnt[r][y]){
				ans |= (1 << y);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

