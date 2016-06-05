#ifndef CTEMPORIZADOR_H
#define CTEMPORIZADOR_H


class Ctemporizador
{
    int segundos; 
    int minuto;
    int hora;
    bool count_down;

    int tempo; /* TODO: Verificar para que isto serve viste que as horas estao em separado */

public:

    Ctemporizador() ;
    bool iniciar() ;
    bool pausa();

    void setTempo(int tempo);
    int getTempo();

    bool aDescontar();
    bool aumentaTempo();
    bool diminuiTempo();
    void notify();
    void setTempoZero();

    int getMinuto();
    void setMinutos(int minutos);

    int getHora();
    void setHora(int hora);

    int getSegundos();
    void setSegundos(int segundos);

};

#endif // CTEMPORIZADOR_H
