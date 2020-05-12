#include<iostream>
#include<cstdlib>
#include<ctime>
#include"empleados.h"
using namespace std;

int main() {
	tListaPtr listaPtr;
	
	//srand(time(NULL));

	listaPtr.punt = new tEmpleado[N]; //Ahora es cuando pasa a ser un array dinamico

	for (int i = 0; i < N; i++) {
		//Si la cantidad de elementos que hay en el array es igual al tamamo MAXIMO se llama a ampliar
		if (listaPtr.contador == listaPtr.capacidad) { 
			ampliar(listaPtr);
		}
		listaPtr.punt[i].estudio = num_to_estudio(rand() % 6);
		listaPtr.punt[i].contratacion = num_to_contratacion(rand() % 3);
		listaPtr.contador++;
	}

	agregarUltimo(listaPtr);
	agregarPrimero(listaPtr);
	eliminarUltimo(listaPtr);
	eliminarPrimero(listaPtr);

	eliminarTodos(listaPtr);
	return 0;
}


void agregarUltimo(tListaPtr& listaPtr) {
	int num;
	tEmpleado empleado;
	if (listaPtr.contador == listaPtr.capacidad) {
		ampliar(listaPtr);
	}

	cout << "Agregar al final de la lista dinamica: " << endl;
	cout << "Inserte estudios (0-ESO, 1-Bachillerato, 2-FP_Medio, 3-FP_Superior, 4-Grado, 5-Master, 6-Doctorado): ";
	cin >> num;
	empleado.estudio = num_to_estudio(num);
	cout << "Inserte contratacion (0-Fijo, 1-Practicas, 2-Eventual, 3-Becario): ";
	cin >> num;
	empleado.contratacion = num_to_contratacion(num);

	//Aqui es donde se agrega al final de la lista dinamica
	listaPtr.punt[listaPtr.contador] = empleado;
	listaPtr.contador++;
}

void agregarPrimero(tListaPtr& listaPtr) {
	int num;
	tEmpleado empleado;
	if (listaPtr.contador == listaPtr.capacidad) {
		ampliar(listaPtr);
	}

	cout << "Agregar al principio de la lista dinamica: " << endl;
	cout << "Inserte estudios (0-ESO, 1-Bachillerato, 2-FP_Medio, 3-FP_Superior, 4-Grado, 5-Master, 6-Doctorado): ";
	cin >> num;
	empleado.estudio = num_to_estudio(num);
	cout << "Inserte contratacion (0-Fijo, 1-Practicas, 2-Eventual, 3-Becario): ";
	cin >> num;
	empleado.contratacion = num_to_contratacion(num);

	//"Formula" de agregar elementos en un array
	//Aqui es donde se agrega al principio(posicion 0) de la lista
	//Primero se dezplaza todo a la derecha
	for (int i = listaPtr.contador; i >= 0; i--) {
		listaPtr.punt[i + 1] = listaPtr.punt[i];
	}
	//Luego se agrega al principio
	listaPtr.punt[0] = empleado;
	listaPtr.contador++;
}

void eliminarUltimo(tListaPtr& listaPtr) {
	for (int i = listaPtr.contador - 1; i < listaPtr.contador; i++) {
		listaPtr.punt[i] = listaPtr.punt[i + 1];
	}
	listaPtr.contador--;
}

void eliminarPrimero(tListaPtr& listaPtr) {
	for (int i = 0; i < listaPtr.contador; i++) {
		listaPtr.punt[i] = listaPtr.punt[i + 1];
	}
	listaPtr.contador--;
}

void eliminarTodos(tListaPtr& listaPtr) {
	delete[] listaPtr.punt;
	listaPtr.punt = nullptr; //Mejor que apunte a nullptr, a que apunte a saber donde
	listaPtr.contador = 0;
}

void ampliar(tListaPtr& listaPtr) {
	//Duplica el tamano:
	//se crea un nuevo array aux dinamico de tamano doble( 2 * lista.capacidad )
	//luego se copia los contenido de nuestro array dinamico original(lista.punt) y los pone en aux
	//se borra nuestro array original(lista.punt)
	//El puntero del array dinamico aux se copia a lista.punt
	cout << "Se ha llamdo a duplicar tamano con lista.contador= " << listaPtr.contador << endl;

	tEmpleado* aux = nullptr;

	aux = new tEmpleado[2 * listaPtr.capacidad];
	for (int i = 0; i < listaPtr.contador; i++) {
		aux[i] = listaPtr.punt[i];
	}
	delete[] listaPtr.punt; //usar [] para vectores dinamicos
	listaPtr.punt = aux;
	listaPtr.capacidad = listaPtr.capacidad * 2; //Se actualiza el tamano maximo
	aux = nullptr; //Como ya no necesitamos aux, tendra que apuntar a nullptr o NULL(por que mejor que apunte a nullptr, a que apunte a una direccion aleatoria)
}

tEstudio num_to_estudio(int num) {
	tEstudio e;
	switch (num) {
	case 0:
		e = ESO;
		break;
	case 1:
		e = Bachillerato;
		break;
	case 2:
		e = FP_Medio;
		break;
	case 3:
		e = FP_Superior;
		break;
	case 4:
		e = Grado;
		break;
	case 5:
		e = Master;
		break;
	case 6:
		e = Doctorado;
		break;
	}
	return e;
}

tContratacion num_to_contratacion(int num) {
	tContratacion c;
	switch (num) {
	case 0:
		c = Fijo;
		break;
	case 1:
		c = Practicas;
		break;
	case 2:
		c = Eventual;
		break;
	case 3:
		c = Becario;
		break;
	}
	return c;
}
