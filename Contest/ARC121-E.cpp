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
	p[0] = 0;
	for(int x=1;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	
	
    return 0;
}

