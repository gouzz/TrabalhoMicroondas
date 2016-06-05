#include "calimentos.h"

CAlimentos::CAlimentos()
{

}
void CAlimentos::adicionar(string alimento) {
    alimentos.push_back(alimento);
    atual = 0;
}
void CAlimentos::mudaAlimento() {
    atual = ++atual % alimentos.size();
}
string CAlimentos::getAlimento() { return alimentos[atual];}
