#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	if(abs(a-b) == 1 || (min(a, b) == 1 && max(a, b) == 10)){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
    return 0;
}

