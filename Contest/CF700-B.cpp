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

int ask(int x){
	int ans;
	cout << "? " << x << endl;
	cin >> ans;
	
	return ans;
}

int 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	if(n == 1){
		cout << "! 1" << endl;
		return 0;
	}
	
	int ans = -1;
	int bef = ask(1), bef2 = ask(2), bef3 = ask(3);
	
	if(bef < bef2){
		cout << "! 1" << endl;
		return 0;
	}
	if(bef1 > bef2 && bef2 < bef3){
		cout << "! 2" << endl;
		return 0;
	}
	bef = ask(n/2), bef2 = ask((n+1)/2);
	
	if(bef == 1){
		cout << "! " << n/2 << endl;
		return 0;
	}
	
	if(bef2 == 1){
		cout << "! " << (n+1)/2 << endl;
	}
	
	if(ask(n/2-1) > bef && bef < bef2){
		cout << "! " << n/2 << endl;
		return 0;
	}
	
	if(bef > bef2 && bef2 < ask((n+1)/2+1)){
		cout << "! " << (n+1)/2 << endl;
		return 0;
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

