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

vector<int> must, maybe;
bool contain[10];

ll solve(int idx, bool ok[]){
	if(idx >= 4){
		bool valid = true;
		for(auto i : must){
			if(!ok[i]){
				valid = false;
				break;
			}
		}
		
		return valid;
	}
	
	ll ans = 0;
	for(int x=0;x<10;x++){
		if(!contain[x]) continue;
		
		bool bef = ok[x];
		ok[x] = true;
		ans += solve(idx+1, ok);
		ok[x] = bef;
	}
	
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	string s;
	cin >> s;
	
	for(int x=0;x<10;x++){
		if(s[x] == 'o'){
			must.push_back(x);
			contain[x] = true;
		} else if(s[x] == '?'){
			maybe.push_back(x);
			contain[x] = true;
		} else {
			contain[x] = false;
		}
	}
	
	bool ok[10];
	fill(ok, ok+10, false);
	
	cout << solve(0, ok) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

