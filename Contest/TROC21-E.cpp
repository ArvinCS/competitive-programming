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
	cin >> n;
	
	bool empty[n];
	fill(empty, empty+n, true);
		
	int data[n];
	bool right[n];
	for(int x=0;x<n;x++){
		cin >> data[x] >> right[x];
		data[x]--;
	}
	
	set<int> slot;
	for(int x=0;x<n;x++){
		slot.insert(x);
	}
	
	int ans[n];
	for(int x=n-1;x>=0;x--){
		if(slot.count(data[x])){
			slot.erase(slot.find(data[x]));
			ans[x] = 0;
		} else {
			if(right[x]){
				auto nxt = slot.lower_bound(data[x]);
				if(nxt == slot.end()){
					nxt = slot.lower_bound(0);
				}
				ans[x] = (*nxt + n - data[x]) % n;
				slot.erase(nxt);
			} else {
				auto nxt = slot.lower_bound(data[x]);
				if(nxt == slot.begin()){
					nxt = slot.upper_bound(n);
				}
				nxt--;
				ans[x] = (data[x] + n - *nxt) % n;
				slot.erase(nxt);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

