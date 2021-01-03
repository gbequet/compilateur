#include "util.h"

void genDebutMips(context_t *context)
{
  fprintf(yyout, ".data\n");
  fprintf(yyout, "newLine: .asciiz \"\\n\"\n");
  fprintf(yyout, "segFaultWarning: .asciiz \"Segmentation fault\"\n");

  fprintf(yyout, "\n.text\n");

  fprintf(yyout, "\nSEGFAULT:\n");
  fprintf(yyout, "li $v0, 4\n");
  fprintf(yyout, "la $a0, segFaultWarning\n");
  fprintf(yyout, "syscall\n");
  fprintf(yyout, "j L%zu\n\n", context->nextquad);

  fprintf(yyout, "\nPOW:\n");
  fprintf(yyout, "add $24, $zero, $zero\n");
  fprintf(yyout, "li $v0, 1\n");

  fprintf(yyout, "\nPOW_LOOP:\n");
  fprintf(yyout, "beq $24, $a1, EXIT_POW\n");
  fprintf(yyout, "mul $v0, $v0, $a0\n");
  fprintf(yyout, "addi $24, $24, 1\n");
  fprintf(yyout, "j POW_LOOP\n");

  fprintf(yyout, "\nEXIT_POW:\n");
  fprintf(yyout, "jr $ra\n");
}

void arithmetique(quad q, int place, char *fct)
{
  entry *e1, *e2;
  if (q.op1.type == QO_CST)
  {
    if (q.op2.type == QO_CST) // [cst;cst]
    {
      fprintf(yyout, "li $24, %d\n", q.op1.u.cst);
      fprintf(yyout, "li $25, %d\n", q.op2.u.cst);
      fprintf(yyout, "%s $%d, $24, $25\n", fct, place);
    }
    else
    {
      e2 = lookup(q.op2.u.name);
      if (e2->typedesc.type == TYPE_INT) // [cst;y]
      {
        fprintf(yyout, "li $24, %d\n", q.op1.u.cst);
        fprintf(yyout, "lw $25, %d($sp)\n", e2->addr_pile);
        fprintf(yyout, "%s $%d, $24, $25\n", fct, place);
      }
      else // [cst;temp]
      {
        fprintf(yyout, "li $24, %d\n", q.op1.u.cst);
        fprintf(yyout, "%s $%d, $24, $%d\n", fct, place, e2->reg);
      }
    }
  }
  else
  {
    e1 = lookup(q.op1.u.name);
    if (q.op2.type == QO_NAME)
    {
      e2 = lookup(q.op2.u.name);
      if (e1->typedesc.type == TYPE_INT)
      {
        fprintf(yyout, "lw $24, %d($sp)\n", e1->addr_pile);

        if (e2->typedesc.type == TYPE_INT) // [x;y]
        {
          fprintf(yyout, "lw $25, %d($sp)\n", e2->addr_pile);
          fprintf(yyout, "%s $%d, $24, $25\n", fct, place);
        }
        else // [x;temp]
        {
          fprintf(yyout, "%s $%d, $24, $%d\n", fct, place, e2->reg);
        }
      }
      else if (e1->typedesc.type == TYPE_ARRAY)
      {
        // [ARR;temp]
        // c'est le seul cas possible et ca n'arrive qu'avec Q_PLUS
        fprintf(yyout, "li $24, %d\n", e1->addr_pile);
        fprintf(yyout, "%s $%d, $24, $%d\n", fct, place, e2->reg);
      }
      else
      {
        if (e2->typedesc.type == TYPE_INT) // [temp;y]
        {
          fprintf(yyout, "lw $24, %d($sp)\n", e2->addr_pile);
          fprintf(yyout, "%s $%d, $%d, $24\n", fct, place, e1->reg);
        }
        else // [temp;temp]
        {
          fprintf(yyout, "%s $%d, $%d, $%d\n", fct, place, e1->reg, e2->reg);
        }
      }
    }
    else
    {
      if (e1->typedesc.type == TYPE_INT) // [x;cst]
      {
        fprintf(yyout, "lw $24, %d($sp)\n", e1->addr_pile);
        fprintf(yyout, "li $25, %d\n", q.op2.u.cst);
        fprintf(yyout, "%s $%d, $24, $25\n", fct, place);
      }
      else // [temp;cst]
      {
        fprintf(yyout, "li $24, %d\n", q.op2.u.cst);
        fprintf(yyout, "%s $%d, $%d, $24\n", fct, place, e1->reg);
      }
    }
  }
}

