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

	int n, k;
	cin >> n >> k;
	
	vector<int> v[n+1];
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		
		v[a[x]].push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	for(auto p : v){
		cout << p.first << " " << p.second << "\n";
	}
	
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			cout << x << " " << y << " -> " << (x+1)*(y+1) - k*(a[x]|a[y]) << "\n"; 
		}
	}
    return 0;
}

