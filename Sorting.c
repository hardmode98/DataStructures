#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[]);
void merge(int arr[], const int left[] , const int right[] , int length_left, int length_right);
void mergeSort(int arr[] , int length_of_array);
void qs(int arr[] , int start, int end);
void heapSort(int arr[] , int n);
void partition();
void selectionSort(int arr[] , int size);
void shellsort(int arr[], int num);

int main() {
    int arr[] = {3,1,2,4,6,5};
    int length_of_array= sizeof(arr) / sizeof(arr[0]);

    shellsort(arr ,length_of_array);

    for (int i = 0; i < length_of_array ; ++i) {
        printf("%d" , arr[i]);
    }
}

void insertion_sort(int arr[]){

    int value =0;
    int hole=0;
    for (int i = 1; i < 7 ; i++) {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole-1] > value){
            arr[hole] = arr[hole-1];

            hole = hole-1;
        }

        arr[hole] = value;
    }

}

void merge (int arr[] , const int left[] , const int right[] , int length_left , int length_right ){

   int i = 0, j=0 ,k =0;
   while (i <length_left && j <length_right){
       if (left[i] < right[j]){
           arr[k] = left[i];
           i++;
       }else {
           arr[k] = right[j];
           j++;
       }

       k++;
   }

   while (i<length_left){
       arr[k] =  left[i];
       k++;
       i++;
   }

   while (j<length_right){
       arr[k] = right[j];
       j++;
       k++;
   }

}

void mergeSort(int arr[] , int length_of_array){

    if (length_of_array < 2) return;

    int mid = length_of_array/2;

    int left[mid] , right[length_of_array-mid];

    for (int i = 0; i < mid ; ++i) {
        left[i] = arr[i];
    }

    for (int j = mid; j < length_of_array ; ++j) {
        right[ j -mid] = arr[j];
    }

    mergeSort(left , mid);
    mergeSort(right ,length_of_array-mid);
    merge(arr ,left ,right , mid , length_of_array-mid);

}

int part(int arr[] ,int start , int end){

    int pivot = arr[end];
    int pivot_pos = start;

    int temp=0 , temp1=0;

    for (int i = start; i < end ; ++i) {

        if (arr[i] <= pivot){
        temp = arr[i];
        arr[i] = arr[pivot_pos];
        arr[pivot_pos] = temp;
        pivot_pos++;

        }
    }

    temp1 = arr[pivot_pos];
    arr[pivot_pos]= arr[end];
    arr[end] = temp1;

    return pivot_pos;
    }

void qs (int arr[] , int start , int end){

    if (start < end){

        int pi = part(arr, start ,end);
        qs(arr , start , pi-1);
        qs(arr , pi+1 , end);
    }
}

void heapify(int array[] , int size , int root){

    int largest = root;
    int left = 2 * root +1;
    int right = 2*root +2;

    if (left < size && array[largest] < array[left]){
        largest = left;
    }

    if (right < size && array[largest] < array[right]){
        largest = right;
    }

    if (largest != root){

        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        heapify(array , size , largest);

    }
}


// main function to do heap sort
void heapSort(int arr[], int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void selectionSort(int arr[], int size){

    for (int i = 0; i < size-2; i++) {

        int minIndex = i;

        for (int j = i+1; j <size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        //swap for every iteration finding smallest number and then swapping
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

    }
}

void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = 0; j < num; j++) {

            if (arr[j] > arr[i + j]){

                int temp = arr[j];
                arr[j] = arr[i+j];
                arr[i+j] = temp;

            }
        }
    }
}