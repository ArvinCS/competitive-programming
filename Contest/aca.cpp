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
 
bool find(string s, vector<us> marks, us i){
	if(i == marks.size()){
		us cnt = 0;
		for(int x=0;x<=s.length()-sub.length();x++){
			if(s.substr(x,x+sub.length()) == sub){
				cnt++;
				x += 3;
			}
			if(cnt > 1) break;
		}	
		
		if(cnt == 1){
			cout << "Yes\n";
			cout << s << "\n";
			return true;
		} else return false;
	}
	

		char previous = (marks[i] > 0 ? s[marks[i]-1] : 'b');
		if(previous == 'b'){
			s[marks[i]] = 'a';
		} else if(previous == 'c'){
			s[marks[i]] = 'a';
		} else {
			if(marks[i] > 1 && s[marks[i]-2] == 'b'){
				s[marks[i]] = 'c';
			} else {
				s[marks[i]] = 'b';
			}
		}
		
		if(find(s, marks, i+1)) return true;

	s[marks[i]] = 'd';
	if(find(s, marks, i+1)) return true;
	
	return false;
}
 
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
		
		vector<us> marks;
		for(int x=0;x<s.length();x++){
			if(s[x] == '?'){
				marks.push_back(x);
			}
		}		
		
		if(!find(s, marks, 0)) cout << "No\n";
	}
 
    return 0;
}
