#ifndef REGISTRO_EMPLEADOS_H
#define REGISTRO_EMPLEADOS_H

//Declaracion de la lista
const int N = 10;
typedef enum tEstudio {ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctorado};
typedef enum tContratacion {Fijo, Practicas, Eventual, Becario};
typedef struct {
	tEstudio estudio;
	tContratacion contratacion;
}tEmpleado;

//Declaracion de datos dinamicos
typedef tEmpleado* tPtr;
typedef struct {
	tPtr punt[N];
	int contador = 0;
}tListaPtr;

//Prototipos
int main();

tEstudio num_to_estudio(int num);

tContratacion num_to_contratacion(int num);

void eliminarUltimo(tListaPtr& listaPtr);

void eliminarPrimero(tListaPtr& listaPtr);

void agregarUltimo(tListaPtr& listaPtr, tEmpleado empleado);

void agregarPrimero(tListaPtr& listaPtr, tEmpleado empleado);

//Funcion para liberar la memoria, recuerdas el new? Pues ahora toca liberarlos
void eliminarTodos(tListaPtr& listaPtr);
#endif
