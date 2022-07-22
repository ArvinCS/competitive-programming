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

	int n, q;
	cin >> n >> q;
	
	int data[n], one = 0;
	for(int x=0;x<n;x++){
		cin >> data[x];
		if(data[x] == 1) one++;
	}
	
	for(int x=0;x<q;x++){
		int t, p;
		cin >> t >> p;
		if(t == 1){
			if(data[p-1] == 1){
				one--;
				data[p-1] = 0;
			} else {
				one++;
				data[p-1] = 1;
			}
		} else {
			if(p > one){
				cout << "0\n";
			} else {
				cout << "1\n";
			}
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

