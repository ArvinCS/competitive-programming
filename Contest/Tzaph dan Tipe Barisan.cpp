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
	
	short n;
	cin >> n;
	
	short before, inc = 0, dec = 0;
	cin >> before;
	for(short x=1;x<n;x++){
		short tmp;
		cin >> tmp;
		
		if(before < tmp){
			inc++;
		} else if(before > tmp){
			dec++;
		}
		before = tmp;
	}
	
	if(inc == 0 && dec == 0){
		cout << "EQUAL\n";
	} else if(inc > 0 && dec > 0){
		cout << "NONE\n";
	} else if(inc > 0){
		cout << "NONDECREASING\n";
	} else if(dec > 0){
		cout << "NONINCREASING\n";
	}
	
    return 0;
}

