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

string balik(string s){
	string ans = s;
	for(int x=0;x*2<ans.length();x++){
		swap(ans[x], ans[ans.length()-1-x]);
	}	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, k;
	cin >> n >> k;
	
	if(n < k){
		for(int x=0;x<n;x++){
			char c = ('a' + x);
			cout << c;
		}
		cout << "\n";
		return 0;
	}
	
	string tmp;
	for(char x='a';x<('a'+k);x++){
		tmp += x;
		for(char y=x+1;y<('a'+k);y++){
			tmp += x;
			tmp += y;
		}
	}
	
	if(k == 1){
		tmp = "a";
	}
	
	string ans;
	int len = n;
	while(len > 0){
		if(len < tmp.length()){
			ans += tmp.substr(0, len);
			break;
		}
		ans += tmp;
		len -= tmp.length();
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

