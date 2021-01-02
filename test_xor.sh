#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_xor.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_xor.txt


    expected="./intermediate_examples/resultats_test/test_xor_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_xor.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'Xor OK\n'
    else
        printf 'Xor ERREUR\n'
    fi

fi