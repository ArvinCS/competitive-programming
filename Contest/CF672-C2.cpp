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

const int maxN = 3e5 + 5;

int a[maxN], n;
ll ans = 0;

void add(int x){
	if(x < 0 || x > n) return;
	if(a[x-1] < a[x] && a[x] > a[x+1]) ans += a[x];
	if(a[x-1] > a[x] && a[x] < a[x+1]) ans -= a[x];
}

void remove(int x){
	if(x < 0 || x > n) return;
	if(a[x-1] < a[x] && a[x] > a[x+1]) ans -= a[x];
	if(a[x-1] > a[x] && a[x] < a[x+1]) ans += a[x];
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
		int q;
		cin >> n >> q;
		
		ans = 0;
		
		a[0] = a[n+1] = 0;
		for(int x=1;x<=n;x++){
			cin >> a[x];
		}
				
		for(int x=1;x<=n;x++){
			if(a[x-1] > a[x] && a[x] < a[x+1]){
				ans -= a[x];
			} else if(a[x-1] < a[x] && a[x] > a[x+1]){
				ans += a[x];
			}
		}
		
		cout << ans << "\n";
		
		for(int x=0;x<q;x++){
			int left, right;
			cin >> left >> right;
						
			remove(left-1);
			remove(left);
			remove(left+1);
			
			if(left < right){
				if(left+1 != right-1 && left != right-1) remove(right-1);
				if(left+1 != right) remove(right);
				remove(right+1);
			}
			
			swap(a[left], a[right]);
			
			add(left-1);
			add(left);
			add(left+1);
			
			if(left < right){
				if(left+1 != right-1 && left != right-1) add(right-1);
				if(left+1 != right) add(right);
				add(right+1);
			}
			
			cout << ans << "\n";
		}
	}

    return 0;
}

