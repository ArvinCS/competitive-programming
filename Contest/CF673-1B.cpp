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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n], sum = 0;
		for(int x=0;x<n;x++){
			cin >> data[x];
			sum += data[x];
		}
		
		if(sum%n != 0){
			cout << "-1\n";
			continue;
		}
		
		vector<tuple<int, int, int>> ans;
		int need = sum/n;
		bool visited[n+1];
		fill(visited, visited+n+1, false);
		
		for(int x=2;x<=n;x++){
			if(data[x-1]/x > 0){
				int tmp = data[x-1]/x;
				
				if(tmp == 0) continue;
				ans.push_back(make_tuple(x, 1, tmp));
				data[x-1] -= tmp*x;
				data[0] += tmp*x;
				
				visited[x] = true;
			}
		}
		
		for(int x=2;x<=n;x++){
			if((!visited[x] && data[x-1]/x == 0) || data[x-1] > need){
				int tmp = (data[x-1]+x-1)/x * x - data[x-1];
				
				if(tmp == 0) continue;
				ans.push_back(make_tuple(1, x, tmp));
				data[x-1] += tmp;
				data[0] -= tmp;	
			}
			
			int tmp = data[x-1]/x;
			
			if(tmp == 0) continue;
			ans.push_back(make_tuple(x, 1, tmp));
			data[x-1] -= tmp*x;
			data[0] += tmp*x;
		}
		
		for(int x=2;x<=n;x++){
			int tmp = need-data[x-1];
			
			if(tmp == 0) continue;
			ans.push_back(make_tuple(1, x, tmp));
			data[x-1] += tmp;
			data[0] -= tmp;
		}
		
		cout << ans.size() << "\n";
		for(auto t : ans){
			cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

