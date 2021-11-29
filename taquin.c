#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int l_trou=1 , c_trou=1 , nb_coups=0;
const int li_max=4 ,col_max=4;
int taquin[li_max][col_max];


int main(void){

  for(int i=0 ; i<li_max;i++){
    for(int j=0 ; j <col_max ; j++){
      taquin[i][j]=li_max*i+j;
      printf("%3d",taquin[i][j]);

    }
    printf("\n");
  }

return EXIT_SUCCESS;
}
