#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	
	if(a > c) swap(a, c);
	if(a <= b && b <= c){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

    return 0;
}

