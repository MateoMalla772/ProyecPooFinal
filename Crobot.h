//
// Created by Mate on 27/11/2019.
//

#ifndef PROYECPOOFINAL_CROBOT_H
#define PROYECPOOFINAL_CROBOT_H
#include "tipos.h"
#include "Corden.h"

class Crobot {
private:
    posicion pos_x;
    posicion pos_y;
    texto nombre;
public:
    Crobot(texto nam, posicion x, posicion y){
        nombre=nam;
        pos_x=x;
        pos_y=y;
    };
    texto get_nombre(){return nombre;}
    valor get_x(){return pos_x;};
    valor get_y(){return pos_y;};
    void set_x(posicion x){
        pos_x=x;
    };
    void set_y(posicion y){
        pos_y=y;
    };


};



#endif //PROYECPOOFINAL_CROBOT_H
