
#include "general_types.h"
#include "net_arch.h"
#include "conv.h"

float32 InputImg[32][32] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

float32 InputImgUnpad[28][28] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

float32 img_pool[14][14] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

/* C1 outputs */
float32 in_C1_data[IN_IMG_ROW_C1][IN_IMG_COL_C1];
float32 out_C1_data1[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];
float32 out_C1_data2[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];
float32 out_C1_data3[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];
float32 out_C1_data4[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];
float32 out_C1_data5[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];
float32 out_C1_data6[OUT_IMG_ROW_C1][OUT_IMG_COL_C1];

/* S2 outputs */
float32 out_S2_data1[OUT_IMG_ROW_S2][OUT_IMG_COL_S2]; 
float32 out_S2_data2[OUT_IMG_ROW_S2][OUT_IMG_COL_S2]; 
float32 out_S2_data3[OUT_IMG_ROW_S2][OUT_IMG_COL_S2]; 
float32 out_S2_data4[OUT_IMG_ROW_S2][OUT_IMG_COL_S2]; 
float32 out_S2_data5[OUT_IMG_ROW_S2][OUT_IMG_COL_S2];
float32 out_S2_data6[OUT_IMG_ROW_S2][OUT_IMG_COL_S2]; 

/* C2 outputs */
float32 out_C2_data1[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data2[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data3[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data4[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data5[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];
float32 out_C2_data6[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];
float32 out_C2_data7[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data8[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data9[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data10[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data11[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];
float32 out_C2_data12[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];
float32 out_C2_data13[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data14[OUT_IMG_ROW_C2][OUT_IMG_COL_C2]; 
float32 out_C2_data15[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];
float32 out_C2_data16[OUT_IMG_ROW_C2][OUT_IMG_COL_C2];

/* S3 outputs */
float32 out_S3_data1[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data2[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data3[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data4[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data5[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];
float32 out_S3_data6[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];
float32 out_S3_data7[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data8[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data9[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data10[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data11[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];
float32 out_S3_data12[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];
float32 out_S3_data13[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data14[OUT_IMG_ROW_S3][OUT_IMG_COL_S3]; 
float32 out_S3_data15[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];
float32 out_S3_data16[OUT_IMG_ROW_S3][OUT_IMG_COL_S3];

/* C3 outputs */
float32 out_C3_data[OUT_IMG_ROW_C3];

 		
MatrixType img = {
	.data = &InputImg[0][0],
	.nr_row = 32,
	.nr_col = 32};
				
/* Variables for image */

/* C1 layer */
MatrixType out_C1[C1_NrFilters] ={
	
	{.data = &out_C1_data1[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1},
	
	{.data = &out_C1_data2[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1},
	
	{.data = &out_C1_data3[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1},
	
	{.data = &out_C1_data4[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1},
	
	{.data = &out_C1_data5[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1},
	
	{.data = &out_C1_data6[0][0],
	.nr_row = OUT_IMG_ROW_C1,
	.nr_col = OUT_IMG_COL_C1}
};
	
/* S2 */
MatrixType out_S2[C1_NrFilters] ={
	
	{.data = &out_S2_data1[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2},
	
	{.data = &out_S2_data2[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2},
	
	{.data = &out_S2_data3[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2},
	
	{.data = &out_S2_data4[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2},
	
	{.data = &out_S2_data5[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2},
	
	{.data = &out_S2_data6[0][0],
	.nr_row = OUT_IMG_ROW_S2,
	.nr_col = OUT_IMG_COL_S2}
};

/* C2 */
MatrixType out_C2[C2_NrFilters] ={
	
	{.data = &out_C2_data1[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data2[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data3[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data4[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data5[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data6[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data7[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data8[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data9[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data10[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data11[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data12[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data13[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data14[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data15[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2},
	
	{.data = &out_C2_data16[0][0],
	.nr_row = OUT_IMG_ROW_C2,
	.nr_col = OUT_IMG_COL_C2}
};

/* S3 */
MatrixType out_S3[C2_NrFilters] ={
	
	{.data = &out_S3_data1[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data2[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data3[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data4[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data5[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data6[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data7[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data8[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data9[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data10[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data11[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data12[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data13[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data14[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data15[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3},
	
	{.data = &out_S3_data16[0][0],
	.nr_row = OUT_IMG_ROW_S3,
	.nr_col = OUT_IMG_COL_S3}
};

/* C3 */
MatrixType out_C3[C3_NrFilters];

/* F1 */
float32 out_F1[NUM_NEURONS_F1];

/* F2 */
float32 out_F2[NUM_NEURONS_F2];

			
			


