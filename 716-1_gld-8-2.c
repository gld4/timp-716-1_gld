#include <stdio.h>
#include <stdlib.h>

void siftDown(int *n, int root, int b)
{
  int max; 
  int done = 0;
  while ((root * 2 <= b) && (!done))
  {
    if (root * 2 == b)
      max = root * 2;
    else if (n[root * 2] > n[root * 2 + 1])
      max = root * 2;
    else
      max = root * 2 + 1;

    if (n[root] < n[max])
    {
      int temp = n[root];
      n[root] = n[max];
      n[max] = temp;
      root = max;
    }
    else
      done = 1; 
  }
}
void heapSort(int *n, int array_size)
{

  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(n, i, array_size);

  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = n[0];
    n[0] = n[i];
    n[i] = temp;
    siftDown(n, 0, i - 1);
  }
}
int main ()
{
    int n, i;
    int *a;
    scanf("%d", &n);
    a  =  (int *)calloc(n, sizeof(int));
    for (i = 0;i< n;i++)
    {
        scanf("%d", &a[i]);
    }
    heapSort(a, n);
    for(i = 0;i < n;i++)
    {
        printf("%d ", (a[i]));
    }
    return 0;
}
