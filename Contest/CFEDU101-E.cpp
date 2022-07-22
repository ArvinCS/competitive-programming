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

const int maxN = 1e6 + 5;

int n, k;
char c[maxN], inv[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		int ln = ceil(log2(n-k+2));
		int m = min(k, ln);
		for(int x=0;x<n;x++){
			inv[x] = (c[x] == '0' ? '1' : '0');
		}
		
		int right[n];
		for(int x=n-1;x>=0;x--){
			right[x] = (x+1 < n ? right[x+1] : n);
			if(inv[x] == '1'){
				right[x] = x;
			}
		}
		
		set<int> st;
		int tmp = 0;
		for(int x=0;x<n;x++){
			int num = (inv[x] - '0');
			
			tmp |= num;
			
			if(x >= k-1){
				if(right[x-k+1] >= (x-k+1)+(k-m)){ // if first k-m characters no zeroes
//					cout << x << " " << tmp << "\n";
					st.insert(tmp);
				}
			}
					
			int bit = (tmp >> (m-1));
			tmp ^= (bit << (m-1));
			tmp <<= 1;
		}
		
		string ans;
		for(int x=0;x<k-m;x++){
			ans += '0';
		}
		
		bool possible = false;
		for(int x=0;x<(1 << m);x++){
			if(!st.count(x)){
				possible = true;
				for(int y=m-1;y>=0;y--){
					if((x&(1ll<<y))){
						ans += '1';
					} else {
						ans += '0';
					}
				}
				
				break;
			}
		}
		
		if(possible){
			cout << "YES\n";
			cout << ans << "\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
