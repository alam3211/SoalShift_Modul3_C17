#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main(){
	
	key_t key = 1234;
        int *value,menu,i;
	char weapon[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	char bweapon[10];
	int stock[6]={50,0,0,0,0,0};
	int bstock;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        *value = 10;

        printf("KUY JUAL SENJATA (penjual) : %d\n", *value);
	printf("1. Lihat Stock Senjata\n2. Beli Senjata\n");
	while(1){	
	scanf("%d",&menu);
        switch(menu){
	case 1:
	for(i=0;i<=5;i++){
		printf("%s stock %d\n", weapon[i], stock[i]);
	}
	break;
	
	case 2:
	scanf("%s %d", bweapon, &bstock);
	for(i=0;i<=5;i++){
		if(strcmp(bweapon, weapon[i])==0){
			if(stock[i]>=bstock){
				//printf("test\n");
				stock[i]-=bstock;
			}else printf("barang di stock tidak cukup\n");
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
