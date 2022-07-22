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
	
	int n;
	cin >> n;
	
	map<string, int> mp;
	vector<string> ask;
	for(int x=0;x<n;x++){
		string tmp;
		cin >> tmp;
		
		if(tmp[0] == '!'){
			ask.push_back(tmp.substr(1));
		} else {
			mp[tmp]++;
		}
	}

	for(int x=0;x<ask.size();x++){
		if(mp[ask[x]] >= 1){
			cout << ask[x] << "\n";
			return 0;
		}
	}
	
	cout << "satisfiable\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

