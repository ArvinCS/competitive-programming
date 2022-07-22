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
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		map<int, int> mp;
		ui prefix[n];
		for(ui x=0;x<n;x++){
			us tmp = s[x] - '0';
			prefix[x] = tmp - 1;
			if(x > 0) prefix[x] += prefix[x-1];
		}
		
		ull ans = mp[0]++;
		for(ui x=0;x<n;x++){
			ans += mp[prefix[x]];
			mp[prefix[x]]++;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

