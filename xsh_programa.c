// mut.c - mut, operar  

#include <xinu.h>




void operar(void), incrementar(void), mutex_lock(int pid),  mutex_unlock(int pid);

unsigned char x =0;
sid32 sem;
int pidSem;
void mutex_init(){
    sem= semcreate(1);
}
void mutex_lock(int pid){
    pidSem= pid;
    wait(sem);
}
void mutex_unlock(int pid){
    if(pid == pidSem){
        signal(sem);
    }
}



void xsh_programa(void){    

    mutex_init();
    resume(create(operar, 1024,20,"process 1", 0));
    resume(create(incrementar, 1024,20,"process 2", 0));

    sleep(10);
}

void operar(void){
    int y=0;
    printf("si no existen mensajes de ERROR entonces va OK! \n");
    while(1){
        /*si x es multiplo de 10*/
        mutex_lock(currpid);
        if((x%10)==10){
            y=x*2;

            if((y %10) !=0){
                printf("\r ERROR !! y= %d, x=%d \r, y, x");
            }
        }
        mutex_unlock(currpid);
    }
}

void incrementar (void){
    while(1){
        mutex_lock(currpid);
        x=x+1;
        printf("\n x: %d", x);
        mutex_unlock(currpid);
    }
}





