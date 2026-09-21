#include <iostream>

int main (){
int numero = 10;
int *ptr_numero = &numero;

std:: cout<< "Direccion de memora: " << ptr_numero << std:: endl;
std:: cout<< "Valor en memoria: "<< *ptr_numero << std:: endl;
std:: cout<< "Valor en memoria desde de la variable "<< numero << std:: endl;

int notas[5] = {80, 90, 60, 60, 71};

int *ptr_notas = notas; 

for (int i=0; i<5; i++){
    std:: cout<< "Nota "<< i << *(ptr_notas + i ) << std:: endl;
}

return 0;
}