void puissance(quad q, int place)
{
  entry *e1, *e2;
  if (q.op1.type == QO_CST)
  {
    fprintf(yyout, "li $a0, %d\n", q.op1.u.cst);
    if (q.op2.type == QO_CST) // t := cst ^ cst
    {
      fprintf(yyout, "li $a1, %d\n", q.op2.u.cst);
    }
    else
    {
      e2 = lookup(q.op2.u.name);
      if (e2->typedesc.type == TYPE_INT) // t := cst ^ y
      {
        fprintf(yyout, "lw $a1, %d($sp)\n", e2->addr_pile);
      }
      else // t := cst ^ temp
      {
        fprintf(yyout, "la $a1, $%d\n", e2->reg);
      }
    }
  }
  else
  {
    e1 = lookup(q.op1.u.name);
    if (q.op2.type == QO_NAME)
    {
      e2 = lookup(q.op2.u.name);
      if (e1->typedesc.type == TYPE_INT)
      {
        fprintf(yyout, "lw $a0, %d($sp)\n", e1->addr_pile);
        if (e2->typedesc.type == TYPE_INT) // t := x ^ y
        {
          fprintf(yyout, "lw $a1, %d($sp)\n", e2->addr_pile);
        }
        else // t := x ^ temp
        {
          fprintf(yyout, "la $a1, $%d\n", e2->reg);
        }
      }
      else
      {
        fprintf(yyout, "la $a0, $%d\n", e1->reg);
        if (e2->typedesc.type == TYPE_INT) // t := temp ^ y
        {
          fprintf(yyout, "lw $a1, %d($sp)\n", e2->addr_pile);
        }
        else // t := temp ^ temp
        {
          fprintf(yyout, "la $a1, $%d\n", e2->reg);
        }
      }
    }
    else
    {
      if (e1->typedesc.type == TYPE_INT) // t := x ^ cst
      {
        fprintf(yyout, "lw $a0, %d($sp)\n", e1->addr_pile);
        fprintf(yyout, "li $a1, %d\n", q.op2.u.cst);
      }
      else // t := temp - cst
      {
        fprintf(yyout, "la $a0, $%d\n", e1->reg);
        fprintf(yyout, "li $a1, %d\n", q.op2.u.cst);
      }
    }
  }
  fprintf(yyout, "jal POW\n");
  fprintf(yyout, "move $%d, $v0\n", place);
}

void affectation(quad q, int place)
{
  entry *e1, *eres;
  eres = lookup(q.res.u.name);
  if (q.op1.type == QO_CST) // x := cst
  {
    fprintf(yyout, "li $%d, %d\n", place, q.op1.u.cst);
    fprintf(yyout, "sw $%d, %d($sp)\n", place, eres->addr_pile);
  }
  else if (q.op1.type == QO_NAME)
  {
    e1 = lookup(q.op1.u.name);
    if (e1->typedesc.type == TYPE_INT) // x := y
    {
      fprintf(yyout, "lw $%d, %d($sp)\n", place, e1->addr_pile);   // on chope y dans la pile
      fprintf(yyout, "sw $%d, %d($sp)\n", place, eres->addr_pile); // on sauve x dans la pile
    }
    else // x := temp
    {
      fprintf(yyout, "sw $%d, %d($sp)\n", lastTemp, eres->addr_pile);
    }
  }
}

