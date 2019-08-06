// CS360 Insertion Sort
// Spring 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY 32769
#define NUM_AVG 10              // Number of sorting runs to average
#define MAX_ELEMENTS 65537     // Maximum number of elements in input array
#define MAX_RANGE 1024        // Maximum value of input elements
#define MAX_RUNS 13             // Maximum number of input sizes to run
#define NUM_SORTS 1            // Number of sorting algorithms
#define INSERTIONSORT 0

void make_array(int D[], int n);
void copy_array(int A[],int D[]);
void print_array(int A[]);
int length(int A[]);
int insertion_sort(int A[]);
int merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int count;

int main(void)
{
	int A[MAX_ELEMENTS],B[MAX_ELEMENTS],D[MAX_ELEMENTS];
	int n,i,j,k;
	double counter[NUM_SORTS][MAX_RUNS];

	srand(0);
	// Initialize counter array
	for (i=0; i<NUM_SORTS; i++)
	{
		for (j=0; j<MAX_RUNS; j++)
		{
			counter[i][j] = 0.0;
		}
	}

	// Set number of elements in initial array and run counter
	n = 16;
	i = 0;

	// Loop for each input size
	while ((n <= MAX_ELEMENTS) && (i < MAX_RUNS))
	{
		// Loop with random input arrays of fixed size to average results
		for (j=0; j<NUM_AVG; j++)
		{
			// Generate random array of size n
			make_array(D,n);

			// Insertion sort
			copy_array(A,D);
//			print_array(A);
			count = 0;
			counter[INSERTIONSORT][i] += (insertion_sort(A)/((double) NUM_AVG));
//			print_array(A);
		}

		// Double number of input elements for next run
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

/* Insertion sort routine */
int insertion_sort(int A[])
{
	int i, j, key;

	/* TODO: add INSERTION-SORT() code */
	for (j = 2; j<=length(A); j++){
		count++;
		key = A[j];
		count++;
		// Insert A[j] into the sorted sequence A[1..j-1]
		i = j - 1;
		count++;
		while (i > 0 and A[i] > key){
			count++;
			A[i+1] = A[i];
			count++;
			i = i - 1;
			count++;
		}
		count++;
		A[i+1] = key;
		count++;
	}
	count++;
	return count;
}


