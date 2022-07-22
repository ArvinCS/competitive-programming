#include <iostream>
#include <cmath>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool match(string pattern, string text){
	int i = 0;
	for(int a=0;a<pattern.length();a++){
		bool canSkip = a > 0 && pattern[a-1] == '*';
		char c = pattern[a];
		if(c == '*') continue;
		if(canSkip){
			bool found = false;
			for(int x=i;x<text.length();x++){
				i = x;
				if(c == text[x]){
					found = true;
					break;
				}
			}
			i++;
			if(!found) return false;
		} else {
			if(c != text[i]){
				return false;
			}
			i++;
		}
	}
	cout << i << " " << pattern.length() << "\n";
	return i >= pattern.length();
}

string solve(int length, int n, string pattern[], bool alphabetDone[], int i, string ans){
	if(i >= length){
		bool m = true;
		
		for(int x=0;x<n;x++){
			cout << x << ": \n";
			if(!match(pattern[x], ans)){
				m = false;
				break;
			}
		}
		if(m) return ans;
		else return "*";
	}
	
	ans.append("-");
	//cout << i << ": " << ans << "\n";
	for(int x=0;x<24;x++){
		if(!alphabetDone[x]) continue;
		ans[i] = alphabet[x];
		string temp = solve(length, n, pattern, alphabetDone, i+1, ans);
		if(temp != "*"){
			return temp;
		}
	}
	return "*";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n;
		cin >> n;
		string pattern[n];
		int maxlength = 0;
		int uniLength = 0;
		bool alphabetDone[24];
		for(int x=0;x<n;x++){
			cin >> pattern[x];
			int length = 0;
			for(int a=0;a<pattern[x].length();a++){
				if(pattern[x][a] == '*') continue;
				if(!alphabetDone[pattern[x][a] - 'A']){
					alphabetDone[pattern[x][a] - 'A'] = true;
					uniLength++;
				}
				length++;
			}
		
			maxlength = max(maxlength, length);
		}
		//cout << maxlength << " " << uniLength << "\n";
		cout << "Case #" << c << ": " << solve(max(maxlength, uniLength), n, pattern, alphabetDone, 0, "") << "\n";
	}
    return 0;
}
