#include "loja_heranca.h"
#include <cmath>
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

istream &Produto::digitar(istream &I)
{
  float precoReais = 0.0;
  I.ignore();
  cout << "Nome do produto: ";
  getline(I, nome, '\n');
  cout <<" Preco do produto: ";
  I >> precoReais;
  this->preco = (int)(precoReais*100);
  return I;
}

ostream &Produto::imprimir(ostream &O) const
{
  float preco2 = (float) this->preco/100;

  O << '"'<< nome <<'"'<<';'<<'$'<< preco2;
  return O;
}

 istream &Produto :: ler(istream &I)
 {

     float pr;
     I.ignore(numeric_limits<streamsize>::max(), '"');
     getline(I, nome, '"');

     I.ignore(numeric_limits<streamsize>::max(), '$');
     I >> pr;
     preco = pr*100;

     return I;

 }


istream &Livro::digitar(istream &I)
{
     Produto::digitar(I);
     cout << "Nome do autor: ";
     I.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(I, autor, '\n');

     return I;
}
ostream &Livro::imprimir(ostream &O) const
{
     O << "L: ";
     Produto::imprimir(O);
     O <<';'<<'"'<<autor<<'"';

     return O;

}

istream &Livro :: ler(istream &I){
     Produto:: ler(I);
     I.ignore(numeric_limits<streamsize>::max(), '"');
     getline(I, autor, '"');

     return I;

 }


istream &CD::digitar(istream &I)
{
     Produto::digitar(I);
     cout <<"Numero de faixas: ";
     I.ignore();
     I>>nFaixas;

     return I;
}
ostream &CD::imprimir(ostream &O) const
{
     O <<"C: ";
     Produto::imprimir(O);
     O <<';'<<nFaixas;

     return O;

}
 istream &CD :: ler(istream &I)
 {
     Produto:: ler(I);
     I.ignore(numeric_limits<streamsize>::max(), ';');
     I >> nFaixas;

     return I;

 }


istream &DVD::digitar(istream &I)
{
     Produto::digitar(I);
     cout <<"Duracao: ";
     I.ignore();
     I>>duracao;

     return I;
}
ostream &DVD::imprimir(ostream &O) const
{
     O << "D: ";
     Produto::imprimir(O);
     O << ';' << duracao;

     return O;

}
 istream &DVD :: ler(istream &I)
 {
     Produto:: ler(I);
     I.ignore(numeric_limits<streamsize>::max(), ';');
     I >> duracao;

     return I;


 }




void ListaLivro::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new Livro [N] : NULL );
}

void ListaLivro::copiar(const ListaLivro &LL)
{
  criar(LL.N);
  for (unsigned i=0; i<N; i++) x[i] = LL.x[i];
}

void ListaLivro::limpar()
{
     if(x==NULL)
     {
          N = 0;
     }
     else
     {
          delete[] x;
          x = NULL;
          N = 0;

     }
}

void ListaLivro::incluir(const Livro &L)
{

     Livro *provisorio;
     provisorio = new Livro [N+1];
     for(unsigned i=0; i<N; i++) provisorio[i] = x[i];
     provisorio[N] = L;
     N = N+1;
     delete [] x;
     x = provisorio;
     cout << "Livro incluido com sucesso!\n";

}
void ListaLivro::excluir(unsigned id){
     if (id>=N )
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
    x = provisorio;
    cout << "Livro excluido com sucesso!\n";

}
ostream &ListaLivro::imprimir(ostream &O) const
{

     O << "LISTALIVRO " << N << endl;

     for (unsigned i=0; i<this->N; i++)
     {
          O << i << ")";
          x[i].imprimir(O);
          O << endl;
     }

     return O;
}
void ListaLivro::ler(istream &I)
{
    I >> N;
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    x = new Livro [N];
    for(unsigned i=0; i<N; i++) x[i].ler(I);

}
ostream &ListaLivro::salvar(ostream &O) const
{
 O << "LISTALIVRO " << N << endl;

     for (unsigned i=0; i<this->N; i++) //x.n ou N?
     {
          x[i].imprimir(O);
          O << endl;
     }

     return O;

}

void ListaCD::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new CD [N] : NULL );
}

void ListaCD::copiar(const ListaCD &LCD)
{
  criar(LCD.N);
  for (unsigned i=0; i<N; i++) x[i] = LCD.x[i];
}

void ListaCD::limpar()
{
     if(x==NULL)
     {
          N = 0;
     }
     else
     {
          delete[] x;
          x = NULL;
          N = 0;

     }
}

void ListaCD::incluir(const CD &C)
{

     CD *provisorio;
     provisorio = new CD [N+1];
     for(unsigned i=0; i<N; i++) provisorio[i] = x[i];
     provisorio[N] = C;
     N = N+1;
     delete [] x;
     x = provisorio;
     cout << "CD incluido com sucesso!\n";
}

