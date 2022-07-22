#include <iostream>

using namespace std;

string s;
short memoization[51][51];
short solve(short i, short e){
	if(i > e) return 0;
	if(i == e) return 1;
	if(memoization[i][e] != -1) return memoization[i][e];
	
	if(s[i-1] == s[e-1]){
		memoization[i][e] = 2 + solve(i+1, e-1);
	} else {
		memoization[i][e] = max(solve(i+1, e) , solve(i, e-1) );	
	}
	return memoization[i][e];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n;
	cin >> n;
	
	while(n--){
		cin >> s;
		fill(&memoization[0][0], &memoization[0][0]+51*51, (short) -1);
		cout << solve(1, s.length()) << "\n";
	}
    
	return 0;
}
