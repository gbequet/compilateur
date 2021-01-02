#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_arithmetique/test_mul_prio.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_priorites.txt


    expected="./intermediate_examples/resultats_test/test_priorites_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_priorites.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'Priorites OK\n'
    else
        printf 'Priorites ERREUR\n'
    fi

fi