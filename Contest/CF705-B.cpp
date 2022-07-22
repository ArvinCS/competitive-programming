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

bool valid[10] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
int r[10] = {0, 1, 5, 0, 0, 2, 0, 0, 8, 0};

int flip(int x){
	if(x < 10){
		return x*10;
	}
	
	int ans = 0;
	while(x > 0){
		ans *= 10;
		ans += x%10;
		
		x /= 10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
		
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		int a = (s[0] - '0'), b = (s[1] - '0'), c = (s[3] - '0'), d = (s[4] - '0');
		bool possible = false;
		for(int x=a*10+b;x<n;x++){
			int start = (x == a*10+b ? c*10+d : 0);
			for(int y=start;y<m;y++){
				if(!valid[x/10] || !valid[x%10] || !valid[y/10] || !valid[y%10]) continue;
				int tmp1 = r[x%10]*10 + r[x/10], tmp2 = r[y%10]*10 + r[y/10];
				
				if(tmp1 < m && tmp2 < n){					
					if(x < 10) cout << "0";
					cout << x << ":";
					if(y < 10) cout << "0";
					cout << y << "\n";
					
					possible = true;
					break;
				}
			}
			if(possible) break;
		}
		
		if(possible) continue;
		cout << "00:00\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

