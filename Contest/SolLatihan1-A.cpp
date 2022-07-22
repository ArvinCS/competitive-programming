#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	// sudah jelas, cuma logika if aja.
	if(a == 0){
		cout << "Silver\n";
	} else if(b == 0){
		cout << "Gold\n";
	} else {
		cout << "Alloy\n";
	}
	
    return 0;
}

