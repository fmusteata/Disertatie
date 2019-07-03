#include "conv.h"

void vDoFilter(MatrixType out, MatrixType in, const float32 filter[][FILTER_COL])
{
  uint8 tt = 0; uint8 zz = 0;
  
  for(uint8 i = 0; i < out.nr_row; i++)
  {
    for(uint8 j = 0; j < out.nr_col; j++)
    {
	  for(uint8 t = i; t < i + FILTER_ROW; t++)
	  {
		for(uint8 z = j; z < j + FILTER_COL; z++)
		{
		  /* only God knows what is here */
		  *(out.data + (i*out.nr_col) + j) = *(out.data + (i*out.nr_col) + j) + (*(in.data + (t*in.nr_col) + z) * filter[tt][zz]);
		  zz++;
		}
		tt++; zz = 0;
	  }
	  tt = 0;
    }
  }
}

/* pointer la primul element si dimensiunile */
void conv(MatrixType in, MatrixType out, const float32 filter[][FILTER_COL], uint8 stride)
{
  vDoFilter(out, in, filter);
}

void printMatrix(MatrixType in)
{
   for(int i = 0; i < in.nr_row; i++)
	{
		for(int j = 0; j < in.nr_col; j++)
		{
			printf("%.2f  ", *(in.data + (i*in.nr_col) + j));
		}
		printf("\n");
	}
}


void maxPool(MatrixType in, MatrixType out, uint8 stride)
{
  float32 max;
  
  /* Indexes for populate output */
  int i_index = -1; int j_index = -1;

 for(uint8 i = 0; i < in.nr_row; i = i + stride)
  {
	i_index++;
    for(uint8 j = 0; j < in.nr_col; j = j + stride)
      {
		j_index++;
        
		/* Itinialize max with first element of the evaluated matrix */
		max = GetMatrixElement(in, i, j);
		
        for(uint8 ii = i; ii < (stride + i); ii++)
        {
          for(uint8 jj = j; jj < (stride + j); jj++)
          {
            /* Look for max */
			if(*(in.data + (ii*in.nr_col) + jj) > max)
            {
              max = *(in.data + (ii*in.nr_col) + jj);
            }
          }
        }
        /* Write the output */
        *(out.data + (i_index*out.nr_col) + j_index) = max;
     }
	 j_index = -1;
  }
}

void padWith2(float32 input[][IN_IMG_ROW_C1_UNPAD], float32 output[][IN_IMG_ROW_C1])
{
	uint8 ii = 0;
	uint8 jj = 0;

	for(uint8 i = 2; i < IN_IMG_ROW_C1-2; i++)
	{
		for(uint8 j = 2; j < IN_IMG_COL_C1-2; j++)
		{
			output[i][j] = input[ii][jj];
			++jj;
		}
		jj = 0;
		++ii;
	}
}



















/* Comment in order to see code up */
