#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int mx = 1e9;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
	int X = rnd.next(1, atoi(argv[1]));
	int Y = rnd.next(1, atoi(argv[2]));
	
	cout << X << " " << Y << endl;
}
