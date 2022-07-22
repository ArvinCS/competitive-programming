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

int n, k, ans = 0;

set<vector<string>> st;
vector<string> v;

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

void solve(int cnt){
	if(st.count(v)){
		return;
	}
	st.insert(v);
	
	if(cnt == k){
		ans++;
		return;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(v[x][y] == '.'){
				bool valid = false;
				for(int z=0;z<4;z++){
					if(x+moveX[z] >= 0 && x+moveX[z] < n && y+moveY[z] >= 0 && y+moveY[z] < n){
						if(v[x+moveX[z]][y+moveY[z]] == '@'){
							valid = true;
							break;
						}
					}
				}
				
				if(valid){
					v[x][y] = '@';
					
					solve(cnt+1);
					
					v[x][y] = '.';
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		v.push_back(s);
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(v[x][y] == '.'){
				v[x][y] = '@';
				
				solve(1);
				
				v[x][y] = '.';
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

