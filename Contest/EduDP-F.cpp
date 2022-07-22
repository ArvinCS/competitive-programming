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

const int maxN = 3005;

ll table[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	string s, t;
	cin >> s >> t;
	
	for(int x=0;x<maxN;x++){
		table[x][0] = table[0][x] = 0;
	}
	
	for(int x=0;x<s.length();x++){
		for(int y=0;y<t.length();y++){
			if(s[x] == t[y]){
				table[x+1][y+1] = table[x][y] + 1;
			} else {
				table[x+1][y+1] = max(table[x+1][y], table[x][y+1]);
			}
		}
	}
	
	vector<char> ans;
	int left = s.length(), right = t.length();
	while(left > 0 && right > 0){
		if(table[left-1][right] == table[left][right]){
			left--;
			continue;
		}
		if(table[left][right-1] == table[left][right]){
			right--;
			continue;
		}
		
		ans.push_back(s[left-1]);
		left--;
		right--;
	}
	
	for(int x=ans.size();x>=1;x--){
		cout << ans[x-1];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

