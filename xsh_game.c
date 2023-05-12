//#include <stdio.h>
//#include <stdlib.h> // system ("/bin/stty raw");
//#include <string.h>
#include <xinu.h>

	
shellcmd xsh_game(void){
	char c;
	int intentos=5;
	int int_acert=0;
	char palabra[]="___";
	char pal[]= "leo";
	int pal_leng= strlen(pal);
	int acerto= 0;
	/* Decirle al sistema que el modo input es RAW */
	
	
	//system ("/bin/stty raw");
	control(0,TC_MODER,0,0);
	
	
	while(1) {
		printf("\r                                                              " );
		printf("\r c = %c  ingrese una letra (0 para salir): %s intentos: %d",c,palabra,intentos);
		acerto=0;
		c = (char)getchar();
		
		for(int i=0; i< pal_leng; i++ ){
			if(c == pal[i]){
			palabra[i]= c;
			pal[i]= '#';
			int_acert++;
			acerto=1;
			}
	
		}
		if(!acerto){
			intentos--;
		}
		
		
		if ( int_acert == pal_leng){
			printf("\n you  win the word was:  %s!!\n", palabra);
				break;
		}
		if(intentos == 0){
			printf("\n perdiste\n");
			
			break;
		}
		
	}

	//system ("/bin/stty sane erase ^H");
	control(0,TC_MODEC,0,0);

	//system ("/bin/stty raw");
}
