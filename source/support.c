#include "support.h"
#include <stdio.h>
#include <string.h>

/*
 * NOTE - Modificação
 * Motivo: toupper() não declarado
 * Diff: ø → #include <ctype.h>
 */
#include <ctype.h>

/* Manipulate the path to lead com name, extensions and special characters */
char* padding(char *filename){


//	char output[11];

	// TODO: Add wrapper around this so that it isn't so fucking egregious
	/*
	 * NOTE - Modificação
	 * Motivo: Retornando por ponteiro variável de Stack
	 *         Guardando 12 bytes em array de 11.
	 * diff: char output[11] → static char output[12]
	 */
	static char output[12];
    char* strptr = filename;
    char* dot;
    dot = strchr(filename, '.');

    int i;
    for(i=0; strptr != dot; strptr++, i++){
    	if(i==8)
    		break;
    	output[i] = *strptr;
    }

    int trail = 8 - i;
    for(; trail > 0; trail--, i++){
    	output[i] = ' ';
    }

    strptr = dot;
    strptr++;
    for(i=8; i < 11; strptr++, i++){
    	output[i] = *strptr;
    }

    output[11] = '\0';
    for(i = 0; output[i] != '\0'; i++){
    	output[i] = toupper(output[i]);
    }
    
    char* out = output;
    return out;

}
