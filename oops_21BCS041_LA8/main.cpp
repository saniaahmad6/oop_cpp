#include <bits/stdc++.h>
#include "Point.h"
#include "Location.h"
#include "Vector.h"
#include "Element.h"
#include "PointN.h"
#include <chrono>


using namespace std;

void sort_algo_1(vector<Element *> &to_sort, const int N = 10000)
{
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++)
    {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0)
        {
            if (to_sort[j]->norm() > key->norm())
            {
                to_sort[j + 1] = to_sort[j];
                j -= 1;
            }
            else
            {
                break;
            }
        }
        to_sort[j + 1] = key;
    }
}

void sort_algo_2(vector<Element *> &to_sort, const int N = 10000)
{
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++)
    {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0 && to_sort[j]->norm() > key->norm())
        {
            to_sort[j + 1] = to_sort[j];
            j -= 1;
        }
        to_sort[j + 1] = key;
    }
}



double sortingExecutor1(const int k, bool toPrint = false)
{
    
    vector <Element *> arr(k);

    for (int i=0;i<k;i++){
        if (i%3==0){
            int x=rand()%100,y=rand()%100;
            arr[i]=new Point(x,y);
        }else if (i%3==1){
            int x=rand()%100,y=rand()%100;
            arr[i]=new Vector(x,y);
        }else{
            int dimension=rand()%9+2;
            double *temp=new double[dimension];
            for (int i=0;i<dimension;i++){
                temp[i]=rand()%100;
            }
            arr[i]=new PointN(temp,dimension);
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    sort_algo_1(arr, k);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < k; i++)
        {
            arr[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

double sortingExecutor2(const int k, bool toPrint = false)
{
    
    vector <Element *> arr(k);

    for (int i=0;i<k;i++){
        if (i%3==0){
            int x=rand()%100,y=rand()%100;
            arr[i]=new Point(x,y);
        }else if (i%3==1){
            int x=rand()%100,y=rand()%100;
            arr[i]=new Vector(x,y);
        }else{
            int dimension=rand()%9+2;
            double *temp=new double[dimension];
            for (int i=0;i<dimension;i++){
                temp[i]=rand()%100;
            }
            arr[i]=new PointN(temp,dimension);
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    sort_algo_2(arr, k);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < k; i++)
        {
            arr[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}



int main(){

    cout<<"hello;";
    int SIZES[5] = {10, 100, 1000, 10000, 20000};
    for (int i = 0; i <5; i++)
    {
        double time1 = sortingExecutor1(SIZES[i]);
        double time2 = sortingExecutor2(SIZES[i]);

        if (time2!=0) cout << "Speed Ratio = " << time1 / time2 << endl;
        if (time1!=0) cout << "Speed Ratio = " << time2 / time1 << endl;
        cout << endl;
    }
    return 0;

}



