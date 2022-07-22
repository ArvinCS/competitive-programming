#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	double p;
	cin >> p;
	
	if(p == 0){
		cout << "0\n";
	} else {
		p /= 100.0;
		cout << setprecision(9) << fixed << p / (1 - ((1-p) * (1-p))) << "\n";
	}
    return 0;
}

