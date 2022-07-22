#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int out[n];
	fill(out, out+n, 0);
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		out[a]++; out[b]++;
	}
	
	bool valid = false;
	for(int x=0;x<n;x++){
		if(out[x] == n-1) valid = true;
	}
	
	cout << (valid ? "Yes" : "No") << "\n";
    return 0;
}

