#ifndef NET_ARCH_H
#define NET_ARCH_H

#include "general_types.h"
#include "net_param.h"

typedef struct myNet{
	struct myC1{
		const float32 teta;
		const uint8 nrFilters;
		const float32 filters[C1_NrFilters][FILTER_ROW][FILTER_COL];
		const float32 biases[C1_NrFilters];
	}C1;
	
	struct myS2{
		const float32 teta;
		const uint8 sRate;
		const float32 biases[C1_NrFilters];
		const float32 weights[C1_NrFilters];
	}S2;
	
	struct myC2{
		const float32 teta;
		const uint8 nrFilters;
		const float32 filters[C2_NrFilters][FILTER_ROW][FILTER_COL];
		const float32 biases[C2_NrFilters];
	}C2;
	
	struct myS3{
		const float32 teta;
		const uint8 sRate;
		const float32 biases[C2_NrFilters];
		const float32 weights[C2_NrFilters];
	}S3;
	
	struct myC3{
		const float32 teta;
		const uint8 nrFilters;
		const float32 filters[C3_NrFilters][FILTER_ROW][FILTER_COL];
		const float32 biases[C3_NrFilters];
	}C3;
	
	struct myF1{
		const float32 teta;
		const uint8 nrNeurons;
		const float32 weights[C3_NrFilters][NUM_NEURONS_F1];
		const float32 biases[NUM_NEURONS_F1];
	}F1;
	
	struct myF2{
		const float32 teta;
		const uint8 nrNeurons;
		const float32 weights[NUM_NEURONS_F1][NUM_NEURONS_F2];
		const float32 biases[NUM_NEURONS_F2];	
	}F2;
}CNN_Type;

extern CNN_Type myCnn;

#endif