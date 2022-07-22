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

const int maxA = 1e7 + 5;

int prime[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxA;x++) prime[x] = x;
	for(int x=2;x*x<maxA;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxA;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int data[n];
		fill(data, data+n, 1);
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			int cnt = 1, last = 1;
			while(tmp > 1){
//				cout << x << " -> " << tmp << " " << cnt << " " << last << "\n";
				int div = prime[tmp];
				if(div == last){
					cnt++;
				} else {
					if(cnt % 2 == 1) data[x] *= last;
					last = div;
					cnt = 1;
				}
				tmp /= div;
			}
			if(cnt % 2 == 1) data[x] *= last;
		}
		
		set<int> v[n];
		int idx = 0;
		
		for(int x=0;x<n;x++){
			if(v[idx].count(data[x])){
				if(k == 0){
					idx++;
				} else {
					k--;
				}
			}
			v[idx].insert(data[x]);
		}
		
		cout << idx+1 << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

