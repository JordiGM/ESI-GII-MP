
#ifndef USUARIOS_H
#define USUARIOS_H

//Funciones hechas por Jordi
int buscar_usuario(char*,Usuarios*,int);
char *altaUsuarioInicio(Usuarios *, int *, char *);
char *altaUsuario(Usuarios *, int *); 
void bajaUsuario(Usuarios *, int *);
void listarUsuario(Usuarios *, int *); 
void login(Usuarios *, int *);
void menu_usuario(int, char *, Usuarios *, int *);

#endif /* USUARIOS_H */

