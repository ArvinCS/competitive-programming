#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	ll dist = a*1ll*a + b*1ll*b;
	
	cout << fixed << setprecision(7)<< 1.0/sqrt(dist) * a << " " << 1.0/sqrt(dist) * b << "\n";
	
    return 0;
}

