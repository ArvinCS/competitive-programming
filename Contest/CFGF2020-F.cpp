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

vector<pair<int, int>> ans;

void solve(int left, int right){
	bool visited[right-left+1];
	
	for(int length=1;length<right-left+1;length<<=1){
		fill(visited, visited+(right-left+1), false);
		
		for(int x=0;x<right-left+1;x++){
			if(!visited[x]){
				visited[x] = visited[x+length] = true;
				ans.push_back({left+x, left+x+length});
			}
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int lg = log2(n);
	
	solve(1, (1 << lg));
	solve(n-(1<<lg)+1, n);
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
	
    return 0;
}

