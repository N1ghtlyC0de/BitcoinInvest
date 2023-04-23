/*
Ingreso de valores del Bitcoin de acuerdo a los ultimos dias 
-- el programa genera los precios del Bitcoin segun el orden de los ultimos dias
-- El programa genera un reporte de los dias que espera para la venta
-- el programa maneja un solo apuntador en forma de "cola" en su insercion
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{ 
	int precio;
	lista *apunta; // apuntador Lista
} *cola, *cab, *nuevo, *nuevo2;

void menu(void);
void ingresar(void);
void mostrar1(void);
void mostrar_dias(void);
void limpiar_lista(void);
void espera();

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar Precio Bitcoin Ultimos Dias";
		cout<<"\n 2 Listar Precio Bitcoin Digitados "; 
		cout<<"\n 3 Listar dias venta Bitcoin  "; 
		cout<<"\n ................          "; 
		cout<<"\n 4 Limpiar <Borrar> Lista  "; 
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();
				break;
			case 2:
				mostrar1();	  
				break;
			case 3:
				mostrar_dias();
				break;
			case 4:
				limpiar_lista();
				break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
	}
}

void ingresar(void)
{
	// Ingresa los precios del Bitcoin de los ultimos dias
	// y los ordena en forma de "cola" utiliza un solo apuntador
	
	int sw;
    
	// PRIMERA PARTE	
	nuevo = new(lista); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el Precio de Bitcoin : ";
	cin >> nuevo->precio;
	nuevo->apunta = NULL;
	// las variables apuntad se inicia en NULL ... 
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA
	if (!cab)
	{   // si la lista no esta creada ... la creamos
		// y asignamos los punteros a nuevo Nodo
		cab   = new(lista);
		cola  = new(lista);
		cab  = nuevo;  cola = nuevo; 

		cout <<"\n"<<"se creo la lista";
	}
    else
	{ 
	//  insertamos al final de la lista en forma de "COLA"	
  		cola->apunta = nuevo;
   		cola = nuevo;
	}
	espera(); //funcio para dar <Enter>	
}

void mostrar1(void) //ascendente
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  cout <<"\n"<<" Reporte de los precios del Bitcoin de los ultimos dias"<<endl;
   	  while (nuevo != NULL)
   	  {
		 cout <<"\n"<<"precio  : "<<nuevo->precio;
		 nuevo = nuevo->apunta; 	
	  }
   }
   espera();   
}

void mostrar_dias(void)
{
   int encontro, dias;
   encontro = 0;
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  
	  cout <<"\n"<<" Reporte de Bitcoin y dias para la Venta"<<endl;
	  // primero mostramos los valores del Bitcoin
	  while ( nuevo != NULL )
	  {
	 	cout <<nuevo->precio<<" ";
		nuevo = nuevo->apunta;
	  }
	  cout <<endl;
	  // y ahora mostramos los dias para la venta
	  nuevo = new(lista);
   	  nuevo = cab;
   	  //iniciamos con el primer precio y lo comparamos con los otros precios
   	  // y luego avanzamos en la lista de precios
   	  while ( nuevo != NULL )
	  {
         encontro = 0;  // variable utilizada para verificar si encontramos o no
		 			    // un precio para la venta de Bitcoin  
         dias = 1;
         nuevo2 = new(lista);
         nuevo2 = nuevo->apunta; // nos posicionamos en el siguiente precio
         // para enpezar a comparar estos para poder vender
         while ( nuevo2 != NULL && encontro == 0 )
         {
         	if ( nuevo->precio < nuevo2->precio)
         	{   cout<<dias<<" "; encontro = 1;}
         	dias++;
         	nuevo2 = nuevo2->apunta;
         	// avanzamos en la lista de precios para buscar un precio a comparar
		 }
		 if (nuevo2 == NULL && encontro == 0)
		 {	cout <<" 0 ";
		 }
		 nuevo = nuevo->apunta; 
		 // avanzamos en la lista para el siguiente valor Bitcoin
	  }

   }
   espera();   
}

void limpiar_lista(void)
{   //inicializamos los nodos de Inicio y Fin de la Lista
 	cab   = NULL;  	cola  = NULL;		
}

void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
