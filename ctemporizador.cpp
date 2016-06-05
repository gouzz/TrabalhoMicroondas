#include "ctemporizador.h"
#include <iostream>
using namespace std;

Ctemporizador::Ctemporizador()
{ count_down = false;
    tempo = 0;
}

bool Ctemporizador::iniciar() {
    count_down = true;
    return true;
}
bool Ctemporizador::pausa() {
    count_down = false;
    return true;
}
int Ctemporizador::getTempo() {
    return tempo;
                              }
bool Ctemporizador::aDescontar() {
    return count_down;
}
bool Ctemporizador::aumentaTempo() {
    tempo += 5;
    return true;
}
bool Ctemporizador::diminuiTempo() {
    tempo -= 5;
    if (tempo < 0) tempo = 0;
    return true;
}
void Ctemporizador::notify() {
    if (aDescontar() && (tempo >0)) {
        tempo--;
        if (tempo == 0) setTempoZero();
    }
}

void Ctemporizador::setTempo(int tempo){
    this->tempo=tempo;
}

void Ctemporizador::setTempoZero(){

}

void Ctemporizador::setSegundos(int segundos){
    this->segundos=segundos;
}

int Ctemporizador::getSegundos(){
   return segundos;
}

int Ctemporizador::getHora(){
    return hora;
}

void Ctemporizador::setHora(int hora){
    this->hora = hora;
}

int Ctemporizador::getMinuto(){
    return minuto;
}

void Ctemporizador::setMinutos(int minuto){
    this->minuto = minuto;
}
