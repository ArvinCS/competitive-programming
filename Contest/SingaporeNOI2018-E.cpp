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

	int n;
	ll h;
	cin >> n >> h;
	
	ll s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	priority_queue<ll> left;
	priority_queue<ll, vector<ll>, greater<ll>> right;
	ll low = 0, high = 0;
	ll ans = 0;
	
	left.push(s[0]); right.push(s[0]);
	for(int x=1;x<n;x++){
		low += h, high -= h;
		
		if(s[x] > right.top()-high){
			ans += s[x]-(right.top()-high);
			
			left.push(right.top()-high+low);
			
			right.pop();
			right.push(s[x]+high);
			right.push(s[x]+high);
		} else if(s[x] < left.top()-low){
			ans += (left.top()-low)-s[x];
			
			right.push(left.top()-low+high);
			cout << "added right " << left.top()-low+high << "\n";
			left.pop();
			left.push(s[x]+low);
			left.push(s[x]+low);
			
			cout << "added left 2x " << s[x]+low << "\n";
		} else {
			left.push(s[x]+low);
			right.push(s[x]+high);
		}
		cout << x << " -> " << ans << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

