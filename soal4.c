#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid[100];
 
void* calc(void *input){
 	
	char *c;
	c=(char*)input;	//convert input ke char
	int num=*c-'0';	//convert char ke int
	int i, hasil=1;
	for(i=2;i<=num;i++){
		hasil*=i;
		//printf("hasil %d\n", hasil);	
	}
	printf("hasil %d! = %d\n", num, hasil);
}
 
int main(int jumlah, char **input){

	int i;	
	//printf("jumlah %d input %c\n", jumlah, *input[2]);

    	for(i=1;i<jumlah;i++){
		//printf("test\n");
		pthread_create(&(tid[i]), NULL, calc, (void*) input[i]);
		pthread_join(tid[i], NULL);	
	}
    
 
    return 0;
}