void ListaCD::excluir(unsigned id){
     if (id>=N )
     {
          cerr << "Indice invalido\n";

     }
     if (N == 1)
     {
          delete [] x;
          N = 0;
          x = NULL;
          cout << "CD excluido com sucesso!\n";
          return;
     }
     CD *provisorio;
     provisorio = new CD [N-1];
     for(unsigned i=0; i<N-1; i++)
     {
          if(i >= id)provisorio[i] = x[i+1];

          else provisorio[i]= x[i];

    }
    N = N-1;
    delete [] x;
    x = provisorio;
    cout << "CD excluido com sucesso!\n";

}
ostream &ListaCD::imprimir(ostream &O) const
{

     O << "LISTACD " << N << endl;

     for (unsigned i=0; i<this->N; i++)
     {
          O << i << ")";
          x[i].imprimir(O);
          O << endl;
     }

     return O;
}
void ListaCD::ler(istream &I)
{
    I.ignore(8);
    I >> N;
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    x = new CD [N];
    for(unsigned i=0; i<N; i++) x[i].ler(I);

}
ostream &ListaCD::salvar(ostream &O) const
{
 O << "LISTACD " << N << endl;

     for (unsigned i=0; i<this->N; i++)
     {
          x[i].imprimir(O);
          O << endl;
     }

     return O;

}

void ListaDVD::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new DVD [N] : NULL );
}

void ListaDVD::copiar(const ListaDVD &LDV)
{
  criar(LDV.N);
  for (unsigned i=0; i<N; i++) x[i] = LDV.x[i];
}

void ListaDVD::limpar()
{
     if(x==NULL)
     {
          N = 0;
     }
     else
     {
          delete[] x;
          x = NULL;
          N = 0;

     }
}
void ListaDVD::incluir(const DVD &DV)
{

     DVD *provisorio;
     provisorio = new DVD [N+1];
     for(unsigned i=0; i<N; i++) provisorio[i] = x[i];
     provisorio[N] = DV;
     N = N+1;
     delete [] x;
     x = provisorio;
     cout << "DVD incluido com sucesso!\n";
}

void ListaDVD::excluir(unsigned id){
     if (id>=N )
     {
          cerr << "Indice invalido\n";

     }
     if (N == 1)
     {
          delete [] x;
          N = 0;
          x = NULL;
          cout << "DVD excluido com sucesso!\n";
          return;
     }
     DVD *provisorio;
     provisorio = new DVD [N-1];
     for(unsigned i=0; i<N-1; i++)
     {
          if(i >= id)provisorio[i] = x[i+1];

          else provisorio[i]= x[i];

    }
    N = N-1;
    delete [] x;
    x = provisorio;
    cout << "DVD excluido com sucesso!\n";

}
ostream &ListaDVD::imprimir(ostream &O) const
{

     O << "LISTADVD " << N << endl;

     for (unsigned i=0; i<this->N; i++)
     {
          O << i << ")";
          x[i].imprimir(O);
          O << endl;
     }

     return O;
}
void ListaDVD::ler(istream &I)
{
    I.ignore(9);
    I >> N;
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    x = new DVD [N];
    for(unsigned i=0; i<N; i++) x[i].ler(I);

}

ostream &ListaDVD::salvar(ostream &O) const
{
 O << "LISTADVD " << N << endl;

     for (unsigned i=0; i<this->N; i++)
     {
          x[i].imprimir(O);
          O << endl;
     }

     return O;

}


void Loja::imprimir(ostream &O) const
{
     LL.imprimir(O);
     LC.imprimir(O);
     LD.imprimir(O);

}
void Loja::ler(const char* arq)
{
     ifstream arquivo(arq);
     if (arquivo.is_open())
     {
          string prov;
          arquivo >> prov;
               if (prov != "LISTALIVRO")
               {
                    cerr << "Arquivo com cabecalho invalido\n";
                    return;
               }

               else
               {
                    LL.ler(arquivo);
                    LC.ler(arquivo);
                    LD.ler(arquivo);
                    cerr << "Arquivo lido com sucesso!" <<endl;
               }
        arquivo.close();
     }
     else
     {
          cerr << "Erro ao ler o arquivo!\n";
     }

}


void Loja::salvar(const char* arq) const
{
     ofstream arquivo(arq);
     if(arquivo.is_open())
     {
        cerr << "Salvando o arquivo..." << endl;
        LL.salvar(arquivo);
        LC.salvar(arquivo);
        LD.salvar(arquivo);

        arquivo.close();
        cout << "Arquivo " << arq << " salvo com sucesso!\n";
    }
    else
     {
        cout << "Erro ao salvar o arquivo " << arq <<"!";
     }

}



