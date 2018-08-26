#include<stdio.h>
int main()
{
	int sampleArray[] = {1,4,2,5,3,2,4,5,4,8,5,1,5,4,4,15,4,5};
	for(int i = 0; i<18 ; i++){
		for(int j = 0; j<18; j++){
			if(sampleArray[j] > sampleArray[j+1]){
				int temp = sampleArray[j];
				sampleArray[j] = sampleArray[j+1];
				sampleArray[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i<18; i++){
		printf("%d ", sampleArray[i]);
	}
}
