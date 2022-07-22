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
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		bool valid[4*n+1];
		fill(valid, valid+4*n+1, true);
		
		vector<int> ans;
		int cnt = n;
		for(int x=n*2;x<=4*n;x+=2){
			if(valid[x]){
				ans.push_back(x);
				cnt--;
				for(int y=x+x;y<=4*n;y+=x){
					valid[y] = false;
				}
			}
			if(cnt == 0) break;
		}
		
//		cout << ans.size() << " : ";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

