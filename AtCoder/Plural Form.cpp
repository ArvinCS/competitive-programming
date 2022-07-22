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
	
	string s;
	cin >> s;
	
	int len = s.length();
	for(int x=0;x<len;x++){
		cout << s[x];
		if(x+1 == len){
			if(s[len-1] == 's'){
				cout << "e";
			} 
			cout << "s";
		}
	}
	cout << "\n";
	
    return 0;
}

