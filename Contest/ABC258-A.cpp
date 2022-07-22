#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int k;
	cin >> k;
	
	cout << (21+(k/60)) << ":" << (k%60 < 10 ? 0 : k/10) << (k%10) << "\n";
	
    return 0;
}

