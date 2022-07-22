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
		int n;
		cin >> n;
		
		vector<int> v[2];
		int id = 0;
		while(n > 0){
			v[id].push_back(n%10);
			n /= 10;
			id ^= 1;
		}
				
		ll table[2][10][10][10];
		fill(**table[0], **table[2], 0);
		
		for(int x=0;x<v[0].size();x++){
			for(int a=0;a<10;a++){
				for(int b=0;b<10;b++){
					if(x == 0){
						table[0][x][(a+b)%10][(a+b)/10]++;
						continue;	
					}
					
					for(int c=0;c<10;c++){
						table[0][x][(a+b+c)%10][(a+b+c)/10] += table[0][x-1][v[0][x-1]][c];
					}
				}
			}
		}
		
		ll ans = table[0][v[0].size()-1][v[0].back()][0];
		
		for(int x=0;x<v[1].size();x++){
			for(int a=0;a<10;a++){
				for(int b=0;b<10;b++){
					if(x == 0){
						table[1][x][(a+b)%10][(a+b)/10]++;
						continue;	
					}
					
					for(int c=0;c<10;c++){
						table[1][x][(a+b+c)%10][(a+b+c)/10] += table[1][x-1][v[1][x-1]][c];
					}
				}
			}
		}
		
//		cout << ans << "\n";
		
		if(v[1].size() > 0) ans *= table[1][v[1].size()-1][v[1].back()][0];
		
		cout << ans-2 << "\n";
	}
	
    return 0;
}

