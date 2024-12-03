#ifndef BVS_H_INCLUDED
#define BVS_H_INCLUDED

typedef struct BVSNode *PtrBVSNode;

PtrBVSNode BVSCreateNode(int ItemToInsert);
PtrBVSNode BVSCreateTree(int ItemToInsert);
PtrBVSNode BVSInsert(PtrBVSNode Root, int ItemToInsert);
int BVSMember(PtrBVSNode Root, int ItemToFind);
void BVSPrintInOrder(PtrBVSNode Root);
void BVSPrintPreOrder(PtrBVSNode Root);
void BVSPrintPostOrder(PtrBVSNode Root);
int BVSGetMaxLevel(PtrBVSNode Root);
void BVSPrintLevelOrder(PtrBVSNode Root);
int BVSGetMinItem(PtrBVSNode Root);
int BVSGetMaxItem(PtrBVSNode Root);
void BVSDeleteTree(PtrBVSNode* PtrRoot);
int BVSDeleteItem(PtrBVSNode* PtrRoot, int ItemToDelete);
void BVSPrintTree(PtrBVSNode Root);
int BVSTreeSize(PtrBVSNode Root);

void MyPrintf(const char *format, ...);

#endif // BVS_H_INCLUDED
