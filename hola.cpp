#include <iostream>//hola
using namespace std;



int llegada = 5;
float falso = llegada;



int sumar(int numero,int numero1){
  return numero + numero1;
}


int main () {
 
  cout << "hola mundo";
  for(int i = 0; i <= llegada; i = i + 1){
    cout << i;
  }
  while(llegada != 100){ //por ejemplo numero == 100{
      cout<<llegada;
      llegada = llegada + 1;
  }
  
  do{
    cout<<llegada;
    llegada = llegada - 1;
  }while(llegada != 23); //por ejemplo numero != 23
  
  if(llegada > 5){
    cout<<llegada<<endl;
  } else if (llegada < 7){
    cout<<llegada<<endl;
  } else {
    cout<<llegada<<endl;
  }

  if(falso){
    cout << "aqui no se llega porque lo del if es cierto" << endl;
  }else {
    cout << "aqui se llega porque lo del if es cierto" << endl;
  }
}