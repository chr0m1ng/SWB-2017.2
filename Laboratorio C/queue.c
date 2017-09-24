/*
 * Código para diagnostico de conhecimento básico em C.
 * Desenvolvido para o curso CET-088, CET-082
 * Modificado por Leard Fernandes, 2017
 * Developed by R. E. Bryant, 2017
*/

 /*
  * Este programa implementa uma fila que suporta ambas as operações FIFO e LILO.
  *
  * Ele utiliza uma lista unicamente ligada para representar o conjunto de
  * elementos da fila
*/

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Cria uma fila vazia.
  Retorna NULL se o espaço na puder ser alocado.
*/
queue_t *q_new()
{
  queue_t *q =  malloc(sizeof(queue_t));
  if(q == NULL)
    return NULL;
  q->head = q->tail = NULL;
  q->size = 0;
  return q;
}
/*  Libera todo o espaço utilizado pela fila. */
void q_free(queue_t *q)
{
  if(q == NULL)
    return;
  list_ele_t *next = q->head;
  list_ele_t *temp;
  while(next != NULL)
  {
    temp = next->next;
    free(next);
    next = temp;
  }

  free(q);
}

/*
  Tenta inserir o elemento na cabeça da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_head(queue_t *q, int v)
{
  if(q == NULL)
    return false;
  
  list_ele_t *newh;

  newh = malloc(sizeof(list_ele_t));
  if(newh == NULL)
    return false;

  newh->value = v;
  if(q->head == NULL)
  {
    q->head = newh;
    q->head->next = NULL;
  }
  else
  {
    newh->next = q->head;
    q->head = newh;
  }
  if(q->tail == NULL)
    q->tail = q->head;
  q->size++;
  return true;
}


/*
  Tenta inserir o elemento na calda da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_tail(queue_t *q, int v)
{
  /* Você precisa escrever o código completo para esta função */
  /* lembre-se: Você deverá operar no tempo de O(1) */

  if(q == NULL)
    return false;

  list_ele_t *newt = NULL;

  newt = malloc(sizeof(list_ele_t));
  if(newt == NULL)
    return false;
  
  newt->value = v;
  newt->next = NULL;
  if(q->tail == NULL)
    q->tail = newt;
  else
  {
    q->tail->next = newt;
    q->tail = newt;
  }
  if(q->head == NULL)
    q->head = q->tail;
  q->size++;

  return true;
}

/*
  Tenta remover o elemento na cabeça da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou vazia
  Se vp é não-NULL e o elemento removido, armazena o valor removido em *vp
  Qualquer armazenamento não utilizado deve ser liberado
*/
bool q_remove_head(queue_t *q, int *vp)
{
  if(q != NULL && q_size(q) > 0)
  {
    list_ele_t *head = q->head;
    q->head = q->head->next;

    if(vp != NULL)
      *vp = head->value;
    
    free(head);
    q->size--;

    if(!q_size(q))
      q->head = q->tail = NULL;

    return true;
  }
  else
    return false;

}

/*
  Retorna o número de elementos na fila.
  Retorna 0 se q é NULL ou vazia
*/
int q_size(queue_t *q)
{
  if(q == NULL)
    return 0;
  return q->size;
}

/*
  Inverte os elementos na fila.

  Sua implementação não dever alocar ou liberar quaisquer elementos (e.g., pela
  chamada de q_insert_head ou q_remove_head). Ao invés disso, ela deverá
  modificar os ponteiros na estrutura de dados existente.
*/
void q_reverse(queue_t *q)
{
  if(q == NULL || !q_size(q))
    return;

  list_ele_t *aux = q->head;

  while(aux != q->tail)
  {
    q->head = q->head->next;
    aux->next = q->tail->next;
    q->tail->next = aux;
    aux = q->head;
  }

  while(aux->next != NULL)
    aux = aux->next;
  q->tail = aux;
}
