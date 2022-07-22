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
char data[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){		
		int n;
		cin >> n;
		
		char data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int index = 0;
		ll a = 0, b = 0;
		while(index < n-1){
			if(data[index] == data[index+1]){
				if(data[index] == '0') a++;
				else b++;
			}
			index++;
		}
		cout << max(a,b) << "\n";
	}
	
    return 0;
}

