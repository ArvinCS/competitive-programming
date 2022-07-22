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
	
	int a, b;
	cin >> a >> b;
	
	int left = a, right = b;
	while(left <= right){
		int mid = (left+right)/2;
		cout << mid << endl;
		
		string s;
		cin >> s;
		
		if(s == "selamat"){
			return 0;
		} else {
			cin >> s;
			
			if(s == "kecil"){
				left = mid;
			} else {
				right = mid;
			}
		}
		
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

