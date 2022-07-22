#include <iostream>

using namespace std;

string toBiner(long long a){
	string ans;
	while(a != 0){
		ans.insert(0, to_string(a % 2));
		a /= 2;
	}
	if(ans.length() == 0) ans.append("0");
	return ans;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	long long n;
	cin >> n;
	
	long long dec = n * (n-1);
	cout << toBiner(dec) << "\n";
    return 0;
}
