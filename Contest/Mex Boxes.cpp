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
	
	int n, k;
	cin >> n >> k;
	
	int data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	sort(data, data+n);
	
	int box[k];
	fill(box, box+k, 0);
	
	int curK = 0;
	for(int x=0;x<n;x++){
		if(box[curK] == data[x]){
			box[curK]++;
			curK++;
		} else {
			curK = 0;
			if(box[curK] == data[x]){
				box[curK]++;
				curK++;
			}
		}
	}
	
	ull ans = 0;
	for(int x=0;x<k;x++){
		ans += box[x];
	}
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

