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

const int maxN = 3e3 + 5;

ll table[maxN][maxN];

string s, t;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> s >> t;
	
	reverse(s.begin(), s.end());
	
	fill(table[0], table[maxN], 0);
	table[0][0] = 1;
	
	// Observations:
	// If we put the string in reverse order, it will take leftmost/rightmost empty pos
	// So, there are 2 cases:
	// First, we put it on left or right most empty pos
	// Second, we can skip if and only if the leftmost empty pos is still 0, and current string is skippable i.e x < s.length() - t.length().
	// So, we do basic DP with those 2 cases
	// The answer is sum of last step of the dp.
	
	for(int x=0;x<s.length();x++){
		for(int y=0;y<=x;y++){
			int z = x-y;
			
			if(y >= t.length() || s[x] == t[y]){
				table[y+1][z] += table[y][z];
				table[y+1][z] %= smod;
			}
			
			if(s.length()-1-z >= t.length() || s[x] == t[s.length()-1-z]){
				table[y][z+1] += table[y][z] + (y == 0 && x < s.length()-t.length());
				table[y][z+1] %= smod;
			}
		}
	}
	
	ll ans = 0;
	for(int y=0;y<=s.length();y++){
		int z = s.length()-y;
		
		ans += table[y][z];
		ans %= smod;
	}
	
	cout << ans << "\n";
    return 0;
}

