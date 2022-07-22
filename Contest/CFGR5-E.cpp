#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	
	bool possible = false;
	
	int cur = 1;
	while(cur <= n){
		if(n == cur || n == cur+1){
			possible = true;
			break;
		}
		
		if(cur % 2 == 0){
			cur = 2*cur+1;
		} else {
			cur = 2*cur+2;
		}
	}
	
	if(possible){
		cout << "1\n";
	} else {
		cout << "0\n";
	}
    return 0;
}

