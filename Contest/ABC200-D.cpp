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

bool table[205][205];
int n;
ll arr[205];
vector<vector<int>> ans;

void buildPath(int curIdx, int sum, vector<int>& path){
	if(path.size() > 0 && sum == 0){
		ans.push_back(path);
		return;
	}
	
	if(curIdx <= 0){
		return;
	}	
	
	if(table[curIdx-1][sum]){
		vector<int> tmp = path;
		buildPath(curIdx-1, sum, tmp);
	}
	
	if(table[curIdx-1][(sum-arr[curIdx-1]+200)%200]){
		path.push_back(curIdx);
		buildPath(curIdx-1, (sum-arr[curIdx-1]+200)%200, path);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> arr[x];
		arr[x] %= 200;
	}
	
	fill(table[0], table[n+1], false);
	
	for(int x=0;x<=n;x++){
		table[x][0] = true;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<200;y++){
			table[x+1][y] = (table[x][y] || table[x][(y-arr[x]+200)%200]);
			if(x > 0 && table[x][y] && table[x][(y-arr[x]+200)%200]){
				ans.clear();
				vector<int> tmp;
				buildPath(x+1, y, tmp);
				
				if(ans.size() > 1){
					cout << "Yes\n";
					
					sort(ans[0].begin(), ans[0].end());
					cout << ans[0].size();
					for(int x=0;x<ans[0].size();x++){
						cout << " " << ans[0][x];
					}
					cout << "\n";
					
					sort(ans[1].begin(), ans[1].end());
					cout << ans[1].size();
					for(int x=0;x<ans[1].size();x++){
						cout << " " << ans[1][x];
					}
					cout << "\n";
					return 0;
				}
			}
		}
	}
	
	cout << "No\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

