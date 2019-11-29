//
// Created by Mate on 25/11/2019.
//

#include "Calmacen.h"
#include "tipos.h"
#include "Cproducto.h"
#include "Crobot.h"

Calmacen::Calmacen(valor c, valor f):col{c},fil{f},slots(fil,vector<texto>(col)),v(){
}
void Calmacen::almacen_vacio() {
    for (auto& row:slots)
        for (auto& item:row)
            item="*";
}
void Calmacen::imprimir_almacen_vacio(){
    cout<<"Este es el almacen vacío:"<<endl;
    for (auto& row:slots){
        for (auto& item:row){cout<<setw(4)<<item;}
        cout<<endl;}
}
void Calmacen::agregar_productos(Cproducto P){
    slots[P.get_x()][P.get_y()] = P.get_letra();
}

void Calmacen::imprimir_almacen() {
    for (auto& row:slots){
        for (auto& item:row){cout<<setw(8)<<item;}
        cout<<endl;}
}

void Calmacen::agregar_robot(Crobot *rt) {
    slots[rt->get_x()][rt->get_y()] = rt->get_nombre();
}

void Calmacen::rellenar_vector_robots(Crobot* R){
    v.push_back(R);
}

void Calmacen::usar_robot() {
    texto a=" ";
    cout<<"Indique el nombre del robot (Ex-->R1):";cin>>a;
    posicion x=0,y=0;
    posicion robottt=0;
    posicion u=0,o=0;
    cout<<"hola";
    for (cantidad i=0;i<v.size();i++) {
        if ((v[i]->get_nombre() )== a) {
            cout << "Robot existente"<<endl;
            x = v[i]->get_x();
            y = v[i]->get_y();
            cout << "Indique la posicion a x:";
            cin >> u;
            cout << "Indique la posicion a y:";
            cin >> o;
            robottt=i;
        }
    }
    cout<<"Hola";
    vector<vector<posicion>>posicionesxy;
    //x
    int i=0;
    if(y!=o){
        do{
            posicionesxy[i].push_back(x);
            posicionesxy[i].push_back(y);
            y++;
            i++;
        }while(x!=u);
    }
    if(x!=u){
        do{
            posicionesxy[i].push_back(x);
            posicionesxy[i].push_back(y);
            x++;
            i++;
        }while(x!=u);
    }
    for(int i=0; i<posicionesxy.size();i++){
        v[robottt]->set_x(posicionesxy[i][0]);
        v[robottt]->set_y(posicionesxy[i][1]);
        for (auto& row:slots){
            for (auto& item:row){cout<<setw(8)<<item;}
            cout<<endl;}
    }

}



/*void Calmacen::rellenar_vector_productos(Cproducto *& P) {
    n.push_back(P);
}*/

Calmacen crear_almacen(istream& in){
    valor c1=0;
    valor f1=0;
    cout<<"#N de Columnas:";
    in>>c1;
    cout<<"#N de Filas:";
    in>>f1;
    Calmacen A(c1,f1);
    return A;}

void indicar_productos(Calmacen& A1, istream& in){
    cantidad n;texto t;let r;posicion x;posicion y;cantidad c;
    cout<<"Indique la cantidad de productos que va a ingresar:";in>>n;
    for (cantidad i=0;i<n;i++){
        cout<<"Indique el producto a ingresar:";in>>t;
        cout<<"Con que letra lo va a representar:";in>>r;
        cout<<"Indique a que posicion quiere mandarlo:"<<endl;
        cout<<"Posicion x:";in>>x;
        cout<<"Posicion y:";in>>y;
        cout<<"Cantidad del producto:";in>>c;
        if (c<=0) {cout<<"Indique una cantidad válida:";in>>c;}
        else if (x>A1.get_col()){cout<<"Posición no válida, indique una nueva:";in>>x;}
        else if (y>A1.get_fil() || y==1){cout<<"Posición no válida, indique una nueva:";in>>y;}
        Cproducto P(t,r,x-1,y-1,c);
        A1.agregar_productos(P);}
}

void indicar_robots(Calmacen& A1,istream& in){
    cantidad n=A1.get_fil();t_posicion x=0;t_posicion y=0;texto nom;
    for (cantidad i = 0; i < n; i++) {
        cout<<"Indique el nombre del robot:";in>>nom;
        Crobot *rt=new Crobot(nom, x, y);
        auto *ptrR=&rt;
        A1.rellenar_vector_robots(rt);
        A1.agregar_robot(rt);
        x=x+1;

    }
}


//void dejar_producto();
//void retornar_casa();