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
const int lgN = log2(maxN)+1;

ll table[lgN+2][maxN];

void build(int n, ll a[]){
	table[0][0] = 0;
	for(int x=1;x<n;x++){
		table[0][x] = abs(a[x]-a[x-1]);
	}	
	for(int x=1;x<=lgN;x++){
		int length = (1<<x);
		
		for(int y=0;y+length<=n;y++){
			table[x][y] = __gcd(table[x-1][y], table[x-1][y+length/2]);
		}
	}
}

ll query(int left, int right){
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return __gcd(table[lg][left], table[lg][right-length+1]);	
}

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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		build(n, a);
		
		int pos = 0, ans = 1;
		for(int x=1;x<n;x++){
			while(pos < x){
				if(query(pos+1, x) == 1){
					pos++;
				} else {
					break;
				}
			}
			
			ans = max(ans, x-pos+1);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

