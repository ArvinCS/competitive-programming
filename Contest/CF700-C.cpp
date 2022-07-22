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
	
	int left = 1, right = n;
	while(left <= right){
		int mid = (left+right)/2;
		
		if(left == right){
			cout << "! " << left << endl;
			return 0;
		}
		if(ask(mid) < ask(mid+1)){
			right = mid;
		} else {
			left = mid+1;
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

