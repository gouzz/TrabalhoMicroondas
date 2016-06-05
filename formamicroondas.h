#ifndef FORMAMICROONDAS_H
#define FORMAMICROONDAS_H
#include "cmicroondas.h"
#include <QMainWindow>


namespace Ui {
class FormaMicroondas;
}

class FormaMicroondas : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaMicroondas(QWidget *parent = 0);
    ~FormaMicroondas();

private slots:
    void on_pushBotton_abrirFecharPorta_clicked();
    //void on_dial_sliderMoved(int position);


    void notify();

    void on_pushButton_Relogio_clicked();



    void on_dial_sliderMoved(int position);

    void on_pushButton_CozinhaSaudavel_clicked();

    void on_pushButton_OMeuPrato_clicked();

    void on_pushButton_Descongelar_clicked();

    void on_pushButton_Grill_clicked();

    void on_pushButton_Combinado_clicked();

    void on_pushButton_CozinhaRapida_clicked();

    void on_pushButton_EliCheiros_clicked();

    void on_pushButton_Aquecimento_clicked();

    void on_pushButton_Microwave_clicked();

private:
    Ui::FormaMicroondas *ui;
    Cmicroondas m;
    QTimer *timer;

    /*
    QWidget *WTecladoNumerico();
    QMenu *helpMenu;
    void about();
    bool loadFile(const QString &fileName);
    void MudaImagens(const QString &fileName_porta, const QString &fileName_comida, int peso);
*/
};

#endif // FORMAMICROONDAS_H
