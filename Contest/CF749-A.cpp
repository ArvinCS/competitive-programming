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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int sum = 0;
		vector<int> odd, even;
		for(int x=0;x<n;x++){
			sum += a[x];
			if(a[x]&1) odd.push_back(x);
			else even.push_back(x);
		}
		
		bool prime = true;
		for(int y=2;y*y<=sum;y++){
			if(sum%y == 0){
				prime = false;
				break;
			}
		}
		
		if(prime && odd.size() > 0) odd.pop_back();
		
		vector<int> ans;
		for(int x=0;x<odd.size();x++) ans.push_back(odd[x]);
		for(int x=0;x<even.size();x++) ans.push_back(even[x]);
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

