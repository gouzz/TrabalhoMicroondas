#include "formamicroondas.h"
#include "ui_formamicroondas.h"
#include "stdio.h"
#include <iostream>
#include "cmicroondas.h"
#include "ctemporizador.h"
#include <QTimer>
#include <QString>


using namespace std;


bool estado = true;


FormaMicroondas::FormaMicroondas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaMicroondas)
{
    ui->setupUi(this);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();


    //  m.setEstado( EMICRO::RELOGIO);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(notify()));
    timer->start(1000);

    m.setEstado(ESTADOMICROONDAS::RELOGIO);
   // m.setEstadoDial(ESTADODIAL::RELOGIOMIN);
    m.setHora(0);
    m.setMinutos(0);
    //ui->imageLabel->setPixmap(QPixmap (":/images/PA.jpg"));

}

void FormaMicroondas::notify() {


    QString d;
    m.notify();
    // QString::number(m.getHora());
    if (m.getEstado() == ESTADOMICROONDAS::RELOGIO) {
        d = QString::fromStdString(m.getHoras());

    } else  if ((m.getEstado() == ESTADOMICROONDAS::TEMPORIZADOR)
                || (m.getEstado() == ESTADOMICROONDAS::COZINHAR)
                || (m.getEstado() == ESTADOMICROONDAS::COZINHADO)) {
        d = QString::number(m.getTempoRestante());
    }/* else  if (m.getEstado() == ESTADOMICROONDAS::PESO) {
        d = QString::number(m.getPeso()) +".";
    }*/else {
    }

    ui->lcd->display(d);


}

FormaMicroondas::~FormaMicroondas()
{
    delete ui;
}

void FormaMicroondas::on_pushBotton_abrirFecharPorta_clicked()
{
    if(estado==true){
        ui->label_porta->hide();
        estado=false;
    }
    else{
        ui->label_porta->show();
        estado=true;
    }
}


void FormaMicroondas::on_pushButton_Relogio_clicked()
{
    if(m.getEstado() == ESTADOMICROONDAS::RELOGIO && m.getEstadoDial() == ESTADODIAL::RELOGIOMIN){
        m.setEstadoDial(ESTADODIAL::RELOGIOHORA);
    } else if (m.getEstado() == ESTADOMICROONDAS::PESO){
        //setPeso
    }else if (m.getEstado() == ESTADOMICROONDAS::ALIMENTOS){
        //setPeso
    }else if (m.getEstado() == ESTADOMICROONDAS::POTENCIA){
        //setPotencia
    }else if( m.getEstado() == ESTADOMICROONDAS::TEMPORIZADOR){
        //setTemporizador
    } else {
        m.setEstadoDial(ESTADODIAL::RELOGIOMIN);
    }
}



void FormaMicroondas::on_dial_sliderMoved(int position)
{
    QString d;

    d = QString::fromStdString(m.getHoras());
    ui->lcd->display(d);

    if(m.getEstado() == ESTADOMICROONDAS::RELOGIO){
        if( m.getEstadoDial() == ESTADODIAL::RELOGIOMIN){
            ui->dial->setMinimum(0);
            ui->dial->setMaximum(59);
            m.setMinutos(position);
        } else if (m.getEstadoDial() == ESTADODIAL::RELOGIOHORA){
            ui->dial->setMinimum(0);
            ui->dial->setMaximum(23);
            m.setHora(position);
        }
    }
    if(m.getEstado() == ESTADOMICROONDAS::RELOGIO && m.getPrograma() == PROGRAMA::MICROONDAS){
        m.setEstadoDial(ESTADODIAL::POTENCIA);
        if(m.getEstadoDial() == ESTADODIAL::POTENCIA){
            ui->dial->setMinimum(250);
            ui->dial->setMaximum(900);
            m.setPotencia(position);
            ui->lcd->display(position);
        }
    }
}

void FormaMicroondas::on_pushButton_CozinhaSaudavel_clicked()
{
    m.setPrograma(PROGRAMA::COZINHA_SAUDAVEL);
    ui->frame_CozinhaSaudavel->show();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_OMeuPrato_clicked()
{
    m.setPrograma(PROGRAMA::MEU_PRATO);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->show();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_Descongelar_clicked()
{
    m.setPrograma(PROGRAMA::DESONGELACAO);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->show();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_Grill_clicked()
{
    m.setPrograma(PROGRAMA::GRILL);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->show();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_Combinado_clicked()
{
    m.setPrograma(PROGRAMA::COMBINADO);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->show();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_CozinhaRapida_clicked()
{
    m.setPrograma(PROGRAMA::COZINHA_RAPIDA);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->show();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_EliCheiros_clicked()
{
    m.setPrograma(PROGRAMA::ELIMINACAO_CHEIROS);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->show();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_Aquecimento_clicked()
{
    m.setPrograma(PROGRAMA::AQUECIMENTO);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->show();
    ui->frame_Microwave->hide();
}

void FormaMicroondas::on_pushButton_Microwave_clicked()
{
    m.setPrograma(PROGRAMA::MICROONDAS);
    ui->frame_CozinhaSaudavel->hide();
    ui->frame_OMeuPrato->hide();
    ui->frame_Descongelar->hide();
    ui->frame_Grill->hide();
    ui->frame_Combinado->hide();
    ui->frame_ComidaRapida->hide();
    ui->frame_EliminacaoCheiros->hide();
    ui->frame_Aquecimento->hide();
    ui->frame_Microwave->show();
}
