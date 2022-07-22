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
//	freopen("weak_typing_chapter_2_input.txt","r",stdin);
//	freopen("weak_typing_chapter_2_output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		vector<pair<char, int>> v;
		for(int x=0;x<n;x++){
			if(s[x] != 'F'){
				v.push_back({s[x], x});
			}
		}
		
		ll ans = 0;
		for(int x=0;x+1<v.size();x++){
			if(v[x].first != v[x+1].first){
				ans += (v[x].second+1)*1ll*(n-v[x+1].second) % mod;
				ans %= mod;
			}
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

