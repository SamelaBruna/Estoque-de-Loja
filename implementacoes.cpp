#include "loja_heranca.h"
#include <cmath>



istream &Produto::digitar(istream &I)
{
  float precoReais = 0.0;
  I.ignore();
  cout << "Nome do produto: ";
  getline(I, nome, '\n');
  cout <<" Preco do produto: ";
  I >> precoReais
  this.preco = (int)(precoReais*100);
  return I;
}

ostream &Produto::imprimir(ostream &O) const
{
  float preco2 = this.preco/100;

  O << ' "'<< nome <<'" '<<';'<<'$'<< preco2;
  return O;
}

 istream &Produto :: ler(istream &I){
  ----------------------------------------------
                    IMPLEMENTAR
  ----------------------------------------------

 }
 ostream &Produto::salvar(ostream &O) const

 {
      -------------------------------------------
                    IMPLEMENTAR
      -------------------------------------------
      return imprimir(O);
 }

inline istream &operator>>(istream &I, Produto &X)
{
     return X.digitar(I); //desnecessário?
}
inline ostream &operator<<(ostream &O, Produto &X)
{
     return X.imprimir(O); //desnecessário?
}



istream &Livro::digitar(istream &I)
{
     Produto::digitar(I);
     I>>autor;

     return I;
}
ostream &Livro::imprimir(ostream &O) const
{
     Produto::imprimir(O);
     O <<';'<<'"'<<autor<<'"';

     return O;

}

istream &Livro :: ler(istream &I){
  //----------------------------------------------
                  //  IMPLEMENTAR
  //----------------------------------------------

 }
 ostream &Livro::salvar(ostream &O) const

{
     // -------------------------------------------
       //             IMPLEMENTAR
      //-------------------------------------------
      return imprimir(O);
}


inline istream &operator>>(istream &I, Livro &L) {return L.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &L) {return L.imprimir(O);}


istream &CD::digitar(istream &I)
{
     Produto::digitar(I);
     I>>nFaixas;

     return I;
}
ostream &CD::imprimir(ostream &O) const
{
     Produto::imprimir(O);
     O <<nFaixas;

     return O;

}
 istream &CD :: ler(istream &I){
  ----------------------------------------------
                    IMPLEMENTAR
  ----------------------------------------------

 }
 ostream &CD::salvar(ostream &O) const
{
      -------------------------------------------
                    IMPLEMENTAR
      -------------------------------------------
      return imprimir(O);
}

inline istream &operator>>(istream &I, CD &C) {return C.digitar(I);}
inline ostream &operator<<(ostream &O, CD &C)  {return C.imprimir(O);}


istream &DVD::digitar(istream &I)
{
     Produto::digitar(I);
     I>>duracao;

     return I;
}
ostream &DVD::imprimir(ostream &O) const
{
     Produto::imprimir(O);
     O << duracao;

     return O;

}
 istream &DVD :: ler(istream &I){
  //----------------------------------------------
                    //IMPLEMENTAR
  //----------------------------------------------

 }
 ostream &DVD::salvar(ostream &O) const
{
    //  -------------------------------------------
      //              IMPLEMENTAR
      //-------------------------------------------
      return imprimir(O);
}

inline istream &operator>>(istream &I, DVD &D) {return D.digitar(I);}
inline ostream &operator<<(ostream &O, DVD &D)  {return D.imprimir(O);}


void ListaLivro::limpar()
{
  delete[] x;
  x = NULL;
  N = 0;
}

void ListaLivro::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new double[N] : NULL );
}

void ListaLivro::copiar(const ListaLivro &LL)
{
  criar(LL.N);
  for (unsigned i=0; i<N; i++) x[i] = LL.x[i];
}

ListaLivro::ListaLivro(unsigned Num)
{
  criar(Num);
  for (unsigned i=0; i<N; i++) x[i] = "";
}

void ListaLivro::incluir(const Livro &L){


}
void ListaLivro::excluir(unsigned id){
     if (id>=N || )
     {
          cerr << "Indice invalido\n";

     }
     if (N == 1)
     {
          delete [] x;
          N = 0;
          x = NULL;
          cout << "Livro excluido com sucesso!\n";
          return;
     }
     Livro *provisorio;
     provisorio = new Livro [N-1];
     for(unsigned i=0; i<N-1; i++)
     {
          if(i >= id)provisorio[i] = x[i+1];

          else provisorio[i]= x[i];

    }
    N = N-1;
    delete [] x;
    x = prov;
    cout << "Livro excluido com sucesso!\n";

}
void ListaLivro::imprimir() const{

    cout << "LISTA LIVRO" << N;

for (unsigned i=0; i<x.N; i++)
{
     cout <<i <<')'<<"L: " << x[i].imprimir();
}


}
void ListaLivro::ler(istream &I);
void ListaLivro::salvar(ostream &O) const;



