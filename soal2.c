#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t player1;
pthread_t player2;
int nomor1[16],nomor2[16], point[2]={0,0};
int mengisi, menebak, turn=1;
 
void* play1(void *arg)
{	
	
	int i, j;
    	printf("\n---player1 mengisi ranjau---\n");
	for(i=1;i<=4;i++){
		scanf("%d", &mengisi);		
		if(mengisi<=16) nomor1[mengisi]=1;
		else break;	
	}

	printf("\n---player2 menebak ranjau---\n");
	for(j=1;j<=4;j++){
		scanf("%d", &menebak);		
		if(nomor1[menebak]==1){
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
    	
	printf("\nPoint player1= %d\n", point[1]);
	printf("Point player2= %d\n", point[2]);
	turn=2;	
}


void* play2(void *arg)
{
	int i, j;	
	printf("\n---player2 mengisi ranjau---\n");
	for(i=1;i<=4;i++){
		scanf("%d", &mengisi);		
		if(mengisi<=16) nomor2[mengisi]=1;
		else break;
	}

	printf("\n---player1 menebak ranjau---\n");
	for(j=1;j<=4;j++){
		scanf("%d", &menebak);		
		if(nomor2[menebak]==1){
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

	printf("\nPoint player1= %d\n", point[1]);
	printf("Point player2= %d\n", point[2]);
	turn=1;
}
 
int ceklubang(){
	int i;
	for(i=1;i<=16;i++){
		if(nomor1[i]==0||nomor2[i]==0) return 0;	
	}
	return 1;	
}

int main(){	
	
	while(1){
		//printf("---turn %d---\n", turn);
		if(turn==1) pthread_create(&(player1), NULL, &play1, NULL);
    		else if(turn==2) pthread_create(&(player2), NULL, &play2, NULL);
		pthread_join(player1, NULL);
    		pthread_join(player2, NULL);
		
		if(point[1]>=10){
			printf("\n---player1 menang---\n");
			break;		
		}else if(point[2]>=10){
			printf("\n---player2 menang---\n");
			break;		
		}else if(ceklubang()==1){
			printf("\n---lubang penuh---\n");
			break;
		}		
 	}
   	
    	return 0;
}
