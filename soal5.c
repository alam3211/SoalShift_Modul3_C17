#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[100];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int t=0;
char kata[100][5];
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
	FILE *FileIn;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
    while (pthread_equal(id,tid[t])){
	int count=0;
	FileIn = fopen("novel.txt", "r");
	while((read = getline(&line, &len, FileIn)) != -1) {
		if (strstr(line,kata[t]) != NULL)
		count++;
	}
	fclose(FileIn);
	printf("%s : %d kata",kata[t],count);
	t++;
    }
    return NULL;
}
int main(void)
{
    int i=0;
    char cari[5];
    int err,n;
    
    scanf("%s",cari);
    while(cari!="EXIT" || cari !="exit")//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
	strcpy(kata[i],cari);
        i++;
	t++;
    }
    i=0;
    while(i<t){
    pthread_join(tid[i],NULL);
    i++;
    }
    return 0;
}
