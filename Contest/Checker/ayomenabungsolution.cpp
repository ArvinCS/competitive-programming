#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int k, j, d;
	cin >> k >> j >> d;
	
	int a, b;
	cin >> a >> b;
	
	int x, y;
	cin >> x >> y;
	
	int q;
	cin >> q;
	
	int klee = (q-k+j+d-1)/(j+d);
	int dina = (q-a+b-1)/b;
	int kiki = (q-x+y-1)/y;
	
	if(klee < min(dina, kiki)){
		cout << "TIDAK\n";
	} else {
		cout << "YA\n";
	}
}
