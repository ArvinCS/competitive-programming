#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cout << 40 <<" " << 40 << "\n";
	for(int x=1;x<=10;x++){
		if(x > 1) cout << " ";
		int val = x-1;
		cout << 2*val+1 << " " << 2*val+2 << " " << 2*val+1 << " " << 2*val+2;
	}cout << "\n";
	for(int x=1;x<=10;x++){
		if(x > 1) cout << " ";
		int val = x-1;
		cout << 2*val+2 << " " << 2*val+1 << " " << 2*val+1 << " " << 2*val+2;
	}cout << "\n";
	
	cout << 10 << "\n";
	for(int x=1;x<=10;x++){
		if(x > 1) cout << " ";
		cout << x;
	}
	cout << "\n";
    return 0;
}

