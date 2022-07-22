#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s, ans;
		cin >> s;
		
		ans.push_back(s[0]);
		for(int x=1;x<s.length();x+=2){
			ans.push_back(s[x]);
		}
		cout << ans << "\n";
	}
    return 0;
}
