#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	
	if(x <= a){
		cout << "1\n";
	} else if(x <= b){
		cout << fixed << setprecision(7) << c*1.0/(b-a) << "\n";
	} else {
		cout << "0\n";
	}
	
    return 0;
}

