#include "linked_list.h"

int main() {
  struct linkedListNode * root = malloc(sizeof(struct linkedListNode));
  root->value = 0;
  root->next = NULL;

  for(int i = 1; i < 15; i++) {
    linkedListAdd(root, i);
  }

  linkedListPrint(root);

  int index = 14;
  int value = linkedListValueOf(root, index);
  printf("Index %d: value %d\n", index, value);

  value = 14;
  index = linkedListIndexOf(root, value);
  printf("Value %d: index %d\n", value, index);

  index = 10;
  struct linkedListNode * removedNode = linkedListRemoveAt(root, index);
  free(removedNode);
  removedNode = NULL;
  index = 5;
  removedNode = linkedListRemoveAt(root, index);
  free(removedNode);
  removedNode = NULL;

  index = 5;
  value = 100;
  linkedListInsert(root, value, index);

  index = 14;
  value = 25;
  linkedListInsert(root, value, index);

  index = 0;
  value = 30;
  linkedListInsert(root, value, index);

  index = 0;
  removedNode = linkedListRemoveAt(root, index);
  free(removedNode);

  index = 0;
  removedNode = linkedListRemoveAt(root, index);
  free(removedNode);
  
  linkedListPrint(root);

  linkedListDispose(root);
  
  return 0;
}
