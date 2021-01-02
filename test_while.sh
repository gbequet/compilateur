#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_structure_controle/test_while/test_boucle1.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_while.txt

    ./scalpa intermediate_examples/test_structure_controle/test_while/test_boucle2.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_while.txt



    expected="./intermediate_examples/resultats_test/test_while_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_while.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'While OK\n'
    else
        printf 'While ERREUR\n'
    fi

fi