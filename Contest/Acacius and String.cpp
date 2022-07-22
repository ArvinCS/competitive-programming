#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

string sub = "abacaba";

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
		
		bool correct[n];
		fill(correct, correct+n, false);
		
		int cnt = 0, mcnt = 0;
		for(int x=0;x<=n-sub.length();x++){
			bool tmp[n];
			copy(correct, correct+n, tmp);
			
			int y=0;
			bool hasMark = false;
			for(y=0;y<sub.length();y++){
				if(s[x+y] != sub[y] && s[x+y] != '?') break;
				if(s[x+y] == '?'){
					tmp[x+y] = (cnt == 0);
					hasMark = true;
				}
			}
			
			if(y == sub.length() && (x+y==n || s[x+y+1])){
				cnt++;
				if(hasMark){
					mcnt++;
					copy(tmp, tmp+n, correct);
				}
			}
		}
				
		if(cnt > 0 && (cnt-mcnt == 1 || cnt-mcnt == 0)){
			cout << "YES\n";
			if(cnt-mcnt == 0){
				for(int x=0;x<n;x++){
					if(s[x] == '?'){
						if(correct[x]){
							char previous = (x > 0 ? s[x-1] : 'b');
							if(previous != 'a'){
								s[x] = 'a';
							} else {
								if(x > 1 && s[x-2] == 'b'){
									s[x] = 'c';
								} else {
									s[x] = 'b';
								}
							}
						} else {
							s[x] = 'd';
						}
					}
				}
			} else {
				for(int x=0;x<n;x++){
					if(s[x] == '?') s[x] = 'd';
				}
			}
			cout << s << "\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
