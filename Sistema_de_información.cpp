#include<iostream>
#include<stdlib.h>

using namespace std;

void menu();
void agregar(int vec[],int tam);
void eliminar(int vec[],int tam);
void buscar(int vec[],int tam);
void modificar(int vec[],int tam);
void insertar(int vec[],int tam);
void reporte(int vec[],int tam);
bool comprobacion(int vector[], int tam,int valor);

int main() 
{ 
    int vector[20]={0};
    int op;

    do
    {
        menu();
        cin >> op; 
        switch (op)
        {
            case 0:
            cout<<"saliste"<<endl;
            break;
         
            case 1:
            cout<<"valor agregado"<<endl;
            agregar(vector,20);
            break;
         
            case 2:
            cout<<"eliminar valor"<<endl;
            eliminar(vector,20);
            break;
         
         
            case 3:
            cout<< "buscar valor"<<endl;
            buscar(vector,20);
            break;
         
            case 4:
            cout<<"modificar valor"<<endl;
            modificar(vector,20);
            break;
             
            case 5:
            cout<<"insertar valor"<<endl;
            insertar(vector,20);
            break;
            
            case 6:
            cout<<"reporte"<<endl;
            reporte(vector,20);
            break; 
            
            default:
            cout<<"!ERROR AL ELEGIR OPCION¡";
            break;
        }
     
    }while(op != 0); 

    
    return 0;
} 

void menu()
{
    
    cout<<"1.- Agregar \n2.- Eliminar \n3.- Buscar \n4.- Modificar \n5.- Insertar \n6.- reporte \n0.- salir \n";
    cout<<"ELIGE UNA OPCION: ";
}


void agregar(int vec[],int tam)
{
    int aux=0, i=0;
	while (aux!=1)
	{
		if (vec[i]!=0)
		{
			vec[i++];
		}
		else
		{
			vec[i]=10+rand()%290;
			aux=1;
		}
    }
	
}


void eliminar(int vec[],int tam)
{
    int val;
    cout<<"INGRESA EL VALOR A ELIMINAR: ";
    cin>>val;
    if(comprobacion(vec,tam,val)==true)
    {
        for(int i=0;i<tam;i++)
        {
            if(vec[i]==val)
            {
                for(int J=i;J<tam;J++)
                {
                    vec[J]=vec[J+1];
                }
                cout<<"ELIMINADO"<<endl;
            }
        }
    }    
}


void buscar(int vec[],int tam)
{
    int val;
    cout<<"INGRESA EL VALOR QUE DESEAS BUSCAR: ";
    cin>>val;
    if(comprobacion(vec,tam,val)==true)
    {
        for(int i=0;i<tam;i++)
        {
            if(vec[i]==val)
            {
                cout<<"EL VALOR ESTA EN LA POCISION "<<i<<endl;
            }
        }
    }
    else
    {
        cout<<"EL VALOR NO EXISTE";
    }

}


void modificar(int vec[],int tam)
{
    int val0, val1;
    cout<<"INGRESA EL NUEVO VALOR"<<endl;
    cin>>val1;
    cout<<"INGRESA EL VALOR QUE DESEA MODEIFICAR"<<endl;
    cin>>val0;
    for(int i=0;i<tam;i++)
    {
        if(vec[i]==val0)
        {
            vec[i]=val1;
        }
        else
        {
        cout<<"EL VALOR NO EXISTE";
        }
    }
}


void insertar(int vec[],int tam)
{
    int posicion, val, aux;
    cout<<"INGRESA LA POSICION DONDE SE INSERTARA EL VALOR: "<<endl;
    cin>>posicion;
    cout<<"INGRESA EL VALOR: "<<endl;
    cin>>val;
    if(vec[posicion]!=0)
    {
        for(int i=posicion;i<tam&&vec[i+1]!=0;i++)
        {
            aux=vec[i+1];
            vec[i]=aux;
        }
        vec[posicion]=val;
    }
    else
    {
        cout<<"ESA POCISION NO EXISTE";
    }
}


void reporte(int vec[],int tam)
{
    for (int i = 0; i<tam; i++)
	{
	    if(vec[i]!=0)
	    {
		    cout<<"["<<i<<"]="<<vec[i]<<endl;
	    }
	    
    }
}


bool comprobacion(int vec[], int tam,int valor)
{
     for(int i=0;i<tam;i++)
    {
        if(vec[i]==valor)
        {
            return true;
        }
    }
}
