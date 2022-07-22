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
	
	vector<int> primes;
	
	for(int x=0;x<maxA;x++) prime[x] = x;
	for(int x=2;x*1ll*x<maxA;x++){
		if(prime[x] == x){
			primes.push_back(x);
			for(int y=x+x;y<maxA;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	pair<int, int> ans[n];
	for(int i=0;i<n;i++){
		int cur = data[i];
		
		ans[i].first = -1;
		ans[i].second = -1;
		
		if(prime[cur] == cur) continue;
		
		int a = 1;
		int div = prime[cur];
		while(cur % div == 0){
			a *= div;
			cur /= div;
		}
		
		if(cur > 1){
			ans[i].first = a;
			ans[i].second = cur;
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x].first;
	}
	cout << "\n";
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x].second;
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


