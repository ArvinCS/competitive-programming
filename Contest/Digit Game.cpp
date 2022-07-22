#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		string s;
		cin >> n >> s;
		
		vector<us> odd, even;
		if(n == 1){
			if((s[0] - '0') % 2 == 0){
				cout << "2\n";
			} else {
				cout << "1\n";
			}
		} else if(n % 2 == 0){
			for(us x=1;x<n;x+=2){
				short num = s[x] - '0';
				if(num % 2 == 0) even.push_back(num);
				else odd.push_back(num);
			}
			if(even.size() == 0){
				cout << "1\n";
			} else {
				cout << "2\n";
			}
		} else {
			for(us x=0;x<n;x+=2){
				short num = s[x] - '0';
				if(num % 2 == 0) even.push_back(num);
				else odd.push_back(num);
			}
			if(odd.size() > 0){
				cout << "1\n";
			} else {
				cout << "2\n";
			}
		}
	}
	
    return 0;
}

