#include <bits/stdc++.h>

using namespace std;

#define ll long long

const double PI = atan(1)*4;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		ll a, b;
		cin >> a >> b;
		
		double h = sqrt((a+b)*1.0*(a+b) - (4.0*a*a/3));
		double ans = a + h + b; 
		cout << "Case #" << i << ": " << fixed << setprecision(5) << ans << "\n";
	}

    return 0;
}

