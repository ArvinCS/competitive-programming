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
	
	int a[n], b[n];
	bool use[n+1];
	fill(use, use+n+1, true);
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		use[b[x]] = false;
	}
	
	int start = 1, i = 0;
	int cnt1 = 0, cnt2 = 0;
	for(int x=n-1;x>=0;x--){
		if(b[x] == 0) break;
		if(x == 0){
			if(b[x] == 1){
				start = n-x+1;
				break;
			}	
		} else {
			if(b[x] == 1){
				start = n-x+1;
				break;
			} else if(b[x-1]+1 == b[x]){
				continue;
			} else {
				break;
			}
		}
	}
	
	for(int x=start;x<=n;x++){
		if(!use[x]){
			cnt1 = inf_int;
			break;
		}
		
		cnt1++;
		if(i < n){
			use[b[i++]] = true;
		}
	}
	
	i = 0;
	for(int x=0;x<n;x++){
		use[b[x]] = false;
	}
	
	for(int x=1;x<=n;x++){
		if(!use[x]){
			while(i < n && b[i] != x){
				use[b[i++]] = true;
				cnt2++;
			}
			if(i < n){
				use[b[i++]] = true;
				cnt2++;
			}
		}
		
		cnt2++;
		if(i < n){
			use[b[i++]] = true;
		}
	}
	cout << min(cnt1, cnt2) << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

