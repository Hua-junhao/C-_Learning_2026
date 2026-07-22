/*
 * Source: PTA (Programming Teaching Assistant)
 * Problem ID: 6-1
 * Title: 对象指针与对象数组（拉丁舞）
 * Knowledge: Class, Object Pointer, Logic Simulation
 * Author: Hua-junhao
 */
#include <iostream>
#include <string>
using namespace std;
const int K=2;
const int N=20;
class Student{
  string name;
  Student *welcome[K];
  Student *pair;
  public:
      void init(string &name, Student *a, Student *b) {
        this->name=name; 
        welcome[0]=a;
        welcome[1]=b;
        pair=NULL;
      }
     void printPair();
     void addPair();        
};
void Student::addPair()
{
    if (pair!=NULL) return;
    for (int i=0;i<2;i++)
    {
        Student *B=welcome[i];
        if (B->pair!=NULL) continue;
        bool like=0;
        if (B->welcome[0]==this || B->welcome[1]==this)
        {
            like =1;
        }
        bool nochoice=0;
        if (B->welcome[0]->pair!=NULL&&B->welcome[1]->pair!=NULL)
        {
            nochoice=1;
        }
        if (like || nochoice)
        {
            pair=B;
            B->pair=this;
            return;
        }

    }             
}
void Student::printPair() 
{
    if (pair != NULL)
    {
        cout << name << ":" << pair->name << endl;
    }
}
int main(){
    Student male[N], female[N];
    int m, f, i, j, a, b;
    string name;
    cin>>m;
    for(i=0;i<m;i++){
      cin>>name>>a>>b;
      male[i].init(name, &female[a], &female[b]);
    }
    cin>>f;
    for(i=0;i<f;i++){
      cin>>name>>a>>b;
      female[i].init(name, &male[a], &male[b]);
    }
    for(i=0;i<m;i++) male[i].addPair();
    for(i=0;i<f;i++) female[i].addPair();
    for(i=0;i<m;i++) male[i].printPair();
    return 0;
}
