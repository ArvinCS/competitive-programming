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

const int maxN = 3 * 1e5 + 25;
const int logN = log2(maxN);

int table[logN+1][maxN];

int query(int left, int right){
	int logL = log2(right-left+1);
	int length = 1 << logL;
	return min(table[logL][left], table[logL][right-length+1]);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int cnt[n+1];
		cnt[0] = 0;
		
		for(int x=0;x<n;x++){
			cin >> table[0][x];
			cnt[x+1] = 0;
		}
		
		for(int x=1;x<=log2(n);x++){
			int length = 1 << x;
			for(int y=0;y+length-1<n;y++){
				table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
			}
		}
		
		int left = 2, right = n-1, pos = n;
		while(left <= right){
			int mid = (left+right) >> 1;
			fill(cnt, cnt+n+1, 0);
			
			bool valid = true;
			for(int x=0;x+mid-1<n;x++){
				int tmp = query(x, x+mid-1);
				if(tmp > n-mid+1 || cnt[tmp] > 0){
					valid = false;
					break;
				}
				cnt[tmp]++;
			}
			
			if(valid){
				right = mid-1;
				pos = mid;
			} else {
				left = mid+1;
			}
		}
		
		int ans[n];
		fill(ans, ans+n, 0);
		
		if(query(0, n-1) == 1) ans[n-1] = 1;
		
		fill(cnt, cnt+n+1, 0);
		bool valid = true;
		for(int x=0;x<n;x++){
			if(cnt[table[0][x]] > 0){
				valid = false;
				break;
			}
			cnt[table[0][x]]++;
		}
		if(valid) ans[0] = 1;
		
		for(int x=pos-1;x<n-1;x++) ans[x] = 1;
		
		for(int x=0;x<n;x++){
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

