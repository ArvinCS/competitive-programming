#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
	int mx = atoi(argv[1]);
	
	cout << rnd.next(1, mx) << endl;
}
