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
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		vector<string> a;
		
		for(int x=0;x<k;x++){
			string tmp;
			tmp += s[x];
			
			a.push_back(tmp);
		}
		
		for(int x=k;x<n;x++){
			bool found = false;
			for(int y=1;y<k;y++){
				string tmp = a[y];
				tmp += s[x];
				
				cout << tmp << "\n";
				if(a[0].compare(tmp) > 0){
					a[y] += s[x];
					found = true;
					break;
				}
			}
			
			if(!found){
//				a[0] += s[x];
			}
		}
//		
//		string ans = a[0];
//		for(int x=1;x<k;x++){
//			if(ans.compare(a[x]) < 0){
//				ans = a[x];
//			}
//		}
//		
//		cout << ans << "\n";
	}
	
    return 0;
}

