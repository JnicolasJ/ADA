#include <iostream>
#include <fstream>
#include<stdio.h>
#include <windows.h>
#include <vector>
using namespace std;

int peso_mochila,  wt[],   val[],  eleme_mochila;

int max(int a, int b) { return (a > b)? a : b; }



int knapSack()
{
   int i, w;

   int K[elem_mochila+1][peso_mochila+1];// este es el problema al crear una matriz demandando mucha memoria
   for (i = 0; i <= eleme_mochila; i++)
   {
       for (w = 0; w <= peso_mochila; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[eleme_mochila][peso_mochila];
}

int main()
{

    ifstream archivo ("data.txt");
    if(!archivo)
        cout<<" no se encuentr archivo"<<endl;
    unsigned int peso_mochila;
    unsigned int eleme_mochila;
    archivo>>peso_mochila;
    archivo>>eleme_mochila;


    int tmp, tmp1;
    int q=0;
    int val[eleme_mochila];
    int wt[eleme_mochila];
    while(!archivo.eof())
    {
        archivo>>tmp;
        archivo>>tmp1;

            val[q] = tmp;

            wt[q] = tmp1;

            cout<<"agregado "<<tmp<<" peso "<<tmp1<<endl;
            ++q;

    }

    cout<<"elementos agregados"<<endl;

    int knapSack();

    return 0;
}
