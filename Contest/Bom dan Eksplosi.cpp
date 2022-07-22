#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	short n,m,r,q;
	cin >> n >> m >> r;

	q = ((n > m ? m : n) + 2 * r) / (2 * r + 1);
    cout << q << "\n";
	return 0;
}
