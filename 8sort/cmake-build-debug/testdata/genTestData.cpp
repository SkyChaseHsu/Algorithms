#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {

	srand((int)time(0));
	
	for(int N = 10000; N <= 50000; N += 10000){
		for(int i = 1; i <= 20; i++){
			char filename[20];
			sprintf(filename, "N=%d_%d.txt",N, i);
			freopen(filename,"w", stdout);
			for(int i = 0; i < N; i++)
				cout<<rand() % 100000<<" ";
			cout<<endl;
		}
	}
	return 0;
}