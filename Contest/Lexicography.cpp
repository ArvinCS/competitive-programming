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
	
	int n, l, k;
	cin >> n >> l >> k;
	
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	vector<char> ans[n];

	int checkpoint = 0, index = 0;
	for(int x=0;x<k;x++){
		ans[x].push_back(s[index++]);
		if(x > 0 && ans[x].back() > ans[x-1].back()){
			checkpoint = x;
		}
	}
	
//	cout << "cp: " << checkpoint << "\n";
	int tmp = checkpoint;
	for(int x=k;x<l*k;x++){
		if(ans[tmp].size() < l){
			ans[tmp].push_back(s[index++]);
			if(tmp > checkpoint && ans[tmp].back() > ans[tmp-1].back()){
				checkpoint = tmp;
			}
		}
		tmp++;
		if(tmp >= k) tmp = checkpoint;
	}

	for(int x=0;x<k;x++){
		for(int y=ans[x].size();y<l;y++){
			ans[x].push_back(s[index++]);
		}
	}
	
	for(int x=k;x<n;x++){
		for(int y=ans[x].size();y<l;y++){
			ans[x].push_back(s[index++]);
		}
	}
	
	sort(ans, ans+n);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<l;y++){
			cout << ans[x][y];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