void lecture(quad q)
{
  entry *eres = lookup(q.res.u.name);
  // on a forcement q.res.type == QO_NAME d'apres la grammaire
  // le cas ou la var est un string est pas traité
  fprintf(yyout, "li $v0, 5\n");
  fprintf(yyout, "syscall\n");
  if (eres->typedesc.type == TYPE_INT)
  {
    fprintf(yyout, "sw $v0, %d($sp)\n", eres->addr_pile);
  }
  else
  {
    if (q.res.for_tab == 1)
    {
      fprintf(yyout, "move $24, $sp\n");
      fprintf(yyout, "add $24, $24, $%d\n", eres->reg-1);
      fprintf(yyout, "sw $v0, ($24)\n");
    }
  }
}

int ecriture(quad q, int place, int cpt_label_str)
{
  entry *eres;

  switch (q.res.type)
  {
  case QO_CST:
    fprintf(yyout, "li $v0, 1\n");
    fprintf(yyout, "li $a0, %d\n", q.res.u.cst);
    break;

  case QO_STRING: // PB : il faut un seul .data
    fprintf(yyout, ".data\n");
    fprintf(yyout, "str%d: .asciiz %s\n", cpt_label_str, q.res.u.str);
    fprintf(yyout, ".text\n");
    fprintf(yyout, "li $v0, 4\n");
    fprintf(yyout, "la $a0, str%d\n", cpt_label_str);
    cpt_label_str++;
    break;

  case QO_NAME:
    eres = lookup(q.res.u.name);    
    if (eres->typedesc.type == TYPE_STRING) // PB : si la variable est un string
    // reviens a resoudre le pb de comment declarer des string (dans le .data ou dans la pile?)
    {
      fprintf(yyout, "li $v0, 4\n");
      fprintf(yyout, "la $a0, %s\n", q.res.u.name);
    }
    else
    {
      if (eres->typedesc.type == TYPE_INT) // write x; où x est un entier
      {
        fprintf(yyout, "lw $%d, %d($sp)\n", place, eres->addr_pile); // on charge x de la pile dans $place
        fprintf(yyout, "li $v0, 1\n");
        fprintf(yyout, "move $a0, $%d\n", place);
      }
      else // write temp; ex: write 1+1;
      {
        if (q.res.for_tab == 1)
        {
          fprintf(yyout, "move $24, $sp\n");
          fprintf(yyout, "add $24, $24, $%d\n", eres->reg);
          fprintf(yyout, "lw $25, ($24)\n");
        }
        else
        {
          fprintf(yyout, "li $v0, 1\n");
          fprintf(yyout, "move $a0, $%d\n", lastTemp);
        }
      }
    }
    break;

  default:
    break;
  }

  fprintf(yyout, "syscall\n");

  // on va a la ligne (plus net)
  fprintf(yyout, "li $v0, 4\n");
  fprintf(yyout, "la $a0, newLine\n");
  fprintf(yyout, "syscall\n");

  return cpt_label_str;
}

