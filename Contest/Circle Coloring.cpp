#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		int data[3][n];
		for(int x=0;x<3;x++){
			for(int y=0;y<n;y++){
				cin >> data[x][y];
			}	
		}
		
		vector<int> ans;
		unordered_set<int> exist;
		
		ans.push_back(data[0][0]);
		exist.insert(data[0][0]);
		
		int prev = data[0][0];
		for(int x=1;x<n;x++){
			if(data[0][x] != prev && (x < n-1 || data[0][x] != ans[0])){
				ans.push_back(data[0][x]);
				prev = data[0][x];
			} else if(data[1][x] != prev && (x < n-1 || data[1][x] != ans[0])){
				ans.push_back(data[1][x]);
				prev = data[1][x];
			} else if(data[2][x] != prev && (x < n-1 || data[2][x] != ans[0])){
				ans.push_back(data[2][x]);
				prev = data[2][x];
			}
		}
		
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

