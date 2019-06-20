#include "general_types.h"
#include "conv.h"
#include "img_decl.h"
#include "sigmoid.h"

int main()
{

  //int row_img = sizeof(img) / sizeof(img[0]);
  //int col_img = sizeof(img)/row_img;
  //int row_filter = sizeof(filter) / sizeof(filter[0]);
  //int col_filter = sizeof(filter)/row_filter;

  //printf("Imgagine intiala: \n\n");
  //for(int i=0;i<5;i++){for(int j=0;j<5;j++){printf("%d ", img[i][j]);}printf("\n");}
  //printf("\n");

  padWith2(img_test, img);

 // printf("Imgagine dupa padding: \n\n");
 // for(int i=0;i<32;i++){for(int j=0;j<32;j++){printf("%.0f  ", img[i][j]);}printf("\n");}
  //printf("\n");
  
  conv(img, filter, 1);

  //printf("Imgagine dupa aplicare filtru convolutie: \n\n");
  //conv(img_pad, filter , 1);

	printf("SIGMOID\n"); 
  printf("%.8f", sigmoid(4));
  
  printf("Press ENTER key to Continue\n");  
  getchar();

  return 0;
}
