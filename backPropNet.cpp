#include "backPropNet.h"
using namespace std;

backPropNet::backPropNet() {
	//null constructor
	grid = NULL;

}


backPropNet::backPropNet(vector<int> * layerSizes) {

	grid = new vector<vector<sigmoidNeuron *> *>();
	int preLayer = 1;
	for (vector<int>::iterator layer = layerSizes->begin(); layer != layerSizes->end(); ++laye) {
		vector<sigmoidNeuron *> * temp = new vector<sigmoidNeuron *>();
		for (int i = 0; i < *layer; ++i)
			temp->push_back(new sigmoidNeuron(preLayer, 1, -0.5));
		
		grid->push_back(temp);
		preLayer = *layer;
	}
}

vector<double> backPropNet::evaluate(vector<double> * inputs) {
	
	vector<double> ret;

	vector<double> * prev = new vector<double>(*inputs);
	vector<double> * next = new vector<double>();
	for (vector<vector<sigmoidNeuron *> *>::iterator layer = grid->begin(); layer != grid->end(); ++layer) {
		for (vector<sigmoidNeuron *>::iterator neuron = layer->begin(); neuron != layer->end(); ++neuron)
			next->push_back(neuron->compute(prev));
		next->reverse();
		delete prev;
		prev = next;
		next = new vector<double>();
	}
	
	ret = *prev;
	return ret;
}


