#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_COD_ART 4
#define TAM_DESC_ART 10
#define TAM_TIT_ART 12

typedef struct {
    char *codigo;
    char *descripcion;
    char *titulo;
} articulo;

/* prototipos */
articulo *fichero_a_almacen( int * );
void llena_fichero( int );
void mostrar_almacen ( int, articulo * );

void quitar_saltos( char * );
char *leer_campo( int, char * );
int leer_numero( char * );

articulo *fichero_a_almacen( int *num ) {
     articulo *alm;
     char *cod, *desc, *tit;

     FILE *fich;
     fich = fopen("prueba.txt", "r");
     if (fich==NULL) exit(1);

     while ( !feof(fich) ) {
           cod=(char *) malloc( TAM_COD_ART+1*sizeof(char) );
           desc=(char *) malloc( TAM_DESC_ART+1*sizeof(char) );
           tit=(char *) malloc( TAM_TIT_ART+1*sizeof(char) );
           fscanf(fich, "%[^-]-%[^-]-%[^\n]\n", cod, desc, tit); // formato para que admita espacios

           if (! *num) alm = (articulo *) malloc( (*num+1) * sizeof(articulo) );
           else alm = (articulo *) realloc( alm, (*num+1) * sizeof(articulo) );
           printf("Registro recuperado: %d - |%*s| - |%-*s| - |%-*s| >>> OK\n",
                  *num, TAM_COD_ART, cod,
                        TAM_DESC_ART, desc,
                        TAM_TIT_ART, tit);
           alm[*num].codigo = cod;
           alm[*num].descripcion = desc;
           alm[*num].titulo = tit;
           (*num)++;
     }

     fclose(fich);
     return alm;
}

void quitar_saltos( char *cadena ) {
     char *p;
     p = strchr(cadena, '\n');
     if (p) *p = '\0';
}

char *leer_campo( int largo, char *titulo ) {
//  Seria incorrecto leer string mediante un puntero al que no se le ha reservado memoria
//  scanf toma una palabra como cadena y usa los espacios para separar variables.
     char *campo;
     campo = (char *)calloc(largo+1, sizeof(char)) ;
     printf("%s (%d):", titulo, largo);
     fgets(campo, largo+1, stdin);
     quitar_saltos( campo );
     fflush( stdin );
     return campo;
}

int leer_numero( char *titulo ) {
     int num;
     printf("%s (integer):", titulo);
     scanf("%d", &num);
     fflush( stdin );
     return num;
}

void llena_fichero( int n ) {
  int i;
  articulo atemp;

  FILE *fichero;
  fichero = fopen("prueba.txt", "w");
  if (fichero==NULL) exit(1);

  for (i=0; i<n; i++) { // leemos n elementos
      printf("*** Elemento %d\n",i);
      atemp.codigo=leer_campo(TAM_COD_ART, "Código:");
      atemp.descripcion=leer_campo(TAM_DESC_ART, "Descripción:");
      atemp.titulo=leer_campo(TAM_TIT_ART, "Título:");
      printf("Usted ha introducido: Código=%s Descripción=%s Título=%s -->> OK\n\n",
                            atemp.codigo, atemp.descripcion,  atemp.titulo);
      fprintf( fichero, "%0*d-%s-%s\n", // %04s %- s
	  		   TAM_COD_ART,  atoi(atemp.codigo),
	  		   atemp.descripcion,
	  		   atemp.titulo);

  }

  fclose(fichero);
}

void mostrar_almacen ( int num, articulo *alm ) {
    int i;
    for (i=0; i<num; i++)
        printf("Refistro: %d - |%*s| - |%-*s| - |%-*s|\n",
                  i, TAM_COD_ART, alm[i].codigo,
                        TAM_DESC_ART, alm[i].descripcion,
                        TAM_TIT_ART, alm[i].titulo);
}

int main(int argc, char *argv[]) {

  int num_articulos=0, num_registros;
  articulo *almacen;

  setlocale(LC_CTYPE, "Spanish");

  printf("Empezamos ""...""\n\n");

  printf("Llenamos el fichero de texto desde el teclado \n");
  num_registros = leer_numero("Número de registros ");
  printf("\n");
  llena_fichero(num_registros);

  printf("\nRecuperamos el fichero de texto y lo volcamos en un array dinámico \n");
  almacen = fichero_a_almacen( &num_articulos );
  printf("Se han recuperado %d registros.\n", num_articulos);

  printf("\nMostramos el contenido del array dinámico \n");
  mostrar_almacen ( num_articulos, almacen );
  printf("\n\n");

  //system("PAUSE");
  return 0;

}



