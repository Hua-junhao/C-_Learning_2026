#include<iostream>
#include<string>
using namespace std;
class Fruit{
protected:
    int weight;
public:
    Fruit(int weight)
    {
        this->weight=weight;
        cout << "Fruit Constructor" << endl;
    }
    virtual ~Fruit() {
        cout << "Fruit Destructor" << endl;
    }
    
    virtual void display(){
        cout << "weight=" << weight<<endl;
    }
};
class Banana:public Fruit{
private:
    string origin;
public:
    Banana(string origin,int weight):Fruit(weight)
    {
        this->origin=origin;
        cout << "Banana Constructor" << endl;
    }
    ~Banana(){
        cout << "Banana Destructor" << endl;
    }
    void display(){
        cout << "origin=" << origin << ",weight=" << weight << endl;
    }
};
int main(){
    Fruit *pf=new Banana("Chongqing",10);;
    pf->display();
    delete pf;
    return 0;
}