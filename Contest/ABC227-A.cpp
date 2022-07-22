#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k, a;
	cin >> n >> k >> a;
	
	k = (k-1+n)%n;
	
	cout << (a+k-1)%n + 1 << "\n";
	
    return 0;
}

