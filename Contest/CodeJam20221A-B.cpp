#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 100;

ll fib[N];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fib[0] = fib[1] = 1;
	for(int x=2;x<N;x++){
		fib[x] = fib[x-1]+fib[x-2];
	}
	
	cout << fib[N-1] << "\n";
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		
	}
	
    return 0;
}

