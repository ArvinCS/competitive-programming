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

const int maxN = 2e5 + 5;

ll cache[maxN];

int ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

void ans(int x){
	cout << "! " << x << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(cache, cache+maxN, -1);
	
	int n, t;
	cin >> n >> t;
	
	for(int i=0;i<t;i++){
		int m;
		cin >> m;
		
		ll cnt = 0;
		for(int x=1;x<=n;x+=32){
			ll y = min(x+31, n);
			
			ll tmp = (cache[x] != -1 ? cache[x] : ask(x, y));
			cache[x] = tmp;
			if(cnt+(y-x+1-tmp) >= m){
				cache[x]++;
				ll left = x, right = y;
				
				while(left <= right){
					if(left == right){
						ans(left);
						break;
					}
					ll mid = (left+right) >> 1;
					
					int a = ask(left, mid);
					if(cnt+(mid-left+1-a) < m){
						cnt += (mid-left+1-a);
						left = mid+1;
					} else {
						right = mid;
					}
				}
				break;
			}
			cnt += (y-x+1-tmp);
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

