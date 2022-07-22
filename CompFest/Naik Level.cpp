#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n;
ull exp[20], m;

bool solve(ull totalExp, int currentIndex){
	if(currentIndex > n){
		return totalExp == m;
	}
	return solve(totalExp, currentIndex+1) || solve(totalExp+exp[currentIndex], currentIndex+1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(us x=0;x<n;x++){
		ull tmp;
		cin >> tmp;
		exp[x] = tmp;
	}
	
	if(solve(0, 0)){
		cout << "bisa\n";
	} else {
		cout << "tidak bisa\n";
	}
    return 0;
}

