
#ifndef USUARIOS_H
#define USUARIOS_H

//Funciones hechas por Jordi
int buscar_usuario(char*,Usuarios*,int);
char *altaUsuarioInicio(Usuarios *, int *, char *);
void login(Usuarios *, int *);
void menu_usuario(int, char *, Usuarios *, int *);

#endif /* USUARIOS_H */

