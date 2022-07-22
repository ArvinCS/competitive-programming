#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	string s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	int t;
	cin >> t;
	
	for(int x=0;x<t;x++){
		cout << "Nama saya " << s[x%n] << "\n";
	}
	return 0;
}
