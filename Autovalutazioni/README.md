# Esercizio 1
```c
#include "stdio.h"

int main(void)
{
  int somma = 0, n;
  
  do
  {
    scanf("%d", &n);
    somma = somma + n;
   }
   while (n != 0);
   
   printf("%d\n", n);
   
   return 0;
```
# Esercizio 2
```c
#include "stdio.h"

int main(void)
{
  int i;
  
  for (i = 1; i < 10; i++)
    if (i % 2 == 0) printf("%d\n", i);
    
   return 0;
}
```
# Esercizio 3
```c
#include "stdio.h"

int main(void)
{
  int d,m,a;
  int older_d = 32, older_m = 13, older_a = 9999;
  
  while (d || m || a) 
  {
    scanf("%d/%d/%d", &d, &m, &a);
    
    if (d || m || a){
      if (a < older_a) {
        older_a = a; older_m = m; older_d = d;
      } else if (a == older_a) {
        if (m < older_m) {
          older_a = a; older_m = m; older_d = d;
        } else if (m == older_m) {
          if (d < older_d ) {
            older_a = a; older_m = m; older_d = d;
          }
        }
      }
    }
  }
  
  printf("%02d/%02d/%04d", older_d, older_m, older_a);
  
  return 0;
}
```
