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
		int a, b;
		cin >> a >> b;
		
		int n = a+b;
		vector<int> ans;
		
		for(int x=0;x<=n;x++){
			// case 1 (alice first)
			int cnt1 = min((n+1)/2, a), cnt2 = min(n/2, b);
			int remain = max((n+1)/2 - cnt1, 0) + max(n/2 - cnt2, 0);
			if(remain <= x){
				if((x-remain) % 2 == 0 && (x-remain)/2 <= min(cnt1, cnt2)){
					ans.push_back(x);
					continue;
				}	
			}
			
			// case 2 (borys first)
			cnt1 = min((n+1)/2, b); cnt2 = min(n/2, a);
			remain = max((n+1)/2 - cnt1, 0) + max(n/2 - cnt2, 0);
			if(remain <= x){
				if((x-remain) % 2 == 0 && (x-remain)/2 <= min(cnt1, cnt2)){
					ans.push_back(x);
					continue;
				}
			}
		}
		
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}