void conditionnelle(quad q, char *fct)
{
  entry *e1, *e2;
  if (q.op1.type == QO_CST)
  {
    fprintf(yyout, "li $24, %d\n", q.op1.u.cst);

    if (q.op2.type == QO_CST) // [cst;cst]
    {
      fprintf(yyout, "li $25, %d\n", q.op2.u.cst);
      if (q.res.type == QO_LABEL)
        fprintf(yyout, "%s $24, $25, %s\n", fct, q.res.u.name);
      else
        fprintf(yyout, "%s $24, $25, L%zu\n", fct, q.res.u.etiquette);
    }
    else
    {
      e2 = lookup(q.op2.u.name);
      if (e2->typedesc.type == TYPE_INT) // [cst;y]
      {
        fprintf(yyout, "lw $25, %d($sp)\n", e2->addr_pile);
        if (q.res.type == QO_LABEL)
          fprintf(yyout, "%s $24, $25, %s\n", fct, q.res.u.name);
        else
          fprintf(yyout, "%s $24, $25, L%zu\n", fct, q.res.u.etiquette);
      }
      else // [cst;temp]
      {
        if (q.res.type == QO_LABEL)
          fprintf(yyout, "%s $24, $%d, %s\n", fct, e2->reg, q.res.u.name);
        else
          fprintf(yyout, "%s $24, $%d, L%zu\n", fct, e2->reg, q.res.u.etiquette);
      }
    }
  }
  else
  {
    e1 = lookup(q.op1.u.name);
    if (q.op2.type == QO_NAME)
    {
      e2 = lookup(q.op2.u.name);
      if (e1->typedesc.type == TYPE_INT)
      {
        fprintf(yyout, "lw $24, %d($sp)\n", e1->addr_pile);
        if (e2->typedesc.type == TYPE_INT) // [x;y]
        {
          fprintf(yyout, "lw $25, %d($sp)\n", e2->addr_pile);
          if (q.res.type == QO_LABEL)
            fprintf(yyout, "%s $24, $25, %s\n", fct, q.res.u.name);
          else
            fprintf(yyout, "%s $24, $25, L%zu\n", fct, q.res.u.etiquette);
        }
        else // [x;temp]
        {
          if (q.res.type == QO_LABEL)
            fprintf(yyout, "%s $24, $%d, %s\n", fct, e2->reg, q.res.u.name);
          else
            fprintf(yyout, "%s $24, $%d, L%zu\n", fct, e2->reg, q.res.u.etiquette);
        }
      }
      else
      {
        if (e2->typedesc.type == TYPE_INT) // [temp;y]
        {
          fprintf(yyout, "lw $24, %d($sp)\n", e2->addr_pile);
          if (q.res.type == QO_LABEL)
            fprintf(yyout, "%s $%d, $24, %s\n", fct, e1->reg, q.res.u.name);
          else
            fprintf(yyout, "%s $%d, $24, L%zu\n", fct, e1->reg, q.res.u.etiquette);
        }
        else // [temp;temp]
        {
          if (q.res.type == QO_LABEL)
            fprintf(yyout, "%s $%d, $%d, %s\n", fct, e1->reg, e2->reg, q.res.u.name);
          else
            fprintf(yyout, "%s $%d, $%d, L%zu\n", fct, e1->reg, e2->reg, q.res.u.etiquette);
        }
      }
    }
    else
    {
      if (e1->typedesc.type == TYPE_INT) // [x;cst]
      {
        fprintf(yyout, "lw $24, %d($sp)\n", e1->addr_pile);
        fprintf(yyout, "li $25, %d\n", q.op2.u.cst);
        if (q.res.type == QO_LABEL)
          fprintf(yyout, "%s $24, $25, %s\n", fct, q.res.u.name);
        else
          fprintf(yyout, "%s $24, $25, L%zu\n", fct, q.res.u.etiquette);
      }
      else // [temp;cst]
      {
        fprintf(yyout, "li $24, %d\n", q.op2.u.cst);
        if (q.res.type == QO_LABEL)
          fprintf(yyout, "%s $%d, $24, %s\n", fct, e1->reg, q.res.u.name);
        else
          fprintf(yyout, "%s $%d, $24, L%zu\n", fct, e1->reg, q.res.u.etiquette);
      }
    }
  }
}

void acces_element_tableau(quad q, int place)
{
  // q.res := *q.op1
  entry *e1 = lookup(q.op1.u.name);

  fprintf(yyout, "move $24, $sp\n");
  fprintf(yyout, "add $24, $24, $%d\n", e1->reg);
  fprintf(yyout, "lw $%d, ($24)\n", place);
}

void sauvegarde_element_tableau(quad q)
{
  // *q.op1 := q.res
  entry *e1 = lookup(q.op1.u.name);

  if (q.res.type == QO_CST) // *q.op1 := cst
  {
    fprintf(yyout, "li $24, %d\n", q.res.u.cst);
    fprintf(yyout, "move $25, $sp\n");
    fprintf(yyout, "add $25, $25, $%d\n", e1->reg);
    fprintf(yyout, "sw $24, ($25)\n");
  }
  else
  {
    entry *eres = lookup(q.res.u.name);
    if (eres->typedesc.type == TYPE_INT) // *q.op1 := x
    {
      fprintf(yyout, "lw $24, %d($sp)\n", eres->addr_pile);
      fprintf(yyout, "sw $24, %d\n", e1->reg);
    }
    else // *q.op1 := temp
    {
      fprintf(yyout, "sw $%d, %d\n", eres->reg, e1->reg);
    }
  }
}
