#include<stdio.h>
int main(){
	int array[5] = {1,2,3,4,5};
	int searchNum;
	int flag = 0;
	int location;
	int i;
	
	printf("Enter the number that is to be searched \n");\
	scanf("%d", &searchNum);
	for(i = 0; i<5; i++){
		if(array[i] == searchNum){
			flag = 1;
			location = i;
			break;
		}
	}
	if(flag == 0){
		printf("not found");
	}else if(flag == 1){
		printf("found, location = %d", (location+1));
	}
}
