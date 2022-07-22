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

	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int mx[27], ans[n];
	fill(mx, mx+27, 0);
	fill(ans, ans+n, -1);
	
	int comp = 0;
	for(int x=0;x<n;x++){
		int val = 0;
		for(int y=(s[x] - 'a')+1;y<26;y++){
			val = max(val, mx[y]);
		}
		
		ans[x] = val+1;	
		comp = max(comp, ans[x]);
		mx[(s[x] - 'a')] = max(mx[(s[x] - 'a')], val+1);
	}
	
	cout << comp << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

