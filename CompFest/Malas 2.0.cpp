#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, m;
	cin >> n >> m;
	
	ull data[n+1], bit[n+1], tmp;
	
	for(ui x=1;x<=n;x++){
		data[x] = 0;
		bit[x] = 0;
	}
	
	for(ui x=1;x<=n;x++){
		cin >> data[x];
		bit[x] += data[x];
		ui y = x + (x & (-x));
		if(y <= n){
			bit[y] += bit[x];
		}
	}

	while(m--){
		us t;
		ull a, b;
		cin >> t >> a >> b;
		if(t == 1){
			ull tmp = data[a];
			data[a] ^= b;
			bit[a] += data[a] - tmp;
			
			ui index = a + (a & (-a));
			while(index <= n){
				bit[index] += data[a] - tmp;
				index += index & (-index);
			}
		} else {
			ui index = b;
			ull ans = 0;
			while(index > 0){
				ans += bit[index];
				index -= index & (-index);
			}
			index = a-1;
			while(index > 0){
				ans -= bit[index];
				index -= index & (-index);
			}
			cout << ans << "\n";
		}
	}
    return 0;
}

