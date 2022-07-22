#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, ans = 0;
	cin >> n;
	
	us data[n+1];
	for(us x=1;x<=n;x++){
		cin >> data[x];
	}
	
	us i = 1;
	while(i <= n){
		while(data[i] != i){
			us tmp = data[i];
			data[i] = data[tmp];
			data[tmp] = tmp;
			
			ans++;
		}
		i++;
	}
	
	cout << ans << "\n";
    return 0;
}
