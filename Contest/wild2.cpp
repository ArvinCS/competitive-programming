#include <iostream>
#include <vector>

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
	
	string pattern;
	us n;
	cin >> pattern >> n;
	
	string tmp;
	vector<string> words;
	for(us x=0;x<n;x++){
		cin >> tmp;
		words.push_back(tmp);
	}
	
	int artIndex = pattern.find('*');
	if(artIndex == 0){
		if(pattern.size() > 1){
			pattern = pattern.substr(1);
			for(int x=0;x<words.size();x++){
				if(words[x].length() >= pattern.length() && words[x].substr(words[x].length()-pattern.length()) == pattern) cout << words[x] << "\n";
			}
		} else {
			for(int x=0;x<words.size();x++) cout << words[x] << "\n";
		}
	} else if(artIndex == pattern.size() - 1){
		pattern = pattern.substr(0, pattern.size() - 1);
		for(int x=0;x<words.size();x++){
			if(words[x].substr(0, pattern.length()) == pattern) cout << words[x] << "\n";
		}
	} else {
		string prefix = pattern.substr(0, artIndex), suffix = pattern.substr(artIndex+1, pattern.length());
		for(int x=0;x<words.size();x++){
			if(words[x].length() < (prefix.length() + suffix.length()) || words[x].substr(0, prefix.length()) != prefix || words[x].substr(words[x].length()-suffix.length(), words[x].length()) != suffix){
				continue;
			}
			cout << words[x] << "\n";
		}
	}
    return 0;
}
