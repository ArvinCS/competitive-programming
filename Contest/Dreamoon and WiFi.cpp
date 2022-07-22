#include <iostream>
#include <cmath>

using namespace std;

short faktorial(int n){
	if(n == 1) return 1;
	return n * faktorial(n-1);
}

short findCase(short n, short i, short t, short v){
	if(i >= n){
		return v == t;
	}
	short ans = 0;
	ans += findCase(n,i+1,t,v+1);
	ans += findCase(n,i+1,t,v-1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a,b;
	cin >> a >> b;
	
	short cntA = 0, cntB = 0, unknown = 0;
	for(int x=0;x<a.length();x++){
		if(a[x] == '+') cntA++;
		else if(a[x] == '-') cntA--;
		if(b[x] == '+') cntB++;
		else if(b[x] == '-') cntB--;
		else if(b[x] == '?') unknown++;
	}
	
	double ans = 0;
	if(unknown == 0){
		if(cntA == cntB) ans++;
	} else {
		short diff = cntA - cntB;
		if(-unknown <= cntA-cntB && cntA-cntB <= unknown){
			double total = pow(2, unknown);
			ans = findCase(unknown, 0, diff, 0) / total;
		}
	}
	
	cout.precision(12);
	cout << fixed << ans << "\n";
    return 0;
}
