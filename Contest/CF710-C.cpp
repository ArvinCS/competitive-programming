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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		string a, b;
		cin >> a >> b;
		
		if(a == b){
			cout << "0\n";
			continue;
		}
		
		int len1 = a.length(), len2 = b.length();
		int ans = len1+len2;
		for(int a1=0;a1<len1;a1++){
			for(int a2=len1-1;a2>=0;a2--){
				int length = a2-a1+1;
				for(int x=0;x+length-1<len2;x++){
					bool possible = true;
					for(int y=0;y<length;y++){
						if(a[a1+y] != b[x+y]){
							possible = false;
							break;
						}
					}
					if(possible){
						ans = min(ans, len1-length + len2-length);
					}
				}
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

