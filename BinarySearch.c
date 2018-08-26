//Binary Search
#include<stdio.h>
int array[5] = {1,3,5,7,9};
int binarySearch(int size, int x)
{
	int start = 0;
	int end = size - 1;
	
	int mid = (start + end)/2;
	
	while(start <= end){
		if(array[mid] == x){
			return mid;
		}else if(array[mid] > x){
			end = mid - 1;
			mid = (start + end)/2;
		}else{
			start = mid + 1;
			mid = (start + end)/2;
		}	
	}
	return -1;
}

int main()
{
	int x = binarySearch(5, 3);
	if(x == -1){
		printf("Not found\n");
	}else{
		printf("Found at index : %d", x);
	}
}
