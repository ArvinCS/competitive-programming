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

ll ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	
	ll ans;
	cin >> ans;
	
	return ans;
}

void answer(int x){
	cout << "! " << x << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int left = 1, right = n;
	while(left < right){
		if(right-left == 1){
			answer(ask(left,right) == right ? left : right);
			return 0;
		}
		int smax = ask(left, right);
		int mid = (left+right) >> 1;
	
		if(smax < mid){
			if(ask(left, mid) == smax){
				right = mid;
			} else {
				left = mid;
			}
		} else {
			if(ask(mid, right) == smax){
				left = mid;
			} else {
				right = mid;
			}
		}
	}
	
	answer(right);
    return 0;
}

// Santai
// Pikirin dengan benar-benar

