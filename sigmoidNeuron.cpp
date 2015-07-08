#include "sigmoidNeuron.h"
using namespace std;

sigmoidNeuron::sigmoidNeuron():
weights(16, 0.0) {
	
	srand(time(NULL));

	for (vector<double>::iterator it = weights.begin(); it != weights.end(); ++it) {
		double w = (double)rand()/RAND_MAX;
		*it = w;
	}
}

sigmoidNeruon::sigmoidNeuron(int size, double initWeightRange, double initBias):
weights(size, 0.0) {

	srand(time(NULL));

	for (vector<double>::iterator it = weights.begin(); it != weights.end(); ++it) {
		double w = (double)rand()/RAND_MAX;
		*it = w * initWeightRange;
	}
	
	bias = initBias;
}

}

double sigmoidNeuron::compute(vector<double> inputs) {
	return dot(inputs, weights) + bias;
}

double dot(vector<double> a, vector<double> b) {
	if (a.size() != b.size()) {
		cout << "attempt to dot vectors of different sizes!" << endl;
		return 0.0;
	}
	double sum = 0.0;
	vector<double>::iterator itb = b.begin();
	for (vector<double>::iterator ita = a.begin(); ita != a.end(); ++ita) {
		sum += (*ita)*(*itb);
		++itb;
	}
	return sum;
}

