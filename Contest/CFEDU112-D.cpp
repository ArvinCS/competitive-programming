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

const int maxN = 2e5 + 5;

int cnt[maxN][3*3+1];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	int idx = 0;
	for(int x=1;x<=3;x++){
		if(n == 1) break;
		
		for(int y=1;y<=3;y++){
			if(x == y) continue;
			
			cnt[0][idx] = (s[0] != ('a'+x-1));
			cnt[1][idx] = (s[1] != ('a'+y-1));
			
			int a = x, b = y;
			for(int i=2;i<n;i++){
				if(s[i] != ('a' + (a^b) - 1)){
					cnt[i][idx] = 1;
				} else {
					cnt[i][idx] = 0;
				}
				
				int tmp = a^b;
				a = b;
				b = tmp;
			}
			idx++;
		}
	}
	
	for(int x=0;x<idx;x++){
		for(int y=1;y<n;y++){
			cnt[y][x] += cnt[y-1][x];		
		}
	}
	
	for(int i=1;i<=q;i++){
		int left, right;
		cin >> left >> right;
		
		left--; right--;
		
		if(n == 1){
			cout << "0\n";
			continue;
		}
		
		int ans = inf_int;
		for(int x=0;x<idx;x++){
			ans = min(ans, cnt[right][x] - (left > 0 ? cnt[left-1][x] : 0));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

