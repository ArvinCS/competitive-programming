#include <bits/stdc++.h>

//We're no strangers to love
//You know the rules and so do I
//A full commitment's what I'm thinking of
//You wouldn't get this from any other guy
//I just wanna tell you how I'm feeling
//Gotta make you understand
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye
//Never gonna tell a lie and hurt you
//We've known each other for so long
//Your heart's been aching but you're too shy to say it
//Inside we both know what's been going on
//We know the game and we're gonna play it
//And if you ask me how I'm feeling
//Don't tell me you're too blind to see
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye
//Never gonna tell a lie and hurt you
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye
//Never gonna tell a lie and hurt you
//Never gonna give, never gonna give
//(Give you up)
//We've known each other for so long
//Your heart's been aching but you're too shy to say it
//Inside we both know what's been going on
//We know the game and we're gonna play it
//I just wanna tell you how I'm feeling
//Gotta make you understand
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye
//Never gonna tell a lie and hurt you
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye
//Never gonna tell a lie and hurt you
//Never gonna give you up
//Never gonna let you down
//Never gonna run around and desert you
//Never gonna make you cry
//Never gonna say goodbye

using namespace std;

#define ll long long

const double eps = 1e-9;

int n, q;
ll a, b, m, k[1005];

ll search(double val){
	ll cnt = 0;
	
	for(int x=1;x<=n;x++){
		ll tmp = floor(val * (a+x) - b);
		if(tmp < 0) tmp = 0;
		if(tmp > m) tmp = m;
		
		cnt += tmp;
	}
	
	return cnt;
}

bool isSame(double a, double b){
	if(abs(a-b) < eps){
		return true;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m >> a >> b >> q;
	
	for(int x=0;x<q;x++){
		cin >> k[x];
	}
	
	for(int i=0;i<q;i++){
		double l = 0, r = 2e9;
		for(int x=1;x<=100;x++){
			double m = (l+r)*0.5;
			
			if(search(m) < k[i]){
				l = m;
			} else {
				r = m;
			}
		}
		
		double ans = l+eps, diff = 1e18;
		ll ans1 = -1, ans2 = 1;
		
		for(int x=1;x<=n;x++){
			ll row = floor(ans * (a+x) - b);
			if(row < 0) row = 0;
			if(row > m) row = m;
			
			for(ll y=max(1ll, row-100);y<=min(row+100, m);y++){
				double cur = fabs((b+y) - ans * (a+x));

				if(cur < diff && !isSame(cur, diff)){
					diff = cur;
					ans1 = (b+y);
					ans2 = (a+x);
				}
			}
		}
		
		ll ans3 = __gcd(ans1, ans2);
		ans1 /= ans3; ans2 /= ans3;
		
		cout << ans1 << "/" << ans2 << "\n";
	}
    return 0;
}

