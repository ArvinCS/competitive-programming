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

ll rev(ll x){
	ll ans = 0;
	
	while(x > 0){
		ans *= 10;
		ans += (x%10);
		x /= 10;
	}
	return ans;
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
		int n, k;
		cin >> n >> k;
		
		ll ans = inf_ll;
		for(int x=0;x<=9;x++){
			ll cur = 0;
			for(int i=1;i<=18;i++){
				ll used = min(x+k, 9)-x+1;
				ll remain = k+1-used;
				
				ll sum = used*9*(i-1) + (min(x+k, 9)*(min(x+k, 9)+1)/2 - x*(x-1)/2) + remain*(remain-1)/2 + remain;
				// formula : add how many digit 9 in num format 9..9x multiply by total number 
				// + add last digit of no-changed number (not becoming 1....0)
				// + (if there is case where the digit changed to 1...0, add the last digit of it) 
				// + (if there is cases where the digit changed to 1...0, add how many number is it)
				
				if(sum <= n && (n-sum)%(k+1) == 0){ // check if the sum <= n and the remaining is "divideable" to k+1 numbers also not overflowing more than 10^18.
					ll val = 0;
					ll cnt = n-sum; // remainin sum
					
					if(cnt > 0){ // limit the dig, if there is cases 1...0 the limit for the first new digit is 8, otherwise if it's 9 it will be broken.
						val += min((remain > 0 ? 8ll : 9ll), cnt/(k+1));
						cnt -= val*(k+1);
					}
					while(cnt > 0){ // add the 9 digit number until 0
						val *= 10;
						val += min(cnt/(k+1), 9ll);	
						cnt -= min(cnt/(k+1), 9ll)*(k+1);
					}
					val = rev(val);
					val *= pow(10, i); // combine the new digit and the number above
					val += cur;
					
					ans = min(ans, val+x);	// check min
				}
				
				cur += 9;
				cur *= 10;
			}
		}
		
		cout << (ans == inf_ll ? -1 : ans) << "\n";
	}
	

    return 0;
}

