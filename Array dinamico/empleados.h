#ifndef REGISTRO_EMPLEADOS_H
#define REGISTRO_EMPLEADOS_H

//Declaracion de los elementos
const int N = 10; //Tamano inicial
typedef enum tEstudio { ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctorado };
typedef enum tContratacion { Fijo, Practicas, Eventual, Becario };
typedef struct {
	tEstudio estudio;
	tContratacion contratacion;
}tEmpleado;

//Declaracion del array dinamico
//que de momento en la declaracion no lo hacemos array, eso se hace en la ejecucion de la funcion main(o en la que necesitemos)
typedef tEmpleado* tPtr;
typedef struct {
	tPtr punt; //En la ejecucion esto sera un array dinamico
	int contador = 0; //Cuantos elementos hay en el array
	int capacidad = N; //Tamano MAXIMO que tiene el array, dependiendo de nuestras necesidades podemos alterarlo
}tListaPtr;

//Prototipos
int main();

tEstudio num_to_estudio(int num);

tContratacion num_to_contratacion(int num);

void eliminarUltimo(tListaPtr& listaPtr);

void eliminarPrimero(tListaPtr& listaPtr);

void agregarUltimo(tListaPtr& listaPtr, tEmpleado empleado);

void agregarPrimero(tListaPtr& listaPtr, tEmpleado empleado);

//Funcion para liberar la memoria, recuerdas el new en el main? Pues ahora toca liberar el array entero
void eliminarTodos(tListaPtr& listaPtr);
//Funcion para ampliar el tamano de nuestro array dinamico
void ampliar(tListaPtr& lista);
#endif
