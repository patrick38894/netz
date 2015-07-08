#include "sigmoidNeuron.h"
using namespace std;

class backPropNet {
public:
	backProtNet();
	backProtNet(vector<int> layerSizes);
	vector<double> evaluate(vector<double> * input);
protected:
	vector<vector<sigmoidNeuron * > * > * grid;

};


