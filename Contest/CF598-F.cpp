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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s, t;
		cin >> s >> t;
		
		int cnt[27];
		fill(cnt, cnt+27, 0);
		
		bool valid = true, two = false;
		for(int x=0;x<n;x++){
			cnt[(s[x] - 'a')]++;
			if(cnt[(s[x] - 'a')] >= 2){
				two = true;
			}
		}
		for(int x=0;x<n;x++){
			cnt[(t[x] - 'a')]--;
		}
		for(int x=0;x<26;x++){
			if(cnt[x] != 0){
				valid = false;
				break;
			}
		}
		
		if(!valid){
			cout << "NO\n";
			continue;
		}
		if(two){
			cout << "YES\n";
			continue;
		}
		
		// N must be <= 26 with distinct characters, by PHP
		int x = 0, z = 1;
		while(x < n){
			int pos = x;
			for(int y=x;y<n;y++){
				if(t[y] == s[x]){
					pos = y;
					break;
				}
			}
			
			if(pos-x+1 > n-x-1){
				if(x+z+1 > n) break;
				if(n-z < x) break;
				
				reverse(s.begin()+x, s.begin()+x+z+1);
				reverse(t.end()-z-1, t.end());
				z++;
				continue;
			}
			
			reverse(s.end()-(pos-x+1), s.end());
			reverse(t.begin()+x, t.begin()+pos+1);
			x++;
			z = 1;
		}
		
		if(s == t){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

