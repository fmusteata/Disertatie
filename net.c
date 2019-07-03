#include "general_types.h"
#include "conv.h"
#include "cnn_decl.h"
#include "sigmoid.h"
#include "net_arch.h"
#include "net.h"

void vDoNetC1(MatrixType img)
{
	/* C1 layer */
	for(uint8 i = 0; i < C1_NrFilters; i++)
	{
		/* Apply convolutional filters */ 
		conv(img, out_C1[i], myCnn.C1.filters[i], 1);
		
		/* Add the biasese */
		for(uint8 j = 0; j < out_C1[i].nr_row; j++)
		{
			for(uint8 z = 0; z < out_C1[i].nr_col; z++)
			{
				SetMatrixElement(out_C1[i], j, z, (GetMatrixElement(out_C1[i], j, z) + myCnn.C1.biases[i]));
			}
		}
	}
}

void vDoNetS1(void)
{
	float32 temp;
	float32 temp_sig;
	
	for(uint8 i = 0; i < C1_NrFilters; i++)
	{
		maxPool(out_C1[i], out_S2[i], myCnn.S2.sRate);

		for(uint8 j = 0; j < out_S2[i].nr_row; j++)
		{
			for(uint8 z = 0; z < out_S2[i].nr_col; z++)
			{
				temp = (GetMatrixElement(out_S2[i], j, z) * myCnn.S2.weights[i]) + myCnn.S2.biases[i];
				temp_sig = sigmoid(temp);
				SetMatrixElement(out_S2[i], j, z, temp_sig);
			}
		}
	}
}