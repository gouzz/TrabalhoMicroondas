#ifndef CMICROONDAS_H
#define CMICROONDAS_H
#include "ctemporizador.h"
#include "estadomicroondas.h"
#include "estadodial.h"
#include "programa.h"

#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


class Cmicroondas
{
    Ctemporizador temporizador;
    Ctemporizador temporizador_horas;
    ESTADOMICROONDAS estado;
    ESTADODIAL estadoD;
    PROGRAMA programa;
    int peso; // Meter na classe balança.
    int potencia;

public:
    Cmicroondas();
    void notify();

    string getHoras();


    int getTempoRestante();
    void setTempoRestante(int tempo_restante);

    //Funcoes Temporizador

    void setSegundos(int segundos);
    int getSegundos();

    int getMinuto();
    void setMinutos(int minutos);

    int getHora();
    void setHora(int hora);



    bool setPotencia(int potencia);
    int getPotencia();



    bool Iniciar();
    bool Pausa();
    bool Parar();
    void getPeso();

    //Estados:
    ESTADOMICROONDAS getEstado();
    void setEstado(ESTADOMICROONDAS estado);

    void setEstadoDial(ESTADODIAL estadoD);
    ESTADODIAL getEstadoDial();

    PROGRAMA getPrograma();
    void setPrograma(PROGRAMA programa);
};

#endif // CMICROONDAS_H
