
#include <iostream>
#include <fstream>
using namespace std;

void ingresarDatos();
void mostrarDatos();

int main() {
  int op;
  do
  {
    cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
    cout<<"°          MENU         °"<<endl;
    cout<<"°  1. Ingresar datos    °"<<endl;
    cout<<"°  2. Mostrar datos     °"<<endl;
    cout<<"°  3. Salir             °"<<endl;
    cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
    cout<<"Ingrese una opción: ";
    cin>>op;
    switch (op)
    {
      case 1:
      while(getchar()!='\n');
      ingresarDatos();
      break;
      case 2:
      while(getchar()!='\n');
      mostrarDatos();
      break;
      case 3:
      cout<<"HASTA PRONTO!";
      break;
      default:
      cout<<"Esta opción no existe! Por favor, vuelva a ingresar";
      break;
    }
  }
  while(op!=3);
}

void ingresarDatos()
{
  string nombre, apellido, carrera, nombreArchivo;
  int edad;
  char r;
  ofstream archivo;
  cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin,nombreArchivo);
  archivo.open(nombreArchivo);
  do 
  {
    cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
    cout<<"Ingrese el nombre: ";
    getline(cin,nombre); 
    cout<<"Ingrese el apellido: ";
    getline(cin,apellido); 
    cout<<"Ingrese la carrera: ";
    getline(cin,carrera);
    cout<<"Ingrese la edad: ";
    cin>>edad;
    cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;

    archivo<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea ingresar otro contacto? [s/n]: ";
    cin>>r;
    cin.ignore();
  }
  while(r=='s');
  archivo.close();
}

void mostrarDatos()
{
  string nombre, apellido, carrera, nombreArchivo, texto;
  int edad;

  ifstream archivoLectura;
  cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
  cout<<"Ingrese el nombre del archivo que desea leer: ";
  getline(cin,nombreArchivo);
  cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
  archivoLectura.open(nombreArchivo,ios::in);
  
  while(!archivoLectura.eof())
  {
    archivoLectura>>nombre>>apellido>>carrera>>edad;

    if(!archivoLectura.eof())
    {
      cout<<"Nombre: "<<nombre<<endl;
      cout<<"Apellido: "<<apellido<<endl;
      cout<<"Carrera: "<<carrera<<endl;
      cout<<"Edad: "<<edad<<endl;
      cout<<"° ° ° ° ° ° ° ° ° ° ° ° °"<<endl;
    }
  }
  archivoLectura.close();
}