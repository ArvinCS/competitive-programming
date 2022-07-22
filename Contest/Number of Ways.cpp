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
	
	int n;
	cin >> n;
	
	ll prefix[n];
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp;
		
		prefix[x] = tmp;
		if(x > 0) prefix[x] += prefix[x-1];
	}
	
	if(n < 3 || prefix[n-1] % 3 != 0){
		cout << "0\n";
	} else {
		ll a = 0, b = 0, bagA = prefix[n-1]/3, bagB = bagA*2;
		for(int x=0;x<n-1;x++){
			if(prefix[x] == bagB){
				b += a;
			}
			if(prefix[x] == bagA){
				a++;
			}
		}
		cout << b << "\n";
	}
	
    return 0;
}

