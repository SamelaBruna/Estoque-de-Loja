#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;

class Produto
{
private:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};

inline istream &operator>>(istream &I, Produto &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Produto &X) {return X.imprimir(O);}

class Livro: public Produto
{
private:
    string autor;

public:
     inline Livro(): Produto(), autor(""){} // construtor default
     inline Livro(const char *N,const unsigned P, const char *A): Produto(N,P), autor(A) {} //especifico
     istream &digitar(istream &I);
     ostream &imprimir(ostream &O) const;
     istream &ler(istream &I);
     inline ostream &salvar(ostream &O) const {return imprimir(O);}

};

inline istream &operator>>(istream &I, Livro &L) {return L.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &L) {return L.imprimir(O);}


class CD: public Produto
{
private:
     unsigned nFaixas;

public:

     inline CD(): Produto(), nFaixas(0){} // construtor default
     inline CD(const char *N,const unsigned P, const int NF): Produto(N,P), nFaixas(NF) {} //especifico
     istream &digitar(istream &I);
     ostream &imprimir(ostream &O) const;
     istream &ler(istream &I);
     inline ostream &salvar(ostream &O) const {return imprimir(O);}

};

inline istream &operator>>(istream &I, CD &C) {return C.digitar(I);}
inline ostream &operator<<(ostream &O, CD &C)  {return C.imprimir(O);}

class DVD: public Produto
{
private:
     unsigned duracao;

public:

     inline DVD(): Produto(), duracao(0){} // construtor default
     inline DVD(const char *N,const unsigned P, const int D): Produto(N,P), duracao(D) {} //especifico
     istream &digitar(istream &I);
     ostream &imprimir(ostream &O) const;
     istream &ler(istream &I);
     inline ostream &salvar(ostream &O) const {return imprimir(O);}

};

inline istream &operator>>(istream &I, DVD &D) {return D.digitar(I);}
inline ostream &operator<<(ostream &O, DVD &D)  {return D.imprimir(O);}


class ListaLivro
{
private:
    Livro *x;
    unsigned N;
    void criar(unsigned Num);
    void copiar(const ListaLivro &LL);
    void limpar();

public:

    inline ListaLivro(): N(0), x(NULL) {}
    inline ListaLivro(const ListaLivro &LL) {copiar(LL);}
    inline ListaLivro(unsigned Num) {criar(Num);}

    void incluir(const Livro &L);
    void excluir(unsigned id);
    ostream &imprimir(ostream &O) const;
    void ler(istream &I);
    ostream &salvar(ostream &O) const;

    inline ~ListaLivro() {limpar();}
};

class ListaCD
{
private:
    CD *x;
    unsigned N;
    void copiar(const ListaCD &LCD);
    void criar(unsigned Num);
    void limpar();

public:

    inline ListaCD(): N(0), x(NULL) {}
    inline ListaCD(const ListaCD &LCD) {copiar(LCD);}
    inline ListaCD(unsigned Num) {criar(Num);}

    void incluir(const CD &C);
    void excluir(unsigned id);
    ostream &imprimir(ostream &O) const;
    void ler(istream &I);
    ostream &salvar(ostream &O) const;

    inline ~ListaCD() {limpar();}
};


  class ListaDVD
{
private:
    DVD *x;
    unsigned N;
    void copiar(const ListaDVD &LDV);
    void criar(unsigned Num);
    void limpar();

public:

    inline ListaDVD(): N(0), x(NULL) {}
    inline ListaDVD(const ListaDVD &LDV) {copiar(LDV);}
    inline ListaDVD(unsigned Num) {criar(Num);}

    void incluir(const DVD &DV);
    void excluir(unsigned id);
    ostream &imprimir(ostream &o) const;
    void ler(istream &I);
    ostream &salvar(ostream &O) const;

    inline ~ListaDVD() {limpar();}
};


class Loja
{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned id) {LC.excluir(id);}
    void imprimir(ostream &O) const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};
#endif // _LOJA_H_
