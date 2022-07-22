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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n+1];
	for(int x=1;x<=n;x++){
		cin >> data[x];
	}
	
	bool possible = true;
	vector<pair<int, int>> ans;
	queue<pair<int, int>> hasRow;
	
	int row = n, one = n;
	for(int x=n;x>=1;x--){
		if(data[x] == 0) continue;
		
		int col = x;
		if(data[x] == 1){
			if(row <= 0){
				possible = false;
				break;
			}
			
			ans.push_back({row, col});
			hasRow.push({row, col});
			row--;
		} else if(data[x] == 2){
			if(hasRow.empty() || hasRow.front().second <= col){
				possible = false;
				break;
			} else {
				ans.push_back({hasRow.front().first, col});
				hasRow.pop();
			}
		} else if(data[x] == 3){
			if(row <= 0){
				possible = false;
				break;
			}
			
			while(one > 0 && data[one] <= 1){
				one--;
			}
			
			if(one <= col){
				if(!hasRow.empty() && hasRow.front().second > col){
					ans.push_back({row, col});
					ans.push_back({row, hasRow.front().second});
					
					row--;
					hasRow.pop();
					continue;
				}
				possible = false;
				break;
			}
			
			ans.push_back({row, col});
			ans.push_back({row, one});
			
			row--;
			one--;
		}
	}
	
	if(possible){
		cout << ans.size() << "\n";
		for(auto e : ans){
			cout << e.first << " " << e.second << "\n";
		}
	} else {
		cout << "-1\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

