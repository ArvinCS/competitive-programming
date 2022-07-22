#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

char data[1000];

void swap(us a, us b){
	char tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

void reverse(us l, us r){
	while(l <= r){
		swap(l, r);
		l++;
		r--;
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, q;
	cin >> n >> q;
	
	for(us x=0;x<n;x++) cin >> data[x];
	for(us x=0;x<q;x++){
		us i, j, k;
		cin >> i >> j >> k;
		if(i == 1){
			swap(j-1, k-1);
		} else {
			reverse(j-1, k-1);
		}
	}
	
	for(us x=0;x<n;x++) cout << data[x];
	cout << "\n";
	
    return 0;
}

