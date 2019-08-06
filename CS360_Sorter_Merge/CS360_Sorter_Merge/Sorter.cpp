// CS360 Merge Sort
// Spring 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY 32769
#define NUM_AVG 1              // Number of sorting runs to average
#define MAX_ELEMENTS 65537     // Maximum number of elements in input array
#define MAX_RANGE 1024        // Maximum value of input elements
#define MAX_RUNS 13             // Maximum number of input sizes to run
#define NUM_SORTS 1            // Number of sorting algorithms
#define MERGESORT 0

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

			// Merge sort
			copy_array(A,D);
//			print_array(A);
			count = 0;
			counter[MERGESORT][i] += (merge_sort(A,1,length(A))/((double) NUM_AVG));
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

/* Merge sort routine(s) */
int merge_sort(int A[], int p, int r)
{
	int q;

	/* TODO: add MERGE-SORT() code */
	if (p < r){
		q = (p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
	return count;
}

void merge(int A[], int p, int q, int r)
{
	int *L, *R;
	int n1=0,n2=0;
	int i,j,k;

	n1 = q-p+1;
	count++;
	n2 = r-q;
	count++;

	L = (int*) malloc((n1+2)*sizeof(int));
	count++;
	R = (int*) malloc((n2+2)*sizeof(int));
	count++;

	/* TODO: add MERGE() code */
	for (int i = 1; i<n1; i++){
		count++;
		L[i] = A[p+i-1];
		count++;
	}
	count++;
    for (int j = 1; j<n2; j++){
		count++;
		R[j] = A[q+j];
		count++;
    }
	count++;
    L[n1+1] = INFINITY;
	count++;
    R[n2+1] = INFINITY;
	count++;
    i = 1;
	count++;
    j = 1;
	count++;
    for (int k = p; k<r; k++){
		if (L[i] <= R[j]){
			A[k] = L[i];
			count++;
			i = i + 1;
			count++;
		}
		else{
			A[k] = R[j];
			count++;
			j = j + 1;
			count++;
		}
		count++;
	}
	count++;
	
	free(L);
	free(R);
}

