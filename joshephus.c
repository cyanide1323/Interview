// joshephus problem

#include <stdio.h>
 
int josephus(int n, int k)
{
	printf("%d  %d\n",n,k);
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}
 
// Driver Program to test above function
int main()
{
  int n = 8;
  int k = 2;
  printf("\nThe chosen place is %d\n", josephus(n, k));
  return 0;
}
