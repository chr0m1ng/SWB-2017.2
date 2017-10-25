/* 
 * SWB:APP Data Lab 
 * 
 * Gabriel Rodrigues dos Santos
 * 
 * bits.c - Arquivo fonte com suas soluções para o Lab.
 *          Este é o arquivo que você irá manipular e enviar para seu instrutor.
 *
 * ATENÇÃO: Não inclua a biblioteca <stdio.h>; ela confude o compilador dlc.
 * Você pode utilizar printf para depuração sem incluir <stdio.h>, você terá
 * apenas um "warning" do compilador. De forma geral, não é uma boa prática ignorar
 * os avisos do compilador, mas neste caso tudo bem.  
 */

#if 0
/*
 * Instruções para os estudantes:
 *
 * PASSO 1: Leia as instruções seguintes cuidadosamente.
 */

Você irá prover sua solução ao Data Lab pela edição da coleção
de funções neste arquivo fonte.

REGRAS PARA CODIFICAÇÃO DE INTEIROS:
 
  Troque a instrução "return" em cada função com uma ou mais linhas
  de código C que implementa a função. O seu código deve estar em
  conformidade ao seguinte estilo:
   
  int Funct(arg1, arg2, ...) {
      /* Breve descrição de como sua implementação funciona */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Cada "Expr" é uma expressão utilizando SOMENTE:  
  1. Inteiros constantes de 0 até 255 (0xFF), inclusive. Você não está
      autorizado a utilizar grandes constantes como 0xffffffff.
  2. Argumentos de funções e variáveis locais (sem variáveis e globais).
  3. Operações inteiras unárias ! ~
  4. Operações inteiras Binárias & ^ | + << >>
    
  Alguns dos problemas restrigem ainda mais o conjunto de operadores permitidos.
  Cada "Expr" pode consistir de múltiplos operadores. Você não está restrito à 
  um operador por linha.
  
  Você está expressamente proibido de:
  1. Usar qualquer estrutura de controle como if, do, while, for, switch, etc.
  2. Definir ou utilizar qualquer macro.
  3. Definir qualquer função adicional neste arquivo.
  4. Chamar qualquer função.
  5. Usar qualquer outro tipo de operação, tais como &&, ||, -, or ?:
  6. Usar qualquer tipo de casting.
  7. Usar qualque tipo de dado que não seja int. Isto implica que você não 
     pode utilizar arrays, estruturas, ou uniões.

 
  Você deve assumir que sua máquina:
  1. Utiliza a representação de inteiros em 32-bits e em complemento de 2.
  2. Realiza deslocamento aritmético à direita.
  3. Possui um comportamento inesperado quando um inteiro é deslocado por mais que
     o tamanho da palavra.

EXEMPLOS DE ESTILO DE CÓDIGO ACEITÁVEL:
  /*
   * pot2mais1 - retorna 2^x + 1, onde 0 <= x <= 31
   */
  int pot2mais1(int x) {
     /* explora a habilidade de deslocamentos calcular potências de 2 */
     return (1 << x) + 1;
  }

  /*
   * pot2mais4 - retorna 2^x + 4, onde 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* explora a habilidade de deslocamentos calcular potências de 2 */
     int resultado = (1 << x);
     resultado += 4;
     return resultado;
  }

REGRAS DE CODIFICAÇÃO PONTO FLUTUANTE

Para os problemas em que você irá implementar operações de ponto flutuante,
as regras de codificação são menos restritas. Você poderá utilizar controle 
de repetição e condicional. Você está permitido a utilizar ambos int e unsigned.
Você pode utilizar constantes arbitrárias inteiras e sem sinal.

Você está expressamente proibido de:
  1. Definir ou utilizar qualquer macro.
  2. Definir qualquer função adicional neste arquivo.
  3. Chamar qualquer função.
  4. Usar qualquer tipo de casting.
  5. Usar qualque tipo de dado que não seja int ou unsigned. Isto implica que você não 
     pode utilizar arrays, estruturas, ou uniões.
  6. Usar qualquer tipo de dados ponto flutuante, operações ou constantes.


