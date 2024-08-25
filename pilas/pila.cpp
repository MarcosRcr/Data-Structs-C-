
#include <iostream>

using namespace std;

struct Nodo {
  Nodo *siguiente;
  int dato;
} *primero;

void insertarNodo();
void buscarNodo();
void editarNodo();
void mostrarNodo();
void eliminarNodo();

int main() {
  int opt;
  do {
    cout << "|-----------------------------------|" << endl;
    cout << "|           Menu de PIla            |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 1. Insertar   | 2. Buscar         |" << endl;
    cout << "| 3. Editar     | 4. Mostrar        |" << endl;
    cout << "| 5. Eliminar   | 6. Salir          |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opt;

    switch (opt) {
    case 1:
      insertarNodo();
      break;
    case 2:
      buscarNodo();
      break;
    case 3:
      editarNodo();
      break;
    case 4:
      mostrarNodo();
      break;
    case 5:
      eliminarNodo();
      break;
    case 6:
      cout << "Saliendo..." << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  } while (opt != 6);

  cin.get();
  cout << "Pulse cualquier tecla para salir ...";
  cin.get();
  return 0;
}

// primero = null  nuevo = 4             4,7,8,9
// Pila   -     4-> null
// primero = 4     nuevo = 7
// primero = 7     nuevo = 8
// primero = 8     nuevo = 9
void insertarNodo() {
  int cant;
  cout << "\nIngrese la cantidad de ndodos que desee agregar: ";
  cin >> cant;
  while (cant > 0) {
    Nodo *nuevo = new Nodo();
    cout << "Ingrse el dato que contendra el nuevo nodo: ";
    cin >> nuevo->dato;
    nuevo->siguiente = primero;
    primero = nuevo;
    cout << "\nNodo ingresado correctamente\n";
    cant--;
  }
  cout << "Nodos ingresados correctamente\n";
}

void mostrarNodo() {
  Nodo *actual = new Nodo();
  actual = primero;
  if (primero != NULL) {
    while (actual != NULL) {
      cout << endl << " " << actual->dato;
      actual = actual->siguiente;
    }
    cout << "\nPila Completada\n";
  } else {
    cout << endl << "La pila esta vacia";
  }
}

void buscarNodo() {
  Nodo *actual = new Nodo();
  actual = primero;
  int nodoBuscado;
  bool encontrado = false;
  cout << " Ingrese el dato del nodo a Buscar: ";
  cin >> nodoBuscado;
  if (primero != NULL) {
    while (actual != NULL && encontrado != true) {
      if (actual->dato == nodoBuscado) {
        cout << "\nNodo con el dato (" << nodoBuscado << ") Encontrado\n";
        encontrado = true;
      }
      actual = actual->siguiente;
    }
    if (encontrado == false) {
      cout << "\nNodo no encontrado\n";
    }
  } else {
    cout << endl << "La pila esta vacia";
  }
}

void editarNodo() {
  Nodo *actual = new Nodo();
  actual = primero;
  int nodoBuscado;
  bool encontrado = false;
  cout << " Ingrese el dato del nodo a Editar: ";
  cin >> nodoBuscado;
  if (primero != NULL) {
    while (actual != NULL && encontrado != true) {
      if (actual->dato == nodoBuscado) {
        cout << "\nNodo con el dato (" << nodoBuscado << ") Encontrado\n";
        cout << "\nIngrese el dato nuevo para el nodo: ";
        cin >> actual->dato;
        cout << "\nNodo editado correctamente\n";
        encontrado = true;
      }
      actual = actual->siguiente;
    }
    if (encontrado == false) {
      cout << "\nNodo no encontrado\n";
    }
  } else {
    cout << endl << "La pila esta vacia";
  }
}

void eliminarNodo() {
  Nodo *actual = new Nodo();
  actual = primero;
  Nodo *anterior = new Nodo();
  anterior = NULL;
  int nodoBuscado;
  bool encontrado = false;
  cout << " Ingrese el dato del nodo a Eliminar: ";
  cin >> nodoBuscado;
  if (primero != NULL) {
    while (actual != NULL && encontrado != true) {
      if (actual->dato == nodoBuscado) {
        cout << "\nNodo con el dato (" << nodoBuscado << ") Encontrado\n";
        if (actual == primero) {
          primero = primero->siguiente;
        } else {
          anterior->siguiente = actual->siguiente;
        }
        cout << "\nNodo eliminado\n";
        encontrado = true;
      }
      anterior = actual;
      actual = actual->siguiente;
    }
    if (encontrado == false) {
      cout << "\nNodo no encontrado\n";
    }
  } else {
    cout << endl << "La pila esta vacia";
  }
}
