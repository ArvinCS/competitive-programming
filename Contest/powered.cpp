#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = ceil(log2(1e10));

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll p2[maxN+1];
	p2[0] = 1;
	for(int x=1;x<=maxN;x++){
		p2[x] = p2[x-1] * 2;
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		ll curr = data[0];
		int cnt[maxN], ans = 0;
		fill(cnt, cnt+maxN, 0);
		
		for(int x=1;x<n;x++){
			if(curr > data[x]){
				int pangkat = log2(curr - data[x]);
				ans = max(ans, pangkat+1);
				
				curr = max(curr, data[x]+p2[pangkat]);
			}
			curr = max(curr, data[x]);
		}
//		
//		for(int x=1;x<10;x++){
//			cout << cnt[x] << " ";
//		}
//		cout << "\n";
		
		cout << ans << "\n";
	}
	
    return 0;
}

