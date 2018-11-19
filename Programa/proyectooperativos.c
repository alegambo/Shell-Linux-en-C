/*	Nombre del archivo:	   proyectooperativos.c			
*	Información de la versión: Se creó en Lenguaje C.		        
*	Fecha:			   Miercoles 28 de Marzo de 2018.			
*	Autores:		   Alejandro Gamboa- Andrés Casasa
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define maxElem 10
char datos[40];
char *com[maxElem];
char aux[maxElem],aux1[maxElem],aux2[maxElem],aux3[maxElem],aux4[maxElem],aux5[maxElem],aux6[maxElem],aux7[maxElem],aux8[maxElem],aux9[maxElem];
char *argumentos[40];
char *token;
int cont;
int estado;
int i,k;
pid_t pid;
int contaIn = 0;
int contaEx = 0;

void agregar(int k) {
    switch(k) {
    case 0:
        strcpy(aux,datos);
        com[k]=aux;
        break;
    case 1:
        strcpy(aux1,datos);
        com[k]=aux1;
        break;
    case 2:
        strcpy(aux2,datos);
        com[k]=aux2;
        break;
    case 3:
        strcpy(aux3,datos);
        com[k]=aux3;
        break;
    case 4:
        strcpy(aux4,datos);
        com[k]=aux4;
        break;
    case 5:
        strcpy(aux5,datos);
        com[k]=aux5;
        break;
    case 6:
        strcpy(aux6,datos);
        com[k]=aux6;
        break;
    case 7:
        strcpy(aux7,datos);
        com[k]=aux7;
        break;
    case 8:
        strcpy(aux8,datos);
        com[k]=aux8;
        break;
    case 9:
        strcpy(aux9,datos);
        com[k]=aux9;
        break;
    default:
        printf("No se ingreso nada");
        break;
    }
}
void historial2(void) {
    if(strcmp(datos,"!1")==0) {
        if(contaEx!=0) {
            printf(com[0],"\n");
            printf("\n");
        }
        else {
            printf("No existe nada en el historial en este momento");
            printf("\n");
        }
    }
    if(strcmp(datos,"!2")==0) {
        if(contaEx!=0) {
            printf(com[1],"\n");
            printf("\n");
        }
        else {
            printf("Solo se ha insertado un comando");
            printf("\n");
        }
    }
    if(strcmp(datos,"!3")==0) {
        if(contaEx!=0) {
            printf(com[2],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 2 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!4")==0) {
        if(contaEx!=0) {
            printf(com[3],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 3 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!5")==0) {
        if(contaEx!=0) {
            printf(com[4],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 4 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!6")==0) {
        if(contaEx!=0) {
            printf(com[5],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 5 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!7")==0) {
        if(contaEx!=0) {
            printf(com[6],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 6 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!8")==0) {
        if(contaEx!=0) {
            printf(com[7],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 7 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!9")==0) {
        if(contaEx!=0) {
            printf(com[8],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 8 comandos");
            printf("\n");
        }
    }
    if(strcmp(datos,"!10")==0) {
        if(contaEx!=0) {
            printf(com[9],"\n");
            printf("\n");
        }
        else {
            printf("Solo se han insertado 9 comandos");
            printf("\n");
        }
    }
}


void historial(void) {
    int i;
    if(contaEx == 0) {
        printf("El historial esta vacio");
        printf("\n");
    }
    else {
        printf("El siguiente es un listado de los ultimos comandos:\n");
        for(i=0; i < 10; i++) {
            printf(com[i],"\n");
            printf("\n");
        }
    }
}

int main() {
    char *aux;

    system("clear");
    printf("Shell linux\n");
    int salir=1;
    while(1) {
        for(i=0; i<40; i++) {
            datos[i]='\0';
            argumentos[i]=NULL;
        }
        k=0;
        printf("\nShell-Gamboa-Casasa:\\>");
        fgets(datos,40,stdin);
        agregar(contaIn);
        while(datos[k]!='\n')
            k++;

        datos[k]='\0';
        for(i=0,token=strtok(datos," "); token!=NULL; token=strtok(NULL," "),i++) {
            cont=strlen(token);
            aux=(char *)malloc(sizeof(char)*cont);
            strcpy(aux,token);
            argumentos[i]=aux;
            if(strcmp(datos,"salir")==0) {
                printf("Digite salir una vez más para salir del Shell \n");
                exit(0);
            }

        }
        pid=fork();
        switch(pid) {
        case -1:
        {
            printf("Error en el fork");
            exit(1);
        }
        case 0: {
            if(strcmp(argumentos[0],"historial")==0) {
                historial();
            }
            if((strcmp(argumentos[0],"!1")==0)||(strcmp(argumentos[0],"!2")==0)||(strcmp(argumentos[0],"!3")==0)
                    ||(strcmp(argumentos[0],"!4")==0)||(strcmp(argumentos[0],"!5")==0)||(strcmp(argumentos[0],"!6")==0)
                    ||(strcmp(argumentos[0],"!7")==0)||(strcmp(argumentos[0],"!8")==0)||(strcmp(argumentos[0],"!9")==0)
                    ||(strcmp(argumentos[0],"!10")==0)) {
                historial2();
            }
            estado=execvp(argumentos[0],argumentos);
            if(estado) {
                if(strcmp(argumentos[0],"!1")!=0) {
                    if(strcmp(argumentos[0],"!2")!=0) {
                        if(strcmp(argumentos[0],"!3")!=0) {
                            if(strcmp(argumentos[0],"!4")!=0) {
                                if(strcmp(argumentos[0],"!5")!=0) {
                                    if(strcmp(argumentos[0],"!6")!=0) {
                                        if(strcmp(argumentos[0],"!7")!=0) {
                                            if(strcmp(argumentos[0],"!8")!=0) {
                                                if(strcmp(argumentos[0],"!9")!=0) {
                                                    if(strcmp(argumentos[0],"!10")!=0) {
                                                        if(strcmp(argumentos[0],"historial")!=0) {
                                                            printf("no se reconoce como comando en el sistema \n",argumentos);
                                                            exit(1);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        default: {
            wait(NULL);
        }
        }

        contaIn++;
        contaEx++;
        if(contaIn == 10) {
            contaIn = 0;
        }
    }
    return 0;
}