NOTAS:
  1. Utilize o compilador (descrito na atividade) dlc (data lab checker) para 
     checar a legalidade de suas soluções.
  2. Cada função tem um número máximo de operadores (! ~ & ^ | + << >>)
     que você está permitido utilizar para implementação de sua função. 
     A contagem de operadores máxima é conferida pelo dlc. Note que '=' não é 
     contado; você pode utilizar quantos forem necessários sem penalidade.
  3. Use a ferramenta btest para testar a corretude de suas funções.
  4. Use BDD checker para verificar formalmente suas funções.
  5. O número máximo de operações para cada função é dada no comentário do
     cabeçalho de cada função. Se houver qualquer inconsistência entre o número
     máximo de operações entre a atividade (pdf) e este arquivo, considere este
     arquivo com referência.

/*
 * PASSO 2: Modifique as seguintes funções de acordo as regras de codificação.
 * 
 *   IMPORTANTE. PARA EVITAR SURPRESAS NA NOTA:
 *   1. Utilize o compilador dlc para conferir que sua solução está conforme a 
 *      as regras de codificação.
 *   2. Use o BDD checker para formalmente verificar que sua solução produz 
 *      as respostas corretas.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * binNOU - ~(x|y) usando somente ~ and & 
 *   Exemplo: binNOU(0x6, 0x5) = 0xFFFFFFF8
 *   Operadores Permitidos: ~ &
 *   Max ops: 8
 *   Nível: 1
 */
int binNOU(int x, int y) 
{
  return (~x & ~y);
}
/* 
 * bitsPares - retorna 1 se todos os bits pares na palavra são 1
 *   Exemplos: bitsPares(0xFFFFFFFE) = 0, bitsPares(0x55555555) = 1
 *   Operadores permitidos: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Nível: 2
 */
int bitsPares(int x) 
{
  int maskPar = 0x55555555; //Mask com somente os bits pares setados
  int newX = x & maskPar; //AND com a Mask para setar os bits impares como 0 e manter os bits pares originais
  return !(newX ^ maskPar); //XOR com a Mask, os impares devem ficar sempre 0 e caso todos os pares sejam 1 o numero sera 0, caso contrario será algum numero diferente de zero, negação para retornar 0 ou 1
}
/* 
 * mascaraBit - Gera uma mascara consistindo de todos os bits altos e baixos de 1's 
 *   Exemplos: mascaraBit(5,3) = 0x38
 *   Assuma 0 <= baixo <= 31, and 0 <= alto <= 31
 *   Se baixo > alto, então a mascara deverá ter 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int mascaraBit(int alto, int baixo) 
{
  int mask1 = ~0;
  int newAltoMask = (mask1 << alto) << 1; //Coloca alto + 1 zeros no final e o resto 1
  int newBaixoMask = mask1 << baixo; //Coloca baixo zero no final e o resto 1
  
  return (newAltoMask ^ newBaixoMask) & newBaixoMask; //XOR para pegar a diferença das duas Mask AND aplica Mask Baixo quando baixo > alto, caso contrario o AND não terá efeito
}
/*
 * binParidade - retorna 1 se x contém uma número ímpar de 0's
 *   Exemplos: binParidade(5) = 0, binParidade(7) = 1
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Nível: 4
 */
int binParidade(int x) {
  return 2;
}
/* 
 * maiorPosicaoBit - retorna uma macara que marca a posição do bit 1
 *               mais significante. Se x == 0, retorna 0
 *   Exemplo: maiorPosicaoBit(96) = 0x40
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Nível: 4 
 */
int maiorPosicaoBit(int x) {
  return 2;
}
/* 
 * cabeShort - retorna 1 se x pode ser representado como um 
 *   inteiro de 16-bit, em complemento de dois.
 *   Exemplo: cabeShort(33000) = 0, cabeShort(-32768) = 1
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Nível: 1
 */
int cabeShort(int x) 
{
  //Qualquer número com bit setado acima dos 16 primeiros bits não vai caber em um short, quando negativo leva-se em consideração setado = 0, já quando positivo setado = 1
  int sinal = (x >> 31);//Espalho o bit de sinal
  x = x ^ sinal;//Caso esteja nenhum bit setado nos primeiros 16 bits o número cabe
  x = x >> 15;//Pega os primeiros 16 bits
  return !x; //Se couber vai estar tudo zero, senão qualquer número, então nego
}
/* 
 * sinal - retorna 1 se positivo, 0 se zero, e -1 se negativo
 *  Exemplo: sinal(130) = 1
 *            sinal(-23) = -1
 *  Operadores Permitidos: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Nível: 2
 */
