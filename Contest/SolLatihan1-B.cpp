#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	
	// Cukup jelas, tinggal diubah menjadi sebuah rumus saja.
	if(n > a){
		cout << a*x + (n-a)*y << "\n";
	} else {
		cout << n*x << "\n";
	}
    return 0;
}

