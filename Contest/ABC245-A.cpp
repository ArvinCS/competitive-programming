#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if(a < c){
		cout << "Takahashi\n";
	} else if(a == c){
		if(b <= d){
			cout << "Takahashi\n";
		} else {
			cout << "Aoki\n";
		}
	} else {
		cout << "Aoki\n";
	}
	
    return 0;
}

