
#include "general_types.h"
#include "conv.h"

void vDoFilter(float32 out[IMG_ROW_UNPAD][IMG_COL_UNPAD], float32 img[IMG_ROW][IMG_COL], float32 filter[][FILTER_COL])
{
  uint8 tt = 0; uint8 zz = 0;
  
  for(uint8 i = 0; i < IMG_ROW_UNPAD; i++)
  {
    for(uint8 j = 0; j < IMG_COL_UNPAD; j++)
    {
	  for(uint8 t = i; t < i + FILTER_ROW; t++)
	  {
		for(uint8 z = j; z < j + FILTER_COL; z++)
		{
		  out[i][j] = out[i][j] + (img[t][z] * filter[tt][zz]);
		  zz++;
		}
		tt++; zz = 0;
	  }
	  tt = 0;	 
    }
  }
}

void vDoFilter1(float32 out[IMG_ROW_UNPAD][IMG_COL_UNPAD], float32 img[IMG_ROW][IMG_COL], float32 filter[FILTER_ROW][FILTER_COL])
{
  for(uint8 i = 0; i < IMG_ROW_UNPAD; i = i + 1)
  {
    for(uint8 j = 0; j < IMG_COL_UNPAD; j = j + 1)
    {
      out[i][j] =   (  img[i][j]*filter[0][0]) + (img[i][j+1] * filter[0][1]) + (img[i][j+2] * filter[0][2]) + (img[i][j+3] * filter[0][3]) + (img[i][j+4] * filter[0][4])
                  + (img[i+1][j]*filter[1][0]) + (img[i+1][j+1]*filter[1][1]) + (img[i+1][j+2]*filter[1][2]) + (img[i+1][j+3]*filter[1][3]) + (img[i+1][j+4]*filter[1][4])
                  + (img[i+2][j]*filter[2][0]) + (img[i+2][j+1]*filter[2][1]) + (img[i+2][j+2]*filter[2][2]) + (img[i+2][j+3]*filter[2][3]) + (img[i+2][j+4]*filter[2][4])
				  + (img[i+3][j]*filter[3][0]) + (img[i+3][j+1]*filter[3][1]) + (img[i+3][j+2]*filter[3][2]) + (img[i+3][j+3]*filter[3][3]) + (img[i+3][j+4]*filter[3][4])
				  + (img[i+4][j]*filter[4][0]) + (img[i+4][j+1]*filter[4][1]) + (img[i+4][j+2]*filter[4][2]) + (img[i+4][j+3]*filter[4][3]) + (img[i+4][j+4]*filter[4][4]);
				  
    }
  }
}
uint8 conv(float32 img[][IMG_COL], float32 filter[][FILTER_COL], uint8 stride)
{
  /* Declare nedded temporary variables */
  uint8 outRow, outCol, outDim;
  uint8 tt = 0; uint8 zz = 0;

  /* Get the size of the output matrix based on stride (1 or 2) and padding (0 or 1) */
  (stride == 1) ? (outDim = 0) : (outDim = 1);
  switch(outDim)
  {
    case 0: outRow = IMG_ROW-4; outCol = IMG_COL-4; break;
    //case 1: outRow = IMG_ROW/2; outCol = IMG_COL/2; break;
    default: break;
  }

  /* Declare the output with correct dimension */
  float32 out[outRow][outCol];
  float32 out1[outRow][outCol];

  for(int i=0;i<28;i++)
  {
    for(int j=0;j<28;j++)
    {
     out[i][j] = 0;
    }
  }
  
  vDoFilter(out, img, filter);
 
 
 for(int i=0;i<28;i++)
  {
    for(int j=0;j<28;j++)
    {
      printf("%.0f  ",out[i][j] );
    }
    printf("\n\n");
  }

  printf("\nImgagine dupa FILTRUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU: \n\n");
  
  //vDoFilter1(out, img, filter);
 // printf("\nImgagine dupa maxPool: \n\n");


  
  //maxPool(out, 1);
  
}


void printMatrix(float32 img[][IMG_COL], uint8 line, uint8 col)
{
  for(int i=0;i<line;i++)
  {
    for(int j=0;j<col;j++)
    {
      printf("%d ",img[i][j]);
    }
    printf("\n");
  }
}


/* Copy matrix to matrix with variable initial point
Arguments:
  - source matrix
  - destination matrix
  - starting point for destination matrix - 0, 0 for normal copy
  - number of source matrix rows
  - number of source matrix columns

  *************IMPORTANT******************************************
  THIS FUNCTION SHALL BE USED FOR PADDIN
  INITIAL MATRIX WILL BE COPIED IN THE MIDDLE OF ONE BIGGER 0 MATRIX
  ****************************************************************
*/
void copyMatrixToMatrix(float32 dest[][IMG_COL], float32 src[][3],
                        uint8 destStartLine, uint8 destStartCol, uint8 destRow, uint8 destCol)
{
  uint8 ii = 0;
  uint8 jj = 0;

  for(uint8 i = destStartLine; i < destRow; i++)
  {
    for(uint8 j = destStartCol; j < destCol; j++)
    {
        dest[i][j] = src[ii][jj];
        ++jj;
    }
    jj = 0;
    ++ii;
  }
}

void maxPool(float32 img[][IMG_COL_UNPAD], uint8 stride)
{
  /* Declare nedded temporary variables */
  uint8 outRow, outCol,outDim, max;

  /* Get the size of the output matrix based on stride (1 or 2) and padding (0 or 1) */
  (stride == 1) ? (outDim = 0) : (outDim = 1);
  switch(outDim)
  {
    case 0: outRow = IMG_COL_UNPAD-4; outCol = IMG_COL_UNPAD-4; break;
    case 1: outRow = IMG_COL_UNPAD/4; outCol = IMG_COL_UNPAD/4; break;
    default: break;
  }

  /* Declare the output with correct dimension */
  float32 out[outRow][outCol];

  /* Go over the input and compute the output */
  for(uint8 i = 0; i < outRow; i = i + stride)
  {
    for(uint8 j = 0; j < outCol; j = j + stride)
      {
        /* Itinialize max with first element of the evaluated matrix */
        max = img[i][j];
        for(uint8 ii = i; ii < (FILTER_ROW + i); ii++)
        {
          for(uint8 jj = j; jj < (FILTER_COL + j); jj++)
          {
            /* Look for max */
            if(img[ii][jj] > max)
            {
              max = img[ii][jj];
            }
          }
        }
        /* Write the output */
        out[i][j] = max;
     }
  }

  for(uint8 i=0;i<24;i++)
  {
    for(uint8 j=0;j<24;j++)
    {
      printf("%.0f  ", out[i][j]);
    }
    printf("\n");
  }
}

void padWith1(float32 input[][IMG_COL-2], float32 output[][IMG_COL])
{
  uint8 ii = 0;
  uint8 jj = 0;

  for(uint8 i = 1; i < IMG_ROW-1; i++)
  {
    for(uint8 j = 1; j < IMG_COL-1; j++)
    {
        output[i][j] = input[ii][jj];
        ++jj;
    }
    jj = 0;
    ++ii;
  }
}


void padWith2(float32 input[][IMG_COL-4], float32 output[][IMG_COL])
{
  uint8 ii = 0;
  uint8 jj = 0;

  for(uint8 i = 2; i < IMG_ROW-2; i++)
  {
    for(uint8 j = 2; j < IMG_COL-2; j++)
    {
        output[i][j] = input[ii][jj];
        ++jj;
    }
    jj = 0;
    ++ii;
  }
}



















/* Comment in order to see code up */
