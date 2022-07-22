#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int l, r;
	cin >> l >> r;
	
	string s;
	cin >> s;
	
	l--; r--;
	for(int x=0;x<l;x++){
		cout << s[x];
	}
	for(int x=r;x>=l;x--){
		cout << s[x];
	}
	for(int x=r+1;x<s.length();x++){
		cout << s[x];
	}
	cout << "\n";
    return 0;
}

