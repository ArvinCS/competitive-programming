#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	
	for(int x=0;x<n;x++){
		if(p[x] == 0){
			if(p[(x+1)%n] == 1){
				cout << min(x, 2+n-x) << "\n";
			} else {
				cout << min(n-x, 2+x) << "\n";	
			}
			
			break;
		}	
	}
    return 0;
}

