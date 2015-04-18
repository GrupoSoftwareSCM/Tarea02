#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <strings.h>
#include "funciones.h"
#include "funciones.cpp"
using namespace std;

/*
|   FORMATO DEL FICHERO access.log
|
|   ejemplo 190.121.30.129 - - [01/Jun/2012:04:59:02 +0200]
|           "GET /templates/beez_20/css/general.css HTTP/1.1" 200 1447
|           "http://www.openalfa.com/index.php/perl/condiciones-y-cadenas"
|           "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/536.5 Chrome/19.0.1084.52 Safari/536.5"
|
|   1. ip : 190.121.30.129
|   2. client_id: -
|   3. user_id: -
|   4. fecha: 01/Jun/2012:04:59:02 +0200
|   5. peticion revidia: GET /templates/beez_20/css/general.css HTTP/1.1
|   6. codigo de respuesta: 200
|   7. tamaño de respuesta: 1447
|   8. referrer: http://www.openalfa.com/index.php/perl/condiciones-y-cadenas
|   9. agent: Mozilla/5.0 (Windows NT 6.1) AppleWebKit/536.5 Chrome/19.0.1084.52 Safari/536.5
*/


int main(int argc,char *argv[])
{
    string path;
    //cout << "Hello world!" << endl;
    if(strcmp(argv[1],"-so") == 0 || strcmp(argv[1],"-SO") == 0 || strcmp(argv[1],"-So") == 0 || strcmp(argv[1],"-sO") == 0){
        if(ValidarFecha(argv[2]) == 1 && ValidarFecha(argv[4]) == 1){
            if(CompararFecha(argv[2],argv[4]) == 1){
                if(strcmp(argv[3],"hasta") == 0){

                }
                else{
                    cout<<"falto ingresar un parametro"<<endl;
                    cout<<"se debe ingresar de la siguiente forma"<<endl;
                    cout<<"-so YY-MM-DD hasta YY-MM-DD"<<endl;
                }
            }
            else
                cout<<"la fecha "<<argv[2]<<" es mayor que "<<argv[4]<<endl;
        }
        else{
            cout<<"fecha mal ingresada, tiene que ser con el formato ISO YYYY-MM-DD"<<endl;
        }
    }
    else
        cout<<"Parametro no valido ... "<<endl;
    return 0;
}
