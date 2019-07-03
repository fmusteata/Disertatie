#include "net_arch.h"
#include "net_param.h"

CNN_Type myCnn = {
	{
		.teta = teta_C1,
		.nrFilters = C1_NrFilters,
		.filters = filters_C1,
		.biases = biases_C1
	},
	
	{
		.teta = teta_S2,
		.sRate = sRate_S2,
		.biases = biases_S2,
		.weights = weights_S2
	},
	
	{
		.teta = teta_C2,
		.nrFilters = C2_NrFilters,
		.filters = filters_C2,
		.biases = biases_C2
	},
	
	{
		.teta = teta_S3,
		.sRate = sRate_S3,
		.biases = biases_S3,
		.weights = weights_S3
	},
	
	{
		.teta = teta_C3,
		.nrFilters = C3_NrFilters,
		.filters = filters_C3,
		.biases = biases_C3
	},
	
	{
		.teta = teta_F1,
		.nrNeurons = NUM_NEURONS_F1,
		.weights = weights_F1,
		.biases = biases_F1
	},
	
	{
		.teta = teta_F2,
		.nrNeurons = NUM_NEURONS_F2,
		.weights = weights_F2,
		.biases = biases_F2
	}
};
