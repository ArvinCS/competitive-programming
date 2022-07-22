#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 1e9 + 7;

int n, p;
int a[maxN];
ll fib[maxN], table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fib[0] = fib[1] = 1;
	table[0] = 1;
	table[1] = 2;
	for(int x=2;x<maxN;x++){
		fib[x] = (fib[x-1] + fib[x-2]) % mod;
		table[x] = (table[x-1] + fib[x]) % mod;
	}
	
	cin >> n >> p;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	set<int> st;
	ll ans = 0;
	for(int x=0;x<n;x++){
		bool pass = false;
		int msb = log2(a[x]);
		
		int cur = a[x];
		while(cur > 0){
			if(st.count(cur)){
				pass = true;
			}
			if(cur % 4 == 0){
				cur /= 4;
			} else if(cur % 2 == 1){
				cur /= 2;
			} else {
				break;
			}
		}
		if(cur > 0 && st.count(cur)){
			pass = true;
		}
			
		if(!pass){
			ans += (p-msb-1 >= 0 ? table[p-msb-1] : 0);
			st.insert(a[x]);
		}
		
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

