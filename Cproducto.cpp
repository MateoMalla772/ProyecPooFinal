//
// Created by Mate on 25/11/2019.
//

#include "Cproducto.h"
#include "tipos.h"
Cproducto::Cproducto(texto n, let l, posicion x,posicion y,cantidad c):nombre{n},letra{l},posx{x},posy{y},cuantos{c}{

}

void Cproducto::set_nombre(texto n) {
    cout<<"Indique el nombre del producto: ";
    cin>>n;
    nombre=n;
}

texto Cproducto::get_nombre() {
    return nombre;
}

void Cproducto::set_letra(let l) {
    cout<<"Indique la letra para representar el producto: ";
    cin>>l;
    letra=l;
}

let Cproducto::get_letra() {
    return letra;
}
