#ifndef CATEGORIA_H_INCLUDED

#define CATEGORIA_H_INCLUDED



typedef struct
{
    int id;
    char descripcion[50];

}eCategoria;


void imprimirCategorias(eCategoria vecC[], int tamC);
void mostrarCategoria(eCategoria vecC);
int cargarDescripcionCategoria(eCategoria vecC[],int tamC,int id,char descripcion[]);













#endif // CATEGORIA_H_INCLUDED
