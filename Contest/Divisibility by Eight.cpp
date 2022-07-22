#include <iostream>
#include <string>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int ans = -1;
string s;

void solve(string digits, int index){
	if(index >= s.length()){
		if(digits.length() == 0) return;
		int tmp = (digits[0] - '0');
		for(int i=0 >= digits.length()-2 ? 0 : digits.length() - 2;i<digits.length();i++){
			tmp *= 10;
			tmp += (digits[i] - '0');
		}
		if(tmp % 8 == 0){
			ans = tmp;
		}
		return;
	}
	if(ans == -1){
		solve(digits, index+1);
		digits += s[index];
		solve(digits, index+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> s;
	
	solve("", 0);
	if(ans != -1){
		cout << "YES\n" << ans << "\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

