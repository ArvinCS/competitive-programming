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
		
		map<int, int> mp;
		mp[0] = -1;
		int cnt = 0, ans1 = -2, ans2 = -2;
		for(int x=0;x<n;x++){
			char c;
			cin >> c;
			
			if(c == 'a'){
				cnt++;
			} else {
				cnt--;
			}
			
			if(mp.find(cnt) != mp.end()){
				ans1 = mp[cnt]+1;
				ans2 = x;
			}
			mp[cnt] = x;
		}
			
		cout << ans1+1 << " " << ans2+1 << "\n";
	}
	
    return 0;
}

