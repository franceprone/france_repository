#include <iostream>
#include <string>
#include <cmath> 
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

double x;
double y;

struct EBIKE{
    int id;
    double x;
    double y;
    double autonomia;
    bool disponibile;
};


double distanza(EBIKE bike){
    return sqrt(pow(bike.x - x ,2)+pow(bike.y - y ,2));
};

bool confronta(EBIKE bike1, EBIKE bike2){
    return distanza(bike1) < distanza(bike2);
};

int main()
{
EBIKE array_bici[3];
array_bici[0]={32612781,45.12,8.67,13.5,true};
array_bici[1]={47912836,93.04,55.30,15.2,true};
array_bici[2]={21547239,7.81,21.49,10.3,true};


int scelta;
double distanza_utente;

cout << "Iniziamo! Inserisci le tue coordinate x y per vedere dov'è la bici più vicina!" << endl;
cout << "X >> "; cin >> x;
cout << "Y >> "; cin >> y;

sort(array_bici,array_bici + 3,confronta);

cout << "Ecco le info sulle bici disponibili!" << endl;
for(int i=0; i<3 ; i++){
    cout << "EBIKE " << i + 1 << ":" << endl;
    cout << "Bici ID: " << array_bici[i].id << endl;
    cout << "X Bici: " << array_bici[i].x << endl;
    cout << "Y Bici: " << array_bici[i].y << endl;
    cout << "Distanza: " << distanza(array_bici[i]) << endl;
    cout << "Autonomia: " << array_bici[i].autonomia << endl;
};

cout << "Scrivere l'ID della EBIKE che vuoi usare: "; cin >> scelta;

int scelta_bici=0;
int i;
for(i=0; i<3; i++){
    if(array_bici[i].id==scelta){
       scelta_bici=i; 
       break;
    }
}
if(i>3){
    cout << "ID non valido, riprova" << endl;
    return -1;
}
scelta_bici++;
cout << "Hai scelto la bici " << scelta_bici << endl; 


cout << "Quanti km vuoi percorrere?: "; cin >> distanza_utente;

int calcola_distanza=array_bici[scelta_bici].autonomia-distanza_utente;
if(calcola_distanza<0){
    cout << "Distanza non valida" << endl;
    return -1;
}

int temp_min=1;
int temp_max=15;
int ritardo = rand() % 15 + 1;
double tempo=((distanza_utente/20)*60)+ritardo;

double fattura=tempo*0.20;


cout << "Ecco il resoconto finale!" << endl;
cout << "Tempo effetuato per arrivare all'arrivo >>  " << tempo << " min" << endl;
cout << "Km percorsi >> " << distanza_utente << endl;
cout << "Autonomia rimasta >> " << array_bici[scelta_bici].autonomia << endl;
cout << "Ecco l'importo da pagare >> " << fattura << " euro" << endl;


    
    
    
    
    
    
    

    return 0;
}