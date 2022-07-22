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

const int maxN = 5e5 + 5;

int prime[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxN;x++){
		prime[x] = x;
	}
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=2*x;y<maxN;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	int n;
	cin >> n;
	
	vector<int> v;
	for(int x=1;x<=n;x++){
		v.push_back(x/prime[x]);
	}
	
	sort(v.begin(), v.end());
	
	for(int x=1;x<n;x++){
		if(x > 1) cout << " ";
		cout << v[x];
	}
	cout << "\n";
    return 0;
}

