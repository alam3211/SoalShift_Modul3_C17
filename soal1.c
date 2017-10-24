#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
        key_t key = 1234;
        int *value,menu,i;
	char weapon[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	char tweapon[10];
	int stock[6]={0,0,0,0,0,0};
	int tstock;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        *value = 10;

        printf("KUY JUAL SENJATA (penjual) : %d\n", *value);
	printf("1. Lihat Stock Senjata \n 2. Tambah Stock Senjata\n");
	while(1){	
	scanf("%d",&menu);
        switch(menu){
	case 1:
	for(i=0;i<=5;i++){
		 printf("%s stock %d\n", weapon[i], stock[i]);
		}
		break;
	
	case 2:
	scanf("%s %d", tweapon, &tstock);
	for(i=0;i<=5;i++){
		if(strcmp(tweapon, weapon[i])==0){
			stock[i]+=tstock;
		}			
	}
	break;
		default:
		printf("MENU GAADA CUY HEHE\n");		
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
		}
	}
}
