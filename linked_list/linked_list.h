#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct linkedListNode {
  int value;
  struct linkedListNode *next;
};

struct linkedListNode * linkedListAdd(struct linkedListNode * root, int value);
int linkedListValueOf(struct linkedListNode * root, int value);
int linkedListIndexOf(struct linkedListNode * root, int value);
int linkedListPrint(struct linkedListNode * root);
struct linkedListNode * linkedListRemoveAt(struct linkedListNode * root, int index);
int linkedListDispose(struct linkedListNode * root);
int linkedListInsert(struct linkedListNode * root, int value, int index);

