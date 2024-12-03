#include "BVS.h"
#include <stdio.h>

int main()
{
    printf("\nUSaA BVS Framework\n");
    PtrBVSNode MyBVS = NULL;

    printf("\nBVSInsert 2");
    MyBVS = BVSInsert(MyBVS, 2);
    printf("\nBVSInsert 1");
    MyBVS = BVSInsert(MyBVS, 1);
    printf("\nBVSInsert 4");
    BVSInsert(MyBVS, 4);
    printf("\nBVSInsert 3");
    MyBVS = BVSInsert(MyBVS, 3);
    printf("\nBVSInsert 5");
    MyBVS = BVSInsert(MyBVS, 5);
    printf("\nBVSInsert 5");
    MyBVS = BVSInsert(MyBVS, 5);
    printf("\nBVSInsert 8");
    MyBVS = BVSInsert(MyBVS, 8);
    printf("\nBVSInsert 108");
    MyBVS = BVSInsert(MyBVS, 108);
    printf("\nBVSInsert 6");
    MyBVS = BVSInsert(MyBVS, 6);
    printf("\nBVSInsert 0");
    MyBVS = BVSInsert(MyBVS, 0);
    printf("\n");
    printf("\nBVSMember 2 (%d) ", BVSMember(MyBVS, 2));
    printf("\nBVSMember 0 (%d) ", BVSMember(MyBVS, 0));
    printf("\nBVSMember 4 (%d) ", BVSMember(MyBVS, 4));
    printf("\nBVSMember 7 (%d) ", BVSMember(MyBVS, 7));

    printf("\n\nBVSPrintInOrder: ");
    BVSPrintInOrder(MyBVS);
    printf("\nBVSPrintPreOrder: ");
    BVSPrintPreOrder(MyBVS);
    printf("\nBVSPrintPostOrder: ");
    BVSPrintPostOrder(MyBVS);
    printf("\nBVSGetMaxLevel: %d", BVSGetMaxLevel(MyBVS));
    printf("\nBVSPrintLevelOrder: ");
    BVSPrintLevelOrder(MyBVS);
    printf("\nBVSGetMinItem: %d", BVSGetMinItem(MyBVS));
    printf("\nBVSGetMaxItem: %d", BVSGetMaxItem(MyBVS));
    printf("\nBVSTreeSize: %d", BVSTreeSize(MyBVS));

    printf("\n\nBVSPrintTree: ");
    BVSPrintTree(MyBVS);
    printf("\n");

    printf("\nBVSDeleteItem 4 (%d) ", BVSDeleteItem(&MyBVS, 4));
    BVSPrintTree(MyBVS);
    printf("\n");

    printf("\nBVSDeleteItem 2 (%d) ", BVSDeleteItem(&MyBVS, 2));
    BVSPrintTree(MyBVS);
    printf("\n");

    printf("\nBVSDeleteItem 2 (%d) ", BVSDeleteItem(&MyBVS, 2));

    printf("\n\nBVSDeleteTree:");
    BVSDeleteTree(&MyBVS);
    printf("\nBVSGetMaxLevel: %d", BVSGetMaxLevel(MyBVS));
    printf("\nBVSPrintLevelOrder: ");
    BVSPrintLevelOrder(MyBVS);
    printf("\nBVSPrintTree: ");
    BVSPrintTree(MyBVS);
    printf("\n");
    return 0;
}
