#include"communication.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

//
// --- Sample implementation for the task communication ---
//
// To compile this program with the sample grader, place:
//     communication.h communication_sample.cpp sample_grader.cpp
// in a single folder, then open the terminal in this directory (right-click onto an empty spot in the directory,
// left click on "Open in terminal") and enter e.g.:
//     g++ -std=c++17 communication_sample.cpp sample_grader.cpp
// in this folder. This will create a file a.out in the current directory which you can execute from the terminal
// as ./a.out
// See task statement or sample_grader.cpp for the input specification
//

void encode(int N, int X) {
	int lg = log2(N);
	for(int x=0;x<=lg;x++){
		int bit = (1 << x);
		
		bool one = ((X&bit) ? 1 : 0);
		if(send(one) == one){
			send(one);
		} else {
			send(one^1);
		}
	}
}

pair<int, int> decode(int N) {
    int val = 0;
    for(int x=0;x<2;x++){
    	int bit = (1 << x);
    	
    	if(receive()&1){
    		val |= bit;
		} else {
			val |= bit;
		}
	}
	
	if(val == 0){
		return {1, 2};
	} else if(val == 1){
		return {1, 3};
	} else if(val == 2){
		return {2, 3};
	} else {
		if(receive()&1){
			return {1, val};
		}
		return {2, 3};
	}
	
    return {1, 2};
}
