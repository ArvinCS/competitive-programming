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

int highestBit(int n){
	int ans = -1;
	for(int x=0;x<32;x++){
		int bit = (1 << x);
		if(n&bit){
			ans = x;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v[32];
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		v[highestBit(data[x])].push_back(x);
	}
	
	for(int x=0;x<32;x++){
		if(v[x].size() > 2){
			cout << "1\n";
			return 0;
		}
	}
	
	int prefix[n];
	prefix[0] = data[0];
	for(int x=1;x<n;x++){
		prefix[x] = (data[x]^prefix[x-1]);
	}
	
	int ans = inf_int;
	for(int x=0;x<n;x++){
		for(int y=x;y<n;y++){
			for(int z=y+1;z<n;z++){
				int left = prefix[y]^(x > 0 ? prefix[x-1] : 0);
				int right = prefix[z]^prefix[y];
				
				if(left > right){
					ans = min(ans, (y-x) + (z-y-1));
				}
			}
		}
	}
	if(ans == inf_int) cout << "-1\n";
	else cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

