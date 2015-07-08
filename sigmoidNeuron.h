#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

double dot(vector<double> a, vector<double> b);

class sigmoidNeuron {
public:
	sigmoidNeuron();
	sigmoidNeuron(int size, double initWeightRange, double initBias);
	double compute(vector<double> inputs);
	void delta(vector<double> dw);
protected:
	vector<double> weights;
	double bias;
};
