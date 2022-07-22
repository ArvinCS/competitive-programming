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

pair<int, int> findMax(int start, int end, int data[]){
	pair<int, int> ans = {start, data[start]};
	for(int x=start+1;x<=end;x++){
		if(data[x] > ans.second){
			ans.second = data[x];
			ans.first = x;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int ans[101];
		fill(ans, ans+101, -1);
		
//		pair<int, int> tmp = findMax(0, n-1, data);
//		ans[tmp.second] = 0;
		
		queue<tuple<int, int, int>> q;
		q.push(make_tuple(0, n-1, 0));
//		q.push(make_tuple(tmp.first+1, n-1, 0));
		
		while(!q.empty()){
			tuple<int, int, int> tup = q.front();
			q.pop();
			
			int left = get<0>(tup), right = get<1>(tup), depth = get<2>(tup);
			pair<int, int> tmp = findMax(left, right, data);
			
			ans[tmp.second] = depth;
			if(left <= tmp.first-1) q.push(make_tuple(left, tmp.first-1, depth+1));
			if(right >= tmp.first+1) q.push(make_tuple(tmp.first+1, right, depth+1));
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[data[x]];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

