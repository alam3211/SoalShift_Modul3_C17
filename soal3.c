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
void* kolam(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter,time=0,timee=0,menu;
   
    if(pthread_equal(id,tid[0])){
	while(1){
		printf("\nMenu Kolam Aidil:\n1. Beri makan lohan\n2. Beri makan kepiting\n");scanf("%d",&menu);
		switch(menu){
		case 1:
			printf("Status Lohan sebelum : %d\n",hplohan);
			hplohan+=10;
			printf("Status Lohan sesudah : %d\n",hplohan);
						
			break;
		case 2:			
			printf("Status Kepiting sebelum : %d\n",hpkepiting);
			hpkepiting+=10;
			printf("Status Kepiting sesudah : %d\n",hpkepiting);		
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
	if(hplohan <=0 || hpkepiting <=0 || hplohan>100 || hpkepiting>100){
	printf("Status lohan : %d , lohan mati\n",hplohan);
	return 0;
	}
    	}
    }
    else if(pthread_equal(id,tid[2])){
    	while(1){
	sleep(20);	
	hpkepiting-=10;
	timee=1;	
	if(hplohan <=0 || hpkepiting <=0 || hplohan>100 || hpkepiting>100){
	printf("Status kepiting : %d , kepiting mati\n",hpkepiting);
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
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    while(1){
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
}
    return 0;
}
