// CS360 Counting Sort
// Spring 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_AVG 10
#define MAX_ELEMENTS 65537
#define MAX_RANGE 1024//32768
#define MAX_RUNS 13
#define NUM_SORTS 1
#define COUNTINGSORT 0

void make_array(int D[], int n);
void copy_array(int A[],int D[]);
void print_array(int A[]);
int length(int A[]);
int countingsort(int A[], int B[], int k);

int count;

int main(void)
{
	int A[MAX_ELEMENTS],B[MAX_ELEMENTS],D[MAX_ELEMENTS];
	int n,i,j,k;
	double counter[NUM_SORTS][MAX_RUNS];

	srand(0);
	for (i=0; i<NUM_SORTS; i++)
	{
		for (j=0; j<MAX_RUNS; j++)
		{
			counter[i][j] = 0.0;
		}
	}

	n = 16;
	i = 0;
	while ((n <= MAX_ELEMENTS) && (i < MAX_RUNS))
	{
		for (j=0; j<NUM_AVG; j++)
		{
			// Generate random array of size n
			make_array(D,n);

			// Counting sort
			copy_array(A,D);
			print_array(A);
			count = 0;
			counter[COUNTINGSORT][i] += (countingsort(A, B, MAX_RANGE)/((double) NUM_AVG));
			B[0] = length(A);
			print_array(B);
		}

		n *= 2;
		i++;
	}

	/* Print avg runtime results */
	n = 16;
	for (k=0; k<i; k++)
	{
		printf("n = %i ",n); 
		for (j=0; j<NUM_SORTS; j++)
		{
			printf("%.0lf ",counter[j][k]);
		}
		printf("\n");
		n *= 2;
	}

	int key;
	printf("Enter a value to quit");
	scanf("%d",&key);

	return 0;
}

/* Utility function to create a random B[] array of length n */
void make_array(int D[], int n)
{
	int i;
	D[0] = n;
	for (i=1; i<=n; i++)
	{
		D[i] = rand()%MAX_RANGE + 1;
	}
}

/* Utility function to copy B[] -> A[] */
void copy_array(int A[], int D[])
{
	int i;
	for (i=0; i<=D[0]; i++)
	{
		A[i] = D[i];
	}
}

/* Utility function to print sorted A[] array */
void print_array(int A[])
{
	int i;
	for (i=1; i<=length(A); i++)
	{
		printf("%i ",A[i]);
	}
	printf("\n");
}

/* Utility function to get array length */
int length(int A[])
{
  return A[0];
}

/* Counting sort routine(s) */
int countingsort(int A[], int B[], int k)
{
	int i, j;

	int *C = (int *) malloc((k+1)*sizeof(int));//what is this?
	count++;

	/* TODO: add COUNTINGSORT() code */
//	C = new int[k+1]();
	for(i = 0; i<=k; i++){
		count++;
		C[i]=0;
		count++;
	}
	count++;
	for(j = 1; j<=length(A); j++){
		count++;
		C[A[j]] = C[A[j]] + 1;
		count++;
	}
	count++;
	for(i = 1; i<=k; i++){
		count++;
		C[i] = C[i] + C[i-1];
		count++;
	}
	count++;
	for(j = length(A); j>=1; j--){
		count++;
		B[C[A[j]]] = A[j];
		count++;
		C[A[j]] = C[A[j]] - 1;
		count++;
	}
	count++;
	
	free(C);
	return count;
}