
#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef char sint8;
typedef short sint16;
typedef int sint32;
typedef float float32;
typedef long float64;

#define IMG_ROW 32
#define IMG_COL 32

#define IMG_ROW_UNPAD (IMG_ROW - (FILTER_ROW - 1))
#define IMG_COL_UNPAD (IMG_COL - (FILTER_COL - 1))

#define IMG_ROW1 5
#define IMG_COL1 5

#define FILTER_ROW 5
#define FILTER_COL 5
