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

const int maxN = 1e4 + 5, maxM = 1e5 + 5;

int n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	int ans = 0;
	queue<pair<int, int>> q;
	q.push({0, n-1});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int left = p.first, right = p.second;
		if(left > right) continue;
		
		int mn = inf_int;
		vector<int> v;
		for(int x=left;x<=right;x++){
			if(data[x] < mn) v.clear();
			mn = min(mn, data[x]);
			if(data[x] == mn) v.push_back(x);
		}
		
		ans = max(ans, (right-left+1)*mn);
		
		for(int x=0;x<v.size();x++){
			if(x == v.size()-1){
				if(v[x]+1 <= right) q.push({v[x]+1, right});
			}
			if(x == 0){
				if(v[x]-1 >= left) q.push({left, v[x]-1});
			}
			if(x+1 < v.size()){
				if(v[x]+1 <= v[x+1]-1){
					q.push({v[x]+1, v[x+1]-1});
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

