#include "cmicroondas.h"
#include <iostream>

using namespace std;

Cmicroondas::Cmicroondas()
{
    temporizador.setSegundos(0);
    temporizador.setHora(0);
    estado= ESTADOMICROONDAS::RELOGIO;
   // int peso = 0; passar para balanca.setPeso()
    estadoD = ESTADODIAL::TEMPORIZADOR;
    int potencia = 0;
}
void Cmicroondas::notify(){
    temporizador.setSegundos(temporizador.getSegundos()+1);

    if(temporizador.getSegundos()==60){
        temporizador.setMinutos(temporizador.getMinuto()+1);
        temporizador.setSegundos(0);
    }

    if(temporizador.getMinuto()==60){
        temporizador.setHora(temporizador.getHora()+1);
        temporizador.setMinutos(0);
    }

    if(temporizador.getHora() == 24){
        temporizador.setHora(0);
    }

    temporizador.notify();
    temporizador_horas.notify();

    if (getEstado() == ESTADOMICROONDAS::COZINHAR) {
        if (temporizador.getTempo() == 0) {
            setEstado(ESTADOMICROONDAS::COZINHADO);
            temporizador_horas.setTempo(10);
            temporizador_horas.iniciar();
        }
    } else if (getEstado() == ESTADOMICROONDAS::COZINHADO) {
        if (temporizador_horas.getTempo() == 0) {
            setEstado(ESTADOMICROONDAS::RELOGIO);
        }
    } else if (getEstado() == ESTADOMICROONDAS::RELOGIO){

    }
}

string Cmicroondas::getHoras()
{
    stringstream ss;
    int h = temporizador.getHora();
    int m = temporizador.getMinuto();
    ss << setw(2) << setfill('0') << h << ":";
    ss << setw(2) << setfill('0') << m;
    return ss.str();
}

ESTADOMICROONDAS Cmicroondas::getEstado()
{
    return estado;
}

ESTADODIAL Cmicroondas::getEstadoDial()
{
    return estadoD;
}

void Cmicroondas::setEstado(ESTADOMICROONDAS estado)
{
    this->estado = estado;
}

void Cmicroondas::setEstadoDial(ESTADODIAL estadoD)
{
    this->estadoD = estadoD;
}

void Cmicroondas::setPrograma(PROGRAMA programa){
    this->programa = programa;
}

PROGRAMA Cmicroondas::getPrograma(){
    return programa;
}

int Cmicroondas::getTempoRestante() {
    return temporizador.getTempo();
}
void Cmicroondas::setTempoRestante(int tempo_restante) {
    temporizador.setTempo(tempo_restante);
}
bool Cmicroondas::Iniciar(){
    if (temporizador.getTempo()==0)
        this->setTempoRestante(30);
    this->setEstado(ESTADOMICROONDAS::COZINHAR);
    temporizador.iniciar();
    return true;
}
bool Cmicroondas::Pausa(){
    temporizador.pausa();
    return true;
}
bool Cmicroondas::Parar(){
    temporizador.setTempoZero();
    this->setEstado(ESTADOMICROONDAS::RELOGIO);

    return true;
}


void Cmicroondas::setSegundos(int segundos){
   temporizador.setSegundos(segundos);
}

int Cmicroondas::getSegundos(){
   return temporizador.getSegundos();
}

int Cmicroondas::getHora(){
    return temporizador.getHora();
}

void Cmicroondas::setHora(int hora){
    temporizador.setHora(hora);
}

int Cmicroondas::getMinuto(){
    return temporizador.getMinuto();
}

void Cmicroondas::setMinutos(int minuto){
    temporizador.setMinutos(minuto);
}


int Cmicroondas::getPotencia() {
    return this->peso;
}
bool  Cmicroondas::setPotencia(int potencia) {
    this->potencia = potencia;
    return true;
}
