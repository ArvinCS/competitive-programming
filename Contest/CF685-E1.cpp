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

int askAnd(int x, int y){
	cout << "AND " << x << " " << y << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

int askXor(int x, int y){
	cout << "XOR " << x << " " << y << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

int askOr(int x, int y){
	cout << "OR " << x << " " << y << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int tmp1 = askAnd(1, 2);
	int tmp2 = askXor(1, 2);
	int ans[n];
	
	if(tmp1 == 0 && tmp2 == 0){
		ans[0] = ans[1] = 0;
	} else {
		int tmp3 = askAnd(1, 3);
		int tmp4 = askOr(2, 3);
		
		int predict = tmp1 + tmp2;
		for(int x=0;x<16;x++){
			int bit = (1 << x);
			
			if(tmp4&bit){
				if(tmp3&bit && tmp2&bit){
					predict -= bit;
				}	
			} else {
				if(tmp2&bit){
					predict -= bit; 
				}
			}
		}
		
		ans[1] = predict;
		ans[0] = (ans[1]^(tmp1+tmp2)) + tmp1;
	}
	
	for(int x=3;x<=n;x++){
		int tmp3 = askXor(1, x);
		
		ans[x-1] = (ans[0]^tmp3);
	}
	
	cout << "!";
	for(int x=0;x<n;x++){
		cout << " " << ans[x];
	}
	cout << endl;
    return 0;
}

// Santai
// Pikirin dengan benar-benar


