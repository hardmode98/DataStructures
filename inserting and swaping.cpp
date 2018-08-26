#include<stdio.h>
int main(){
	int array[5] = {1,2,3,4,5};
	
	int index ;
	int value = 10;
	printf("Enter location \n");
	scanf("%d", &index);
	index -= 1;
	
	for(int i = 4; i> index; i--){
		array[i] = array[i-1];	
	}
	array[index] = value;
	
	for(int i = 0; i< 5; i++){
		printf("%d ", array[i]);
	}
}
