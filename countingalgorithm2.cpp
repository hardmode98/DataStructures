#include<stdio.h>
int main(){
	int sampleArray[] = {1,2,1,2,5};
	int countArray[5];
	
	for(int i = 0; i<5 ; i++){
		for(int j = 0; j<5 ; j++){
			if(sampleArray[j] > sampleArray[j+1]){
				int temp = sampleArray[j];
				sampleArray[j] = sampleArray[j+1];
				sampleArray[j+1] = temp;
			}
		}
	}
	for(int i = 0; i<5; i++){
		printf("%d ", sampleArray[i]);
	}
	
	int number = 1;
	int count = 0;
	//i= 0,1,2,3,4
	//  {1,1,2,2,5}
	
	for(int i = 0; i<5; i++){
		if(number == sampleArray[i]){
			count++;
		}else{
			countArray[number] = count;
			printf("\n%d count: %d\n", number, count);
			number++;
			count = 0;
		}
	}
}
