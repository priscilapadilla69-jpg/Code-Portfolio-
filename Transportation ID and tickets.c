/**
Proyecto Final
Creación de un programa que permita el registro de un usuario, y mantenga
cuenta del dinero disponible en la cuenta del usuario. De la misma manera, que 
le permita recargar este valor.
1. Información Personal
2. Calculo viaje
3. Saldo disponible y recarga
**/
#include <stdio.h>
#include <math.h>//Libreria para operaciones matematicas
#include <ctype.h>//Libreria para la funcion isalpha,para validacion de strings

char registro();
int e();
void regresoMenu();


void main()
{
   int validation(char nombre[]){//funcion para la validacion de la variable nombre
        int i=0;
        while(nombre[i]){
            if (!isalpha(nombre[i])&& nombre[i]!=' '){//Si no es del alfabeto y no es un espacio regresamos false o 0
                return 0;
                i++;
            }
            //Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1 o true
            return 1;
        }
    }
    int validation1(char destino[]){//funcion para la validacion de la variable nombre
        int i=0;
        while(destino[i]){
            if (!isalpha(destino[i])&& destino[i]!=' '){//Si no es del alfabeto y no es un espacio regresamos false o 0
                return 0;
                i++;
            }
            //Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1 o true
            return 1;
        }
    }
char registro(){//funcion para el ingreso de datos personales
    char nombre[10];//variable nombre
    printf("Ingrese su informacion personal\n ");
    do{
        printf("Ingrese su nombre: ");
        scanf("%s",nombre);
    }while(validation(nombre)==0);//validacion de nombre
    printf("Nombre:%s\n",nombre);
    return nombre[10];
}
  int e(){
    int edad;
    do{
        printf("Ingrese su edad: ");
        scanf("%i",&edad);
    }while(edad<=0);//validacion de edad
    printf("Edad:%i\n",edad);
    
    return edad;
}
    int transporte,respuesta;
    int edad, cumple,op,cambio,j;
    char nombre[10];
    char destino[10];
    float km,viaje,recarga;
    float costo,saldo;
    while(op!=4){
      printf("1. Información personal\n2. Calcular viaje\n3. Saldo disponible y recarga\n4.Salir\n");
      do{
          printf("Escoga la opción deseada: ");
         scanf("%i",&op);
       }while(op<=0);//validacion de la variable operacion
            switch(op){
                case 1: 
                    j=0;
                    while(j==0){
                        registro(nombre);
                        e(edad);
                        printf("Su informacion ha sido actualizada\n");
                        j++;
                        break;
                    }
                    while(j>0){
                        do{
                            printf("Desea actualizar su informacion? (1.SI 2.No): ");
                            scanf("%i",&cambio);
                        }while(cambio!=1 && cambio!=2);
                        if(cambio==1){
                            registro(nombre);
                            e(edad);
                            printf("Su informacion ha sido actualizada\n");
                            break;
                        }else{
                            regresoMenu();
                            break;
                        }
                    }
                break;
                case 2:
                 do{
                     printf("Desea saber el costo de su viaje? (1.Si 2.No): ");
                     scanf("%i",&respuesta);
                 }while(respuesta!=1 && respuesta!=2);
                    if(respuesta==1){
                        do{
                            printf("Escoga el medio de transporte 1.Bus 2.Tren");
                            scanf("%i",&transporte);
                        }while(transporte!=1 && transporte!=2);
                        if(transporte==1){
                            do{
                                printf("Quito\nCumbaya\nValle\nSur\nNorte\nIngrese el nombre de su destino: ");
                                scanf("%s",destino);
                                /*if(isupper(destino)){
                                    destino=tolower(destino);
                                }*/
                            }while(validation1(destino)==0);
                            //como asignar valores a cada parada
                        }else if(transporte==2){
                            do{
                                printf("Quito\nTambillo\nMachachi\nBoliche\nIngrese el nombre de su destino: ");
                                scanf("%s",destino);
                            }while(validation1(destino)==0);
                        }
                    }
                   /* Ingresar el nombre de parada y guardar un valor del costo para esa parada
                   Dependiendo de la edad de la persona esta tiene descuento o no, existen valores predeterminados
                   para diferentes edades y medios de transporte*/
                break;
                case 3:
                 do{
                        printf("Ingrese el valor de su recarga: ");
                        scanf("%f",&recarga);
                 }while(recarga<0);
                 saldo=saldo+recarga;
                 printf("Su saldo total es: %f",saldo);
                 //digamos que tomo una viaje a quito debe restar el valor del viaje a quito
                    //restar de la variable recarga despues de cada viaje dependiendo del valor de cada viaje
                break;
                case 4:
                  printf("Fin del programa");
                break;
                default:
                  printf("Opción inválida.Intente nuevamente\n");
                break;      
           }
   }
}

void regresoMenu(){
    int op;
    printf("1. Información personal\n2. Calcular viaje\n3. Saldo disponible y recarga\n");
    do{
        printf("Escoga la opción deseada: ");
        scanf("%i",&op);
    }while(op<=0);
}