int sinal(int x) 
{
      return ((!!x) | (x >> 31)); //Dupla negação de X para o caso de x ser positivo, se x == 0 então 0, senão 1 OR espalho o sinal caso numero negativo fica -1 OR !!x(se x diferente de zero então 1), caso positivo tudo 0(0 OR qualquer coisa = qualquer coisa)
}
/* 
 * diferente - retrona 0 se x == y, e 1 caso contrário 
 *   Exemplos: diferente(5,5) = 0, diferente(4,5) = 1
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Nível: 2
 */
int diferente(int x, int y) 
{
  return !!(x ^ y); //XOR faz virar tudo zero se forem iguais, caso contrario fica qualquer coisa, dupla negação para transformar qualquer coisa em 1 e 0 em 0
}
/* 
 * negativo - retorna 1 se x < 0, retorna 0 caso contrário 
 *   Exemplo: negativo(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Nível: 2
 */
int negativo(int x) 
{
  return (x >> 31) & 1; //Espalha o bit de sinal e AND com 1, caso negativo 1 AND 1 = 1, caso contrario 0
}
/* 
 * respot2 - Calcula x%(2^n), para 0 <= n <= 30
 *   Argumentos negativos deverão resultar em restos negativos
 *   Exemplos: respot2(15,2) = 3, respot2(-35,3) = -3
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Nível: 3
 */
int respot2(int x, int n) {
    return 2;
}
/* 
 * menor - Se x < y  então retorna 1, caso contrário retorna 0 
 *   Exemplo: menor(4,5) = 1.
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Nível: 3
 */
int menor(int x, int y) {
  return 2;
}
/* 
 * cd2ms - Converte de complemento de 2 para magnitude do sinal, 
 *   onde o MSB é o bit de sinal
 *   Você pode assumir que x > TMin
 *   Exemplo: cd2ms(-5) = 0x80000005.
 *   Operadores Permitidos: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Nível: 4
 */
int cd2ms(int x) {
  return 2;
}

/* 
 * mod_float - Retorna o equivalente em nível de bit do valor absoluto
 *   de f para o argumento f ponto flutuante.
 *   Ambos, argumento e resultado são passados como int's, mas 
 *   eles são reinterpretados como representações ao nível de bit de valores
 *   ponto flutuante de precisão simples.
 *   Quando o argumento é NaN, retorne o argumento..
 *   Operadores Permitidos: Qualquer operações de integer/unsigned incluindo. ||, &&. também if, while
 *   Max ops: 10
 *   Nível: 2
 */
unsigned mod_float(unsigned uf) {
  return 2;
}
/* 
 * meio_float - Retorna a nível de bit o equivalente da expressão 0.5*f
 *   para o argumento f ponto flutuante. Ambos, arumento resultado são
 *   passados como unsigned int's, mas eles são interpretados com a 
 *   representação ao nível de bit de um valor ponto flutuante de precisão simples
 *   Quando o argumento é NaN, retorne o argumento. 
 *   Legal ops: Qualquer operações integer/unsigned incluindo ||, &&. também if, while
 *   Max ops: 30
 *   Nível: 4
 */
unsigned meio_float(unsigned uf) {
  return 2;
}
/* 
 * floatInteiro_float - Retorna a nível de bit o equivalente da representação
 *   da expressão (int) f para o argumento f ponto flutuante.
 *   O argumento é passado como unsigned int, mas ele é interpretado com a 
 *   representação ao nível de bit de um valor ponto flutuante de precisão simples
 *   Qualquer valor fora do range (incluindo NaN e infinito) deverá retornar
 *   0x80000000u.
 *   Operadores Permitidos: Qualquer operação integer/unsigned incluindo ||, &&. também if, while
 *   Max ops: 30
 *   Nível: 4
 */
int floatInteiro_float(unsigned uf) {
  return 2;
}
