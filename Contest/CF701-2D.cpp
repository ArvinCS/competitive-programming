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

const int maxN = 505;

int grid[maxN][maxN], ans[maxN][maxN], n, m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=1;x<=32;x++){
		int cur = x;
		for(int y=0;y<3;y++){
			cur *= x;
		}
		
		v.push_back(cur);
	}
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	fill(ans[0], ans[n], -1);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if((x+y)%2 == 0){
				ans[x][y] = 720720;
			} else {
				for(auto d : v){
					if(d < 720720 && (720720-d)%grid[x][y] == 0){
						ans[x][y] = (720720-d);
						break;
					}
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(y > 0) cout << " ";
			cout << ans[x][y];
		}
		cout << "\n";
	}
    return 0;
}

