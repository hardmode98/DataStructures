#include<stdio.h>
int main(){
	int array[5] = {1,2,3,4,5};
	
	int index;
	printf("Enter location\n");
	scanf("%d", &index);
	index =index - 1;
	
	for(int i = index; i<4; i++){
		array[i] = array[i+1];
	}
	
	for(int i = 0; i< 4; i++){
		printf("%d ", array[i]);
	}
}
