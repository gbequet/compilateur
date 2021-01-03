#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_sup.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_supeq.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_inf.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_infeq.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_eq.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_diff.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_and.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_or.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt

    ./scalpa intermediate_examples/test_structure_controle/test_op_bool/test_not.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_conditionnelle.txt


    expected="./intermediate_examples/resultats_test/test_conditionnelle_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_conditionnelle.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'Conditionnelles OK\n'
    else
        printf 'Conditionnelles ERREUR\n'
    fi

fi
