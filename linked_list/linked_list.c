#include "linked_list.h"

struct linkedListNode * linkedListAdd(struct linkedListNode * root, int value) {
  struct linkedListNode * tmp = root;
  while(tmp->next != NULL) {
    tmp = tmp->next;
  }
  struct linkedListNode * new = malloc(sizeof(struct linkedListNode));
  new->value = value;
  new->next = NULL;
  tmp->next = new;

  return new;
};

int linkedListValueOf(struct linkedListNode * root, int index) {
  int currIndex = 0;
  struct linkedListNode * tmp = root;
  while(tmp != NULL) {
    if (currIndex == index)
      return tmp->value;
    tmp = tmp->next;
    currIndex++;
  }
  
  return -1;
};

int linkedListIndexOf(struct linkedListNode * root, int value) {
  int currIndex = 0;
  struct linkedListNode * tmp = root;
  while(tmp != NULL) {
    if (tmp->value == value)
      return currIndex;
    tmp = tmp->next;
    currIndex++;
  }
  
  return -1;
};

int linkedListPrint(struct linkedListNode * root) {
  struct linkedListNode * tmp = root;
  while(tmp != NULL) {
    printf("%d\n", tmp->value);
    tmp = tmp->next;
  }

  return 0;
}

struct linkedListNode * linkedListRemoveAt(struct linkedListNode * root, int index) {
  if (index == 0) {
    struct linkedListNode * next = root->next;
    root->value = next->value;
    root->next = next->next;

    return next;
  }
  
  int currIndex = 0;
  struct linkedListNode * tmp = root;
  while(tmp != NULL) {
    if (++currIndex == index) {
      struct linkedListNode * toRemove = tmp->next;
      struct linkedListNode * next = toRemove->next;

      toRemove->next = NULL;
      tmp->next = next;

      return toRemove;
    }
    tmp = tmp->next;
  }

  return NULL;
}

int linkedListDispose(struct linkedListNode * root) {
  struct linkedListNode * tmp = root;
  struct linkedListNode * next = tmp;
  while(next != NULL) {
    tmp = next;
    next = tmp->next;
    free(tmp);
    tmp = NULL;
  }
  
  return 0;
}

int linkedListInsert(struct linkedListNode * root, int value, int index) {
  if (index == 0) {
    struct linkedListNode * new = malloc(sizeof(struct linkedListNode));
    new->value = root->value;
    new->next = root->next;
    root->value = value;
    root->next =  new;

    return 0;
  }

  int currIndex = 0;
  struct linkedListNode * tmp = root;

  while(tmp != NULL) {
    if (++currIndex == index) {
      struct linkedListNode * new = malloc(sizeof(struct linkedListNode));
      new->value = value;
      new->next = tmp->next;
      tmp->next = new;

      return 0;
    }
    tmp = tmp->next;
  }
  
  return -1;
}
