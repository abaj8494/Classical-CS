#include <stdio.h>
#include <stdlib.h>

int *iSort(int *a, int nbytes) {

  /*  int v, i, j;*/
  /* for (i = 2; i < nbytes; i++) { */
  /*   v = a[i]; */
  /*   j = i; */
  /*   while (a[j-1] > v) { */
  /*     a[j] = a[j-1]; */
  /*     j = j-1; */
  /*   } */
  /*   a[j] = v; */
  /* } */

  for (int i = 1; i < nbytes; i++) {
    int key = a[i];
    int j = i - 1;
    while (j > 0 && a[j] > key) {
      a[j+1] = a[j];
      j = j - 1;
    }
    a[j+1] = key;
  }

  return a;
}

void printArr(int *a, int nbytes) {
  for (int i = 0; i < nbytes; i++) {
    printf("%d",a[i]);
  }
  printf("\n");
}

int main(void)
{
    int sortme[] = {7, 5, 3, 2, 1, 4, 6};
    printArr(sortme, 7);
    iSort(sortme, 7);
    printArr(sortme, 7);
}
