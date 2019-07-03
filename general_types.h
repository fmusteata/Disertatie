#ifndef GENERAL_TYPES_H
#define GENERAL_TYPES_H

#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef char sint8;
typedef short sint16;
typedef int sint32;
typedef float float32;
typedef long float64;

typedef struct myMatrix{
	float32* data;
	uint8 nr_row;
	uint8 nr_col;
}MatrixType;

#define GetMatrixElement(in, i, j)			(*(in.data + (i*in.nr_col) + j))
#define SetMatrixElement(in, i, j, val)		(*(in.data + (i*in.nr_col) + j) = val)

#endif

