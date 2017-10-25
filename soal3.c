#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[3];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int hplohan=100,hpkepiting=100;
int flag=0;
void* kolam(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter,time=0,timee=0,menu;
   
    if(pthread_equal(id,tid[0])){
	while(flag!=1){
		printf("\nMenu Kolam Aidil:\n1. Beri makan lohan\n2. Beri makan kepiting\n");scanf("%d",&menu);
		if(flag==1)return 0;		
		switch(menu){
		case 1:
			printf("Status Lohan sebelum : %d\n",hplohan);
			hplohan+=10;
			printf("Status Lohan sesudah : %d\n",hplohan);
			if(hplohan>100 ||flag==1){
			printf("GameOver\n");
			flag=1;
			return 0;
			}		
			break;
		case 2:			
			printf("Status Kepiting sebelum : %d\n",hpkepiting);
			hpkepiting+=10;
			printf("Status Kepiting sesudah : %d\n",hpkepiting);		
			if(hpkepiting>100 ||flag==1){
			flag=1;
			printf("GameOver\n");
			return 0;
			}			
			break;
		default:
			printf("Tidak ada menu itu bos~\n");		
		}
	}
    }
    else if(pthread_equal(id,tid[1])){
        while(1){
	sleep(10);	
	hplohan-=15;
	time=1;
	if(flag==1)
	return 0;
	else if(hplohan <=0 || hplohan>100){
	 printf("Lohan mati kelaparan,GameOver\n");
	 flag=1;
	 return NULL;
    	 }
        }
    }
    else if(pthread_equal(id,tid[2])){
    	while(1){
	sleep(20);	
	hpkepiting-=10;
	timee=1;
	if(flag==1)
	return 0;	
	else if(hpkepiting <=0 ||hpkepiting>100){
	 printf("Kepiting mati kelaparan,GameOver\n");
	 flag=1;
	 return 0;
	 }
	}
    }
    return NULL;
}

int main(void)
{
    int i=0;
    int err;
    while(i<3)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&kolam,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        /*else
        {
            printf("create thread success\n");
        }*/
        i++;
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    return 0;
}
