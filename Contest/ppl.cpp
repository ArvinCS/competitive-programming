#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

short check(string a, string b){
	us i = 0;
	for(us x=0;x<a.length();x++){
		if(a[x] == b[i]) i++;
	}
	for(short x=a.length()-1;x>=0;x--){
		if(a[x] == b[i]) i++;
	}
	return (i >= b.length() ? i - b.length() + 1 : -1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	us n;
	string s;
	cin >> n >> s;
	
	ui ans = 1, cnt[s.length()];
	fill(cnt, cnt+s.length(), 0);
	
	for(us c=0;c<26;c++){
		string tmp = s;
		char currentChar = 'A' + c;
		for(us x=0;x<n;x++){
			char tmp2 = tmp[x];
			if(tmp2 == currentChar) continue;
			
			tmp[x] = currentChar;
			if(check(tmp, s) >= 0){
//				cout << "tmp: " << tmp << '\n';
				cnt[x] += check(tmp, s);
			}
			tmp[x] = tmp2;
		}	
	}
	
	for(us x=0;x<n;x++){
		ans += cnt[x];
	}
	
	cout << ans << "\n";
	
    return 0;
}

