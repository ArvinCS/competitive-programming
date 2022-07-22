#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

unsigned int k;

bool customSort(unsigned int a, unsigned int b){
	return a % k > b % k;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		unsigned int n;
		cin >> n >> k;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n, customSort);
		
		int point = 0, move = 0;
		for(int x=0;x<n;x++){
			cout << data[x] << "\n";
			if(data[x] % k == 0){
				continue;
			}
			if((data[x] + point) % k == 0){
				move++;
				point++;
			} else if((data[x] + point + 1) % k == 0){
				move += 2;
				point += 2;
			} else {
				int a = k * (data[x]/k), b = k * (data[x]/k + 1);
				cout << "a: " << a << " b: " << b << "\n";
				move += abs(data[x] - (a >= data[x] ? a : b)) + 1;
				point += abs(data[x] - (a >= data[x] ? a : b)) + 1;
				data[x] = (a >= data[x] ? a : b);
			}
			cout << "p: " << point << " - " << move << "\n";
		}	
		
		cout << move << "\n";
	}
	
    return 0;
}
