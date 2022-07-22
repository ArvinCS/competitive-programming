#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int lastZero = 0;
		for(int x=n-1;x>=0;x--){
			if(s[x] == '0'){
				lastZero = x;
				break;
			}
		}

		bool passedOne = false;
		for(int x=0;x<n;x++){
			if(s[x] == '0' && !passedOne){
				cout << s[x];
				continue;
			}
			if(s[x] == '1') passedOne = true;
			if(x >= lastZero){
				cout << s[x];
			}
		}
		cout << "\n";
	}
	
    return 0;
}

