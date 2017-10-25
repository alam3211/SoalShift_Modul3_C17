#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t player1;
pthread_t player2;
int nomor[2][16], point[2]={0,0};
int i, j, turn=1;
int mengisi, menebak;
 
void* tulis(void *arg)
{
	turn=2;
    	printf("---player1 mengisi ranjau---\n");
	for(i=1;i<=4;i++){
		scanf("%d", &mengisi);		
		if(mengisi<=16) nomor[1][mengisi]=1;
		else break;	
	}

	printf("---player2 menebak ranjau---\n");
	for(j=1;j<=4;j++){
		scanf("%d", &menebak);		
		if(nomor[1][menebak]==1){
			point[2]+=1;
			printf("ada ranjau\n");
			printf("Point player2= %d\n", point[2]);
		}
		else{
			point[1]+=1;
			printf("gak ada ranjau\n");
			printf("Point player1= %d\n", point[1]);
		}
		//printf("j %d\n", j);	
	}
    	
	printf("Point player1= %d\n", point[1]);
	printf("Point player2= %d\n", point[2]);	
}


void* baca(void *arg)
{
	turn=1;
	printf("---player2 mengisi ranjau---\n");
	for(i=1;i<=4;i++){
		scanf("%d", &mengisi);		
		if(mengisi<=16) nomor[2][mengisi]=1;
		else break;	
	}

	printf("---player1 menebak ranjau---\n");
	for(j=1;j<=4;j++){
		scanf("%d", &menebak);		
		if(nomor[2][menebak]==1){
			point[1]+=1;
			printf("ada ranjau\n");
			printf("Point player1= %d\n", point[1]);
		}
		else{
			point[2]+=1;
			printf("gak ada ranjau\n");
			printf("Point player2= %d\n", point[2]);		
		}
		//printf("j %d\n", j);	
	}

	printf("Point player1= %d\n", point[1]);
	printf("Point player2= %d\n", point[2]);
}
 
int main(void){

/*	for(i=1;i<=16;i++){
		printf("%d ", nomor[1][1]);
		printf("%d ", nomor[2][2]);
		printf("%d\n", i);	
	}	
*/	
	printf("Point player1= %d\n", point[1]);
	printf("Point player2= %d\n", point[2]);
	
	while(1){
		if(turn==1) pthread_create(&(player1), NULL, &tulis, NULL);
    		else if(turn==2) pthread_create(&(player2), NULL, &baca, NULL);
		pthread_join(player1, NULL);
    		pthread_join(player2, NULL);
 	}
   
    	return 0;
}
