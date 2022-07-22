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

int leftBit(int n){
	int pos = -1;
	for(int x=0;x<=31;x++){
		if((n&(1<<x))){
			pos = x;
		}
	}
	return pos;
}

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
		
		set<int> st;
		int data[n], sum = 0;
		for(int x=0;x<n;x++){
			cin >> data[x];
			sum ^= data[x];
			st.insert(data[x]);
		}
		
		if(sum == 0){
			cout << "DRAW\n";
			continue;
		}
		
		int cnt[33];
		fill(cnt, cnt+33, 0);
		for(int x=0;x<n;x++){
			for(int y=0;y<=31;y++){
				if(data[x]&(1 << y)){
					cnt[y]++;
				}
			}
		}
		
		for(int x=31;x>=0;x--){
			if(cnt[x]&1){
				int one = cnt[x];
				int zero = n-cnt[x];
				
				if(one % 4 == 3 && zero % 2 == 0){
					cout << "LOSE\n";
				} else {
					cout << "WIN\n";
				}
				break;
			}
		}
	}
 
    return 0;
}
 
// Santai
// Pikirin dengan benar-benar
