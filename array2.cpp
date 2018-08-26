#include<stdio.h>
int main(){
	int arr[5]={1,2,3,4,5};
	int temp;
	for(int i = 0; i<5 ; i++){
		for(int i = 0; i<5; i++){
			temp= arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			printf("%d ", arr[i]);
		}
		
		printf("\n");
	}
}
