#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	for(int x=1;x<=n*a;x++){
		for(int y=1;y<=n*b;y++){
			int c = ((x-1)/a) % 2;
			int d = ((y-1)/b) % 2;
			
			if((c^d) == 1){
				cout << "#";
			} else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	
    return 0;
}

