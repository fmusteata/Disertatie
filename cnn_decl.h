#ifndef IMG_INCLUDE_H
#define IMG_INCLUDE_H

#include "general_types.h"
#include "net_param.h"

extern float32 InputImg[32][32];
extern float32 InputImgUnpad[28][28];

/* Variables for image */
extern MatrixType img;

/* C1 layer */
extern MatrixType out_C1[C1_NrFilters];

/* S2 layer */
extern MatrixType out_S2[C1_NrFilters];

/* C2 layer */
extern MatrixType out_C2[C2_NrFilters];

/* S3 layer */
extern MatrixType out_S3[C2_NrFilters];

/* C3 layer */
extern MatrixType out_C3[C3_NrFilters];

/* F1 layer */ 
extern float32 out_F1[NUM_NEURONS_F1];

/* F2 layer */ 
extern float32 out_F2[NUM_NEURONS_F2];




#endif