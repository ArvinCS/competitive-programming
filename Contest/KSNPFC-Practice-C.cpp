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

int play(int x){
	cout << x << endl;
}

int get(){
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	if(n <= 3){
		play(1);
		play(n);
		get();
		
		return 0;
	}
	
	if(n%4 == 0){
		play(2);
		
		while(n > 0){
			int jury = get();
			
			n -= jury;
			
			int tmp = (4-jury);
			
			play(tmp);
			n-= tmp;
		}
	} else {
		play(1);
		
		int tmp = (n-(n/4)*4);
		
		play(tmp);
		n -= tmp;
		
		while(n > 0){
			int jury = get();
			n -= jury;
			
			tmp = 4-jury;
			play(tmp);
			n -= tmp;
		}
	}
	
    return 0;
}

