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

string s1, s2, s3;

bool solve(int idx, int table[27]){
	if(idx == 26){
		bool valid = true;
		
		ll n1 = 0, n2 = 0;
		for(int x=0;x<s1.length();x++){
			n1 *= 10;
			n1 += table[s1[x]-'a'];
		}
		for(int x=0;x<s2.length();x++){
			n2 *= 10;
			n2 += table[s2[x]-'a'];
		}
		
		if(n1 == 0 || n2 == 0) return false;
		
		cout << n1 << " + " << n2 << " = " << n1+n2 << "\n";
		ll n3 = n1+n2;
		if(n3/10 == 0){
			return (s3.length() == 1 && n3 == (table[s3[0] - 'a']));
		} else {
			ll tmp = n3, cur = s3.length()-1;
			while(tmp > 0){
				ll digit = tmp % 10;
				if(digit != table[s3[cur]-'a']){
					valid = false;
					break;
				}
				tmp /= 10;
				cur--;
			}
			
			if(cur >= 0){
				valid = false;
			}
		}
		
//		cout << n1 << " + " << n2 << " = " << n3 << "\n";
		if(valid){
			cout << n1 << "\n";
			cout << n2 << "\n";
			cout << n3 << "\n";
		}
		return valid;
	}
	
	for(int digit=0;digit<10;digit++){
		table[idx] = digit;
		if(solve(idx+1, table)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> s1 >> s2 >> s3;
	
	int c[27];
	fill(c, c+27, 0);
	
	if(!solve(0, c)){
		cout << "UNSOLVABLE\n";
	}	
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

