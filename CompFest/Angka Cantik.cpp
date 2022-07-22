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
	
	short n;
	ui m;
	cin >> n >> m;
	
	ll s = 0, len = pow(10, n);
	for(int x=0;x<n;x++){
		short tmp;
		cin >> tmp;
		
		s *= 10;
		s += tmp;
	}
	
	unordered_map<ull, vector<ull>> mods;
	mods[s % m].push_back(s);
	
	ll ans = 0, currentS = s;
	while(true){
		currentS *= len;
		currentS += s;
		cout << currentS << "\n";
		ull sisa = currentS % m;
		if(mods[sisa].size() != 0){
			ans = currentS - mods[sisa][0];
			break;
		}
		mods[sisa].push_back(currentS);
	}
	
	cout << ans << "\n";
    return 0;
}

