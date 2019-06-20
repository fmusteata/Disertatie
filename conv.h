
extern uint8 conv(float32 img[][IMG_COL], float32 filter[][FILTER_COL], uint8 stride);
extern void printMatrix(float32 img[][IMG_COL], uint8 line, uint8 col);
extern void copyMatrixToMatrix(float32 dest[][IMG_COL], float32 src[][3],uint8 destStartLine, uint8 destStartCol, uint8 destRow, uint8 destCol);
extern void maxPool(float32 img[][IMG_COL_UNPAD], uint8 stride);
extern void padWith1(float32 input[][IMG_COL-2], float32 output[][IMG_COL]);
extern void padWith2(float32 input[][IMG_COL-4], float32 output[][IMG_COL]);
