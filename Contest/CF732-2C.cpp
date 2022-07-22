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

const int maxN = 1e5 + 5;

int freq[maxN][2];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		fill(freq[0], freq[maxN], 0);
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			freq[a[x]][x%2]++;
		}
		
		sort(a, a+n);
		bool possible = true;
		
		for(int x=0;x<n;x++){
			freq[a[x]][x%2]--;
			if(freq[a[x]][x%2] < 0){
				possible = false;
				break;
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

