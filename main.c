#include <stdio.h>

int main (int argc, char *argv[]) {

    char nombre[5][2][50]={{"Carlos","35"},
                           {"Ana","20"},
                           {"Juan","40"},
                           {"Lucia","35"},
                           {"Maria","50"}};
    if(abrirArchivo("nombres")){
        
    }else{
        crearArchivo("nombre");
        guardarNombreArchivo("nombre",nombre);
    }
    
    return 0;
}

int crearArchivo(char nombreArchivo[]){
    FILE *archivo;
    archivo=fopen(nombreArchivo,"w+");
    if (archivo==NULL)
    {
       printf("No se puede crear el archivo");
       return 0;
    }
    fclose(archivo);
    return 1;
}

int abrirArchivo(char nombreArchivo[]){
    FILE *archivo;
    archivo=fopen(nombreArchivo,"r+");
    if (archivo==NULL)
    {
       printf("No se puede abrir el archivo");
       return 0;
    }
    fclose(archivo);
    return 1;
}

void guardarNombreArchivo(char nombreArchivo[],char nombre[5][2][50]){
    FILE *archivo;
    archivo=fopen(nombreArchivo,"r+");
    if (archivo==NULL)
    {
       printf("No se puede abrir el archivo");

    }else{
        for (int i = 0; i < 5; i++)
        {
            fprintf(archivo,"%s %s\n",nombre[i][0],nombre[i][1]);
        }
        fclose(archivo);
    }
}