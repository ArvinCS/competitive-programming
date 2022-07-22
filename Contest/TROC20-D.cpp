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
	
	int data[n], ones = 0;
	for(int x=0;x<n;x++){
		cin >> data[x];
		ones += data[x];
	}

	if(n <= 4){
		cout << "YES\n";
	} else {
		int part = 1;
		for(int x=0;x<n-1;x++){
			if(data[x] != data[x+1]){
				part++;
			}
		}
		
		if(part <= 3){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

