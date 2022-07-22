#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxBit = 1048577;

int table[maxBit];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	int cnt[m][m];
	fill(cnt[0], cnt[m], 0);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(x+1 < n) cnt[(s[x] - 'a')][(s[x+1] - 'a')]++;
		ans |= (1 << (s[x] - 'a'));
	}
	
	
	fill(table, table+maxBit, 1e9);
	
	table[0] = 0;
	for(int x=0;x<(1 << m);x++){
		int one = __builtin_popcount(x);
		for(int y=0;y<m;y++){
			int bit = (1 << y);
			
			if(x&bit) continue;
			
			int sum = 0, exc = 0;
			for(int z=0;z<m;z++){
				if(y == z) continue;
				
				sum += cnt[y][z] + cnt[z][y];
				if(x&(1 << z)){
					exc += cnt[y][z] + cnt[z][y];
				}
			}
			
			table[x|bit] = min(table[x|bit], table[x]+exc*one-(sum-exc)*one);
		}
	}
	
	cout << table[ans] << "\n";
    return 0;
}

