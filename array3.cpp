#include<stdio.h>
int main(){
	int arr[5]={1,2,3,4,5};
	int temp1,temp2;
	
	for(int i = 5; i>0 ;i--){
		temp1 = arr[i];
		arr[i] = arr[i-1];
		arr[i-1]=temp1;
		for(int i = 0; i<5 ; i++){
		for(int i = 0; i<5; i++){
			temp2= arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp2;
			printf("%d ", arr[i]);
		}
		
			printf("\n");
		}
	}
}
