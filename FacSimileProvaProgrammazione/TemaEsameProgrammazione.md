# Question 1
```c
scanf("%d", &n);
```
```c
if (n > 0) printf("La variabile è positiva");
```
```c
for (i = 1; i <= n; i++) printf("%d", i);
```
# Question 2
```c
#include "stdio.h"

int main(void)
{
	int x = 0, n, occorrenze = 0;
	
	do
	{
		scanf("%d", &x);
	}
	while( x <= 0 || x > 20);

	for (int i = 0; i < 100; i++)
	{
		n = rand() % 20 + 1;
		printf("%3d ", n);
		if (x == n) occorrenze++;
	}
	
	printf("Occorrenze: %d", occorrenze);
	return 0;
}
```

# Question 3
```c
#include "stdio.h"

int quantitaDivisori(int n)
{	
	int divisori = 2, i;
	
	for (i = 2; i < n; i++)
			if (n % i == 0) divisori++;
	
	return divisori;
}

int main()
{
	int n, divisori;
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &n);
		printf("%d\n", quantitaDivisori(n));
	}

	return 0;
}
```

# Question 4
```c
#include "stdio.h"

void calcolaPotenze(int vettore[], int n)
{
	int i, j, risultato;
	for (i = 0; i < n; i++)
	{
		risultato = 1;
		for (j = 0; j < vettore[i]; j++) risultato = risultato * 2;
		printf("%d\n", risultato);
	}
}

int main(void)
{
	int vettore[5], i;
	
	for (i = 0; i < 5; i++) scanf("%d", &vettore[i]);
	calcolaPotenze(vettore, DIM);
	
	return 0;
}
```

# Question 5
```c
#include "stdio.h"

typedef struct {
	int d, m, y;
}
Date;

int precede(Date date1, Date date2)
{
	if(date1.y < date2.y) return 1;
	if(date1.m < date2.m) return 1;
	if(date1.d < date2.d) return 1;
	return 0;
}

int numDatePrecedenti(Date array[],int n, Date date)
{
	int i, numDate = 0;
	for (i = 0; i < n; i++)
		if(precede(array[i], date)) numDate++;

	return prec;
}

int main(void)
{
	int i;
	Date array[10];

	for (i = 0; i < 10; i++) scanf("%d-%d-%d", &array[i].d, &array[i].m, &array[i].y);
	printf("%d\n", numDatePrecedenti(array, 10, array[9]);

	return 0;
}
```