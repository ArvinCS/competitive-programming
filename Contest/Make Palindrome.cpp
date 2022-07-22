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
	
	string s;
	cin >> s;
	
	int a[26];
	fill(a, a+26, 0);
	
	for(int x=0;x<s.length();x++){
		a[s[x]-'a']++;
	}
	
	vector<int> v;
	for(int x=0;x<26;x++){
		if(a[x]&1){
			v.push_back(x);
		}
	}
	
	int left = 0, right = v.size()-1;
	while(left < right){
		a[v[left++]]++;
		a[v[right--]]--;
	}

	int index = 0, cnt = 0;
	char ans[s.length()];
	
	if(left == right){
		ans[s.length()/2] = ('a' + v[left]);
		a[v[left]]--;
	}
	
//	for(auto w : v){
//		char tmp = ('a' + w);
//		cout << tmp << " ";
//	}
//	cout << "\n";
	for(int x=0;x<26;x++){
		while(a[x] > 0){
			ans[index] = ('a' + x);
			ans[s.length()-1-index] = ('a' + x);
		
			a[x] -= 2;
			cnt++;
			index++;
		}
	}
	
	for(int x=0;x<s.length();x++){
		cout << ans[x];
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

