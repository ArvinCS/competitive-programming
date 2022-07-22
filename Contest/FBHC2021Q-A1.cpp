#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

bool isVowel[26];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("consistency_chapter_1_validation_input.txt","r",stdin);
//	freopen("consistency_chapter_1_validation_output.txt","w",stdout);
	
	fill(isVowel, isVowel+26, false);
	
	for(int x=0;x<26;x++){
		char c = ('A' + x);
		if(c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O'){
			isVowel[x] = true;
		}
	}
		
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		string s;
		cin >> s;
		
		int cnt[26], vowel = 0, cons = 0;
		fill(cnt, cnt+26, 0);
		
		for(int x=0;x<s.length();x++){
			cnt[(s[x] - 'A')]++;
			
			if(isVowel[(s[x] - 'A')]){
				vowel++;
			} else {
				cons++;
			}
		}
		
		int ans = inf_int;
		for(int x=0;x<26;x++){
			if(isVowel[x]){
				ans = min(ans, cons+(vowel-cnt[x])*2);
			} else {
				ans = min(ans, vowel+(cons-cnt[x])*2);
			}
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

