#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	int k;
	cin >> n >> k;
	
	char ans = ('A' + ((k-1)/n));
	cout << ans << "\n";
    return 0;
}

