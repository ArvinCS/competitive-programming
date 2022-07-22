#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unordered_map<string, int> database;
	
	int n;
	cin >> n;
	
	string tmp;
	while(n--){
		cin >> tmp;
		
		database[tmp]++;
		int cnt = database[tmp];
		if(cnt == 1){
			cout << "OK\n";
		} else {
			cout << tmp << cnt - 1 << "\n";
		}
	}
	
    return 0;
}
