#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_arithmetique/test_add.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_sub.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_mul.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_div.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_mem.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_sub_tricky.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt

    ./scalpa intermediate_examples/test_arithmetique/test_pow.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_arithmetique.txt



    expected="./intermediate_examples/resultats_test/test_arithmetique_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_arithmetique.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'Operations arithmetiques OK\n'
    else
        printf 'Operations arithmetiques ERREUR\n'
    fi

fi