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

bool exist[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	fill(exist, exist+n+1, false);
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		exist[data[x]] = true;
	}
	
	int ans[n], smallest[n];
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		if(x == 0 || data[x] == data[x-1]){
			ans[x] = (x > 0 ? ans[x-1]+1 : 0);
			while(exist[ans[x]]) ans[x]++;
		} else {
			ans[x] = data[x-1];
			smallest[x]++;
		}
		exist[ans[x]] = true;
		
		cout << ans[x];
	}
	cout << "\n";
	
    return 0;
}

