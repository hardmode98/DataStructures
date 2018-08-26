#include<stdio.h>

int main()
{
	int sampleArray[] = {11,22,15,22,14,45,45,78,23,45,78,122,45,788,23,654};
	
	int count = 0;
	
	for(int i = 0; i<16; i++){
		for(int j = 0; j<16; j++){
			int currentNumber = sampleArray[i];
			if(currentNumber == sampleArray[j]){
				count++;
			}
		}
		
		printf("|||%d count is: %d|||\n",sampleArray[i], count);
		count = 0;
	}
	
}
