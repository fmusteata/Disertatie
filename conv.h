#ifndef CONV_H
#define CONV_H

#include "general_types.h"
#include "net_param.h"

extern void conv(MatrixType in, MatrixType out, const float32 filter[][FILTER_COL], uint8 stride);
extern void printMatrix(MatrixType in);
extern void maxPool(MatrixType in, MatrixType out, uint8 stride);
extern void padWith2(float32 input[][IN_IMG_ROW_C1_UNPAD], float32 output[][IN_IMG_ROW_C1]);


#endif