#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	cout << "AGC0";
	if(n >= 42){
		cout << n+1 << "\n";
	} else {
		if(n < 10) cout << "0";
		cout << n << "\n";
	}
	
    return 0;
}

