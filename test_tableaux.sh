#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Usage : $0 n"
    echo "où n indique le nombre de ligne que spim affiche au debut de son execution (en general 2 ou 6)"
fi

if [ "$#" -eq 1 ]; then

    ./scalpa intermediate_examples/test_tableaux/test_tab1.txt > /dev/null
    spim -file prog.asm | tail -n +$1 > intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tab2.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tab3.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tab4.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tab5.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tab6.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt

    ./scalpa intermediate_examples/test_tableaux/test_tabsegfault.txt > /dev/null
    spim -file prog.asm | tail -n +$1 >> intermediate_examples/resultats_test/test_tableaux.txt




    expected="./intermediate_examples/resultats_test/test_tableaux_expected.txt"
    obtenu="./intermediate_examples/resultats_test/test_tableaux.txt"

    if cmp -s "$expected" "$obtenu"; then
        printf 'Tableaux OK\n'
    else
        printf 'Tableaux ERREUR\n'
    fi

fi