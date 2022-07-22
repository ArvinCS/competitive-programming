#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(floor(sqrt(n)) == ceil(sqrt(n))){
			cout << "lampu menyala\n";	
		} else {
			cout << "lampu mati\n";
		}
	}
	
	return 0;
}
