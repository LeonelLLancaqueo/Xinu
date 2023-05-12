#include <xinu.h>

void produce(void), consume(void);

/* global variable */
int32 n=0; 
sid32 sem1,sem2;


shellcmd xsh_productorConsumidor(void){

    sem1= semcreate(1);
    sem2= semcreate(0);

    resume(create(consume,1024,20,"cons",0));
    resume(create(produce,1024,20,"prod",0));

}

void produce(void){
    int32 i;
    for(i=0; i<=2000; i++){
        wait(sem1);
        n++;
        signal(sem2);
    }
}
void consume(void){
    int32 i;
    for(i=0; i<=2000; i++){
        wait(sem2);
        printf("the value of n is %d \n", n);
        signal(sem1);
    }
}