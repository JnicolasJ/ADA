#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elemento {
    int valor;
    int peso;

};

vector< Elemento > Ve;
int peso_mochila;
int elementos_mochila;


void merge_sort(vector<Elemento>&le, vector<Elemento>&ri, vector<Elemento>&lista)
{
    vector<int>::size_type nl = le.size();
    vector<int>::size_type nr = ri.size();
    int i=0;
    int j=0;
    int k=0;
//    cout<<i<<" <-";
    while(i<le.size() && j<nr)
    {

       /* if(le[i].valor>=ri[j].valor)*/ if(le[i].peso<= ri[j].peso)
        {
            lista[k].valor =le[i].valor;
            lista[k].peso = le[i].peso;

            i=i+1;

        }else
            {
             lista[k].valor = ri[j].valor;
             lista[k].peso = ri[j].peso;
       //      cout<<"falso"<<" ";
             j++;
            }
        k++;
        //cout<<"aumento k"<<endl;
    }
    while(i<nl)
    {
         lista[k].valor = le[i].valor;
         lista[k].peso = le[i]. peso;
         i++;
         k++;
    }

    while (j<nr)
      {
         lista[k].valor = ri[j].valor;
         lista[k].peso = ri[j].peso;
         j++;
         k++;
      }
}

void merge_sort(vector<Elemento>&ve)
{
    int tam = ve.size();

    int med = tam/2;
    if(tam<2)
        return;
    vector<Elemento>letf(med);
    vector<Elemento>rigth(tam-med);
    vector<Elemento>::size_type tam_le = letf.size();
    vector<Elemento>::size_type tam_ri = rigth.size();

    for(int i=0; i<med; i++)
        letf[i] = ve[i];//imprimir(letf);
    for(int j=med; j<tam; j++)
        rigth[j-med] = ve[j];//imprimir(rigth);
    merge_sort(letf);
    merge_sort(rigth);
    merge_sort(letf,rigth,ve);
}


void datos()
{
    ifstream archivo("data.txt");
    if(!archivo)
    {
        cout<<"archivo no existe"<<endl;
        return;
    }

    archivo>>peso_mochila;
    archivo>>elementos_mochila;
    int p;
    int v;
    while(!archivo.eof())
    {
        archivo>>v;
        archivo>>p;
        Elemento el;
        el.valor = v;
        el.peso = p;
        //cout<<el.valor<<" "<<el.peso<<endl;
        Ve.push_back(el);
    }
    /*verificacion de ordenamiento
    for(int i=0; i<Ve.size(); i++)
    {
        cout<<Ve[i].valor<<" "<<Ve[i].peso<<endl;
    }

    merge_sort(Ve);//ordenamiento

     for(int i=0; i<Ve.size(); i++)
    {
        cout<<Ve[i].valor<<" "<<Ve[i].peso<<endl;
    }
	*/
    archivo.close();

}


int mochila_solucion()
{
    merge_sort(Ve);
    unsigned int rpt =0;
    unsigned int valor_total=0;
    for(int i=0; i<Ve.size(); i++)
    {
        if(rpt+Ve[i].peso<peso_mochila)
        {
            rpt+=Ve[i].peso;
            valor_total+= Ve[i].valor;
        }else{
                goto con;
             }
    }
    con:
    cout<<"valor maximo: "<<valor_total<<endl;
    cout<<"peso acumulado: "<<rpt<<endl;
    return valor_total;
}
int main()
{
    datos();
    mochila_solucion();
    return 0;
}
