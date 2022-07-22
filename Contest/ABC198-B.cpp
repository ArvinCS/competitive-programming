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
	
	string s;
	cin >> s;
	
	int left = 0, right = s.length()-1;
	for(int x=s.length()-1;x>=0;x--){
		if(s[x] != '0'){
			right = x;
			break;
		}
	}
	
	while(left < right){
		if(s[left] != s[right]){
			cout << "No\n";
			return 0;
		}
		left++;
		right--;
	}
	cout << "Yes\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

