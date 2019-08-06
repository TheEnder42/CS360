// CS360 Heapsort and Quicksort
// Spring 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY 32769
#define NUM_AVG 10
#define MAX_ELEMENTS 65537
#define MAX_RANGE 1024//32768
#define MAX_RUNS 13 //rerun cuz this changed
#define NUM_SORTS 2
#define HEAPSORT 0
#define QUICKSORT 1

void make_array(int D[], int n);
void copy_array(int A[],int D[]);
void print_array(int A[]);
int length(int A[]);
int heapsort(int A[]);
void build_max_heap(int A[]);
void max_heapify(int A[], int i, int heap_size);
int quicksort(int A[], int p, int r);
int partition(int A[], int p, int r);

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

			// Heap sort
			copy_array(A,D);
//			print_array(A);
			count = 0;
			counter[HEAPSORT][i] += (heapsort(A)/((double) NUM_AVG));
//			print_array(A);

			// Quick sort
			copy_array(A,D);
//			print_array(A);
			count = 0;
			counter[QUICKSORT][i] += (quicksort(A,1,length(A))/((double) NUM_AVG));
//			print_array(A);
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

/* Heap sort routine(s) */
int heapsort(int A[])
{
	int heap_size,i,temp;
	heap_size = length(A);
	count++;

	/* TODO: add HEAPSORT() code */
	for(int i = length(A); i>1/*1?*/; i--){
		count++;
		
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		count++;
		
		heap_size--;
		count++;
		
		max_heapify(A, i, heap_size);
	}

	return count;
}

void build_max_heap(int A[])
{
	int heap_size,i;

	/* TODO: add BUILD-MAX-HEAP() code */
	heap_size = length(A);
	count++;
	
	for(int i = length(A)/2; i>0/*1?*/; i--){
		count++;
		max_heapify(A, i, heap_size);
	}
	count++;
	
	return;
}

void max_heapify(int A[], int i, int heap_size)
{
	int l,r,largest,temp;

	/* TODO: add MAX-HEAPIFY() code */
	l = i*2;
	count++;
	r = i*2+1;
	count++;
	
	if(l<=heap_size && A[l]>A[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	count++;
	
	if(r<=heap_size && A[r]>A[largest]){
		largest = r;
	}
	count++;
	
	if(largest != i){
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		count++;
		
		max_heapify(A, largest, heap_size);
	}
	count++;

	return;
}

/* Quick sort routine(s) */
int quicksort(int A[], int p, int r)
{
	int q;

	/* TODO: add QUICKSORT() code */
	if(p<r){
		q = partition(A, p, r);
		count++;
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
	count++;

	return count;
}

int partition(int A[], int p, int r)
{
	int i;
	int x,j,temp;

	/* TODO: add PARTITION() code */
	x = A[r];
	count++;
	i = p - 1;
	count++;
	
	for(int j = p; j < r-1; j++){
		count++;
		if(A[j] <= x){
			i++;
			count++;
			
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			count++;
		}
		count++;
	}
	count++;
	
	temp = A[r];
	A[r] = A[i+1];
	A[i+1] = temp;
	count++;

	return (i+1);
}
