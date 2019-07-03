#include "general_types.h"
#include "cnn_decl.h"
#include "conv.h"
#include "net.h"

int main()
{
    padWith2(InputImgUnpad, InputImg);
	vDoNetC1(img);
	vDoNetS1();
 
 // printf("\n\nImagine convolutie: \n\n");
  //conv(in, out, filters_S2[0], 1);
 // printMatrix(out);
  
 // printf("\n\nImagine max_pool: \n\n");
  //maxPool(out, out_pool, 2);
 // printMatrix(out_pool);
 
 //
  //float32 x;// = 4;
  //float32 sig;// = sigmoid(x);
  //printf("Sigmoid(%.2f) = %.8f", x, sig);
  /*for(uint8 i = 0; i< 20; i++)
  {
	  printf("Dati numarul: ");
	  scanf("%f", &x);
	  sig = sigmoid(x);
	  printf("\nSigmoid(%.2f) = %.8f\n\n", x, sig);
  }*/
  
  return 0;
}
