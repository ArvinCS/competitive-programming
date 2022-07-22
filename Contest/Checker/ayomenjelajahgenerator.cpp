#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
	int n = rnd.next(1, atoi(argv[1])), m = rnd.next(1, atoi(argv[2]));
	
	cout << n << " " << m << endl;
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << rnd.next(1, atoi(argv[3]));
	}
	cout << endl;
	
	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		cout << rnd.next(1, atoi(argv[4]));
	}
	cout << endl;
}
