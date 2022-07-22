#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	bool picked[2*n+2];
	fill(picked, picked+2*n+2, false);
	
	int cur = 1;
	while(true){
		while(cur <= 2*n+1 && picked[cur]) cur++;
		
		cout << cur << endl;
		picked[cur++] = true;
		
		int res;
		cin >> res;
		if(res == 0) break;
		picked[res] = true;
	}
    return 0;
}

