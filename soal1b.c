#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
        key_t key = 1243;
	int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
        int* stock;
        int menu,i,tstock;
	char weapon[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	char tweapon[10];
	stock=(int*)shmat(shmid, NULL, 0);
	
        printf("KUY BELI SENJATA (pembeli) : ");
	printf("\n1. Lihat Stock Senjata\n2. Beli Senjata\n3. Keluar\n");
	while(1){
	
	scanf("%d",&menu);
        switch(menu){
	case 1:
	for(i=0;i<=5;i++){
		printf("%s stock %d\n", weapon[i],stock[i]);		
	}
	break;
	
	case 2:
	scanf("%s %d", tweapon, &tstock);
	for(i=0;i<=5;i++){
		if(strcmp(tweapon, weapon[i])==0){
			if(tstock>stock[i]) printf("Belinya kebanyakan mas,stock gacukup\n");
			else stock[i]-=tstock;			
		}
	}
	break;
	case 3:
	return 0;
	default:
	printf("MENU GAADA CUY HEHE\n");		
        
       		}
	}
	shmdt(stock);
        shmctl(shmid, IPC_RMID, NULL);
}
