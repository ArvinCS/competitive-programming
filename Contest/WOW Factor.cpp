#include <iostream>

using namespace std;

long long solve(string s){
	long long int a = 0,b = 0,c = 0;
	for(int x=0;x<s.length();x++){
		if(s[x] == 'o'){
			b += a;
		} else if(x > 0 && s[x-1] == 'v') {
			a++;
			c += b;
		} 
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	cout << solve(s) << "\n";
    return 0;
}
