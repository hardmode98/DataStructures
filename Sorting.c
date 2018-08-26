//Sorting Algorithms
#include<stdio.h>
int array[5] = {7,9,5,2,13};
void bubbleSort(int size)
{
	int i, j;
	for (i = 0; i < size; i++){
		for(j = 0; j < (size - 1) - i; j++){
			if(array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}
void selectionSort(int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++){
		int iMin = i;
		for(j = i + 1; j < size; j++){
			if(array[iMin] > array[j]){
				iMin = j;
			}
		}
		int temp = array[i];
		array[i] = array[iMin];
		array[iMin] = temp; 
	}
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}
void insertionSort(int size)
{
	int i;
	for(i = 1; i < size - 1; i++){
		int value = array[i];
		int hole = i;
		while(hole > 0 && array[hole - 1] > value){
			array[hole] = array[hole - 1];
			hole--;
		}
		array[hole] = value;
	}
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}
void merge(int A[], int low, int mid, int high)
{
	int i, j , k;
	int n1 = (mid - low)+ 1;
	int n2 = high - mid;
	
	int L[n1];
	int R[n2];
	
	for(i = 0; i < n1; i++){
		L[i] = A[low + i];
	}
	
	for(j = 0; j < n2; j++){
		R[j] = A[mid + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = low;
	
	while(i < n1 && j < n2){
		
		if(L[i] <= R[j]){
			
			A[k] = L[i];
			i++;
			
		}else{
			
			A[k] = R[j];
			j++;
			
		}
	
		k++;
	}
	while(i < n1){
	
		A[k] = L[i];
		i++;
		k++;
		
	}
	while(j < n2){
	
		A[k] = R[j];
		j++;
		k++;
		
	}
}
void mergeSort(int arr[], int left, int right){
	
	int i;
	
	if(left < right){
		int m = left + (right - left)/2;
		mergeSort(arr, left, m);
		mergeSort(arr, m+1, right);
		
		merge(arr, left, m, right);
	}
	
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//Partition function for quicksort
int partition(int A[], int start, int end)
{
	int i, temp, temp1;
	int pivot = A[end];
	int partitionIndex = start;
	for(i = start; i < end ; i++){
		if(A[i] <= pivot){
			temp = A[i];
			A[i] = A[partitionIndex];
			A[partitionIndex] = temp;
			partitionIndex++;
		}
	}
	temp1 = A[partitionIndex];
	A[partitionIndex] = A[end];
	A[end] = temp1;
	return partitionIndex;
}
void quickSort(int A[], int start, int end)
{
	if(start < end)
	{
		int partitionIndex = partition(A, start, end);
		quickSort(A, start, partitionIndex - 1);
		quickSort(A, partitionIndex + 1, end);
	}
}
int main()
{
	int i;
	bubbleSort(5);
	printf("\n");
	selectionSort(5);
	printf("\n");
	insertionSort(5);
	printf("\n");
	int A[6] = {4 , 1, 6, 9, 2, 3};
	mergeSort(A, 0, 6-1); //mergeSort(Array, lowest index, size -1)
	printArray(A, 6); // printArray(Array, size)
	quickSort(A, 0, 5);
	printArray(A, 6);
	
}


