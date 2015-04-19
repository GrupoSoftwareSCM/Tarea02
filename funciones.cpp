
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <strings.h>
#include <time.h>
#include "funciones.h"
#include <vector>

/*incluir libreria para ficheros*/
#include <fstream>

using namespace std;
int buscarEstado(int estado[], string e){
    int i;
    for(i = 0;i<80;i++){
        if(estado[i] == atoi(e.c_str())){
            return 1;
        }
    }
    return 0;
}
void Parcear(string line,string par[]){
    int i,found;
    char caracter = '"';
    for(i=0;i<9;i++){
        if((i<3 && line.find(" ") != -1) || (i>4 && i<7 && line.find(" ") != -1)){
            found = line.find(" ");
            par[i] = line.substr(0,found);
            line = line.substr(found+1,line.size());
        }
        else{
            if(i == 3 && line.find("]") != -1){
                found = line.find("]");
                par[i] = line.substr(1,found-1);
                line = line.substr(found+3,line.size());
            }
            else{
                if(i == 4 && line.find(caracter) != -1){
                    found = line.find(caracter);
                    par[i] = line.substr(0,found);
                    line = line.substr(found+2,line.size());
                }
                else{
                    if(i==7 && line.find(" ") != -1){
                        found = line.find(" ");
                        par[i] = line.substr(1,found-2);
                        line = line.substr(found+2,line.size());
                    }
                    else{
                        if(i == 8 && line.find(caracter) != -1){
                            found = line.find(caracter);
                            par[i] = line.substr(0,found);
                            line = "null";
                        }
                    }
                }
            }
        }
    }
}

int ValidarFecha(string Fecha){
    //formato ISO YYYY-MM-DD
    /*LA FECHA DE HOY*/
    struct tm *tiempo;
    int dia;
    int mes;
    int anio;

    time_t fecha_sistema;
    time(&fecha_sistema);
    tiempo=localtime(&fecha_sistema);

    anio=tiempo->tm_year + 1900; //2015
    mes=tiempo->tm_mon + 1;      //4
    dia=tiempo->tm_mday;         //18
    /*FIN FECHA DE HOY*/
    int len = Fecha.length();
    int i,cont = 0;
    string d,m,y;
    y = Fecha.substr(0,4);
    m = Fecha.substr(5,2);
    d = Fecha.substr(8,2);
    //verificamos si existen 3 "-"
    for(i=0;i<len;i++){
        if(Fecha[i] == '-') cont++;
    }
    if(cont == 2){
        if(atoi(y.c_str())>anio) return 0;
        if(atoi(m.c_str())>mes && atoi(m.c_str())>12) return 0;
        if(atoi(d.c_str())>dia && atoi(m.c_str())>31) return 0;
        else return 1;
    }
    else{
        return 0;
    }
    return 0;
}
int CompararFecha(string f1,string f2){
    string y1,y2,m1,m2,d1,d2;

    y1 = f1.substr(0,4);
    m1 = f1.substr(5,2);
    d1 = f1.substr(8,2);

    y2 = f2.substr(0,4);
    m2 = f2.substr(5,2);
    d2 = f2.substr(8,2);

    if(atoi(y1.c_str()) < atoi(y2.c_str()))
        return 1;
    if(atoi(y1.c_str()) == atoi(y2.c_str())){
        if(atoi(m1.c_str()) < atoi(m2.c_str()))
            return 1;
        if(atoi(m1.c_str()) == atoi(m2.c_str())){
            if(atoi(d1.c_str()) <= atoi(d2.c_str()))
                return 1;
            else
                return 0;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }

                return 1;
}
int agregarEstado(char path[]){
    string line,parseo[9];
    int estado[80],i=0;

    /*abrimos el fichero*/
    ifstream fe; // Fichero de Entrada
    fe.open(path);

    if(fe.is_open()){
        cout<<"fichero abierto"<<endl;
        while(!fe.eof()){
            getline(fe,line);
            Parcear(line,parseo);
            //cout<<"estado: "<<parseo[5]<<endl;
            if(buscarEstado(estado,parseo[5]) == 0) {
                estado[i] = atoi(parseo[5].c_str());
                i++;
            }
        }
        //cout<<"parseo terminado ..."<<endl;
        fe.close();

    }
    else
        cout<<"no se pudo abrir el fichero"<<endl;
    //cout<<"largo"<<estado.size()<<endl;
    int Estado = *estado;
    return Estado;
}
