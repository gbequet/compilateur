#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then
    ./test_arithmetique.sh $1
    ./test_priorites.sh $1
    ./test_conditionnelle.sh $1
    ./test_tableaux.sh $1
    ./test_while.sh $1
    ./test_xor.sh $1
fi