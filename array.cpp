#include<stdio.h>
int main(){
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int arrEven[9];
	int arrOdd[9];
	for(int i = 0; i<9; i++){
		if(arr[i]%2 == 0){
			arrEven[i] = arr[i];
			printf("%d", arrEven[i]);
			printf("\n");
		}
	}
	for(int i = 0; i<9; i++){
		if(arr[i]%2 != 0){
			arrOdd[i] = arr[i];
			printf("%d",arrOdd[i]);
		}
	}
}
