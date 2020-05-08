#include"empleados.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	tEmpleado empleado;
	tListaPtr listaPtr;
	//srand(time(NULL));

	//Inicializacion a NULL o nullptr de todos los punteros
	for (int i = 0; i < N; i++) {
		listaPtr.punt[i] = nullptr;
	}

	//Inicializacion de la lista de punteros
	for (int i = 0; i < 6; i++) {
		empleado.estudio = num_to_estudio(rand() % 6);
		empleado.contratacion = num_to_contratacion(rand() % 4);
		listaPtr.punt[i] = new tEmpleado(empleado);
		listaPtr.contador++;
	}

	eliminarPrimero(listaPtr);
	eliminarUltimo(listaPtr);
	agregarUltimo(listaPtr, empleado);
	agregarPrimero(listaPtr, empleado);

	return 0;
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

void agregarUltimo(tListaPtr& listaPtr, tEmpleado empleado) {
	int num;

	cout << "Agregar al final de la lista dinamica: " << endl;
	cout << "Inserte estudios (0-ESO, 1-Bachillerato, 2-FP_Medio, 3-FP_Superior, 4-Grado, 5-Master, 6-Doctorado): ";
	cin >> num;
	empleado.estudio = num_to_estudio(num);
	cout << "Inserte contratacion (0-Fijo, 1-Practicas, 2-Eventual, 3-Becario): ";
	cin >> num;
	empleado.contratacion = num_to_contratacion(num);

	//Aqui es donde se agrega al final de la lista dinamica
	listaPtr.punt[listaPtr.contador] = new tEmpleado(empleado);
	listaPtr.contador++;
}

void agregarPrimero(tListaPtr& listaPtr, tEmpleado empleado) {
	int num;

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
	listaPtr.punt[0] = new tEmpleado(empleado) ;
	listaPtr.contador++;
}

void eliminarTodos(tListaPtr& listaPtr) {
	for (int i = 0; i < listaPtr.contador; i++) {
		delete listaPtr.punt[i];
		//Nullptr porque, mejor que apunte a algo que sepamos.
		listaPtr.punt[i] = nullptr;
	}

	//Ya no hay elementos en nuestra lista
	listaPtr.contador = 0;
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



