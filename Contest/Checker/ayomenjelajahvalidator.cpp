#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

#define ll long long

int main(int argc, char * argv[]){
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 1e5, "n"); inf.readSpace();
	int m = inf.readInt(1, 1e5, "m");
	
	inf.readEoln();
	
	vector<int> a = inf.readInts(n, 1, 1e4);
	
	inf.readEoln();
	
	vector<int> b = inf.readInts(m, 1, 1e4);
	
	inf.readEoln();
	inf.readEof(); 
}


