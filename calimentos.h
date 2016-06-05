#ifndef CALIMENTOS_H
#define CALIMENTOS_H
#include <vector>
#include <iostream>

using namespace std;

class CAlimentos
{
   vector <string> alimentos;
   string alimento;
protected:
    int atual;
public:
    CAlimentos();
    void adicionar(string alimento) ;
    void mudaAlimento();
    string getAlimento();
};

#endif // CALIMENTOS_H
