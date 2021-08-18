#include <stdio.h>
int main(void)
{
  int n, h, w, a, b, r = 0;
  scanf("%d %d %d", &n, &h, &w);

  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    if (h <= a && w <= b)
      r++;
  }
  printf("%d\n", r);
  return 0;
}