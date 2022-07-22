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

const int maxN = 5e4 + 5;

int cnt[maxN][3];

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
		
		int r[n][5];
		for(int x=0;x<n;x++){
			for(int y=0;y<5;y++){
				cin >> r[x][y];
			}
		}
		
		int idx = 0;
		for(int x=1;x<n;x++){
			int a = 0, b = 0;
			for(int y=0;y<5;y++){
				if(r[idx][y] < r[x][y]){
					a++;
				} else {
					b++;
				}
			}
			
			if(b > a){
				idx = x;
			}
		}
		
		bool valid = true;
		for(int x=0;x<n;x++){
			if(x == idx) continue;
			
			int cnt = 0;
			for(int y=0;y<5;y++){
				if(r[idx][y] > r[x][y]){
					cnt++;
				}
			}
			
			if(cnt >= 3){
				valid = false;
				break;
			}
		}
		
		cout << (valid ? idx+1 : -1) << "\n";
	}

    return 0;
}

