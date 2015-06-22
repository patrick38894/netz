#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class neuron {
public:
	neuron();
	neuron(int);
	~neuron();
	float forwardPass(vector<float>);
	float backProp(float);
private:
	int size;
	vector<float> weights;
};

class net {
public:
	net();
	net(vector<int>);
	~net();
	void train(vector<int>, vector<int>);
	vector<int> classify(vector<int>);
private:
	vector<vector<float>> graph;
};



void printVec(int * v, int l) {
	cout << endl << "vector of size " << l << " is:" << endl;
	for (int i = 0; i < l; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main (int argc, char ** argv) {
	int ioLength = -1;
	char buf[100];
	int ioVec[20];
	
	//net mynet = new net;

	while(1) {
		cout << endl << "enter your input vector as a sequence of integers" << endl;
		cin.get(buf,100);
		cin.ignore(100,'\n');
		char * s = strtok(buf," \n");
		int currLength = 0;
		while (s) {
			cout << "debug str = " << s << endl;
			int i = atoi(s);
			ioVec[currLength++] = i;
			s = strtok(NULL, " \n");
		}
		if (ioLength == -1) {
			ioLength = currLength; //inital input vector will set the length of all future vectors
			//mynet.initialize(currlength);
		}
			
		//mynet.backprop(iovec);
		printVec(ioVec, ioLength);
	}
	return 0;
}


