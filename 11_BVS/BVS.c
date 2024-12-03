// USaA BVS Framework
// S.Simonak, KPI FEI TUKE, 2018-2021

#include "BVS.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct BVSNode {
    int Item;
    PtrBVSNode Left;
    PtrBVSNode Right;
};

// vytvori BVS vrchol so zadanou polozkou (0-99)
PtrBVSNode BVSCreateNode(int ItemToInsert) {
    PtrBVSNode BVS;
    BVS = malloc(sizeof(struct BVSNode));
    if (BVS == NULL) {
        printf("\nOut of memory!");
        exit(-1);
    }
    if (ItemToInsert < 0 || ItemToInsert > 99) {
        printf("\nBVSCreateNode: invalid item (0-99): %d!", ItemToInsert);
        return NULL;
    }
    BVS->Item = ItemToInsert;
    BVS->Left = NULL;
    BVS->Right = NULL;
    return BVS;
}

// vytvori strom BVS so zadanou polozkou v koreni
PtrBVSNode BVSCreateTree(int ItemToInsert) {
    return BVSCreateNode(ItemToInsert);
}

// vlozi polozku do stromu BVS
// pri vkladani do neexistujuceho stromu vrati smern�k na strom s vlozenou polozkou
PtrBVSNode BVSInsert(PtrBVSNode Root, int ItemToInsert) {
    if (Root == NULL) return BVSCreateNode(ItemToInsert);
    if (ItemToInsert < Root->Item) Root->Left = BVSInsert(Root->Left, ItemToInsert);
    else if (ItemToInsert > Root->Item) Root->Right = BVSInsert(Root->Right, ItemToInsert);
    return Root;       // item in Tree
}

// vyhlada zadanu polozku a vrati 1 - ak existuje, 0 - ak neexistuje
int BVSMember(PtrBVSNode Root, int ItemToFind) {
    if (Root == NULL) return 0;
    if (Root->Item > ItemToFind) {
        return BVSMember(Root->Left, ItemToFind);
    }
    if (Root->Item < ItemToFind) {
        return BVSMember(Root->Right, ItemToFind);
    }
    return 1;
}

void BVSPrintInOrder(PtrBVSNode Root) {
    if (Root == NULL) return;

    BVSPrintInOrder(Root->Left);
    printf("%d ", Root->Item);
    BVSPrintInOrder(Root->Right);
}

void BVSPrintPreOrder(PtrBVSNode Root) {
    if (Root == NULL) return;

    printf("%d ", Root->Item);
    BVSPrintPreOrder(Root->Left);
    BVSPrintPreOrder(Root->Right);
}

void BVSPrintPostOrder(PtrBVSNode Root) {
    if (Root == NULL) return;

    BVSPrintPostOrder(Root->Left);
    BVSPrintPostOrder(Root->Right);
    printf("%d ", Root->Item);
}

// vrati pocet prvkov v strome
int BVSTreeSize(PtrBVSNode Root) {
    if (Root == NULL) return 0;

    return BVSTreeSize(Root->Left) + BVSTreeSize(Root->Right) + 1;
}

int BVSGetLevel(PtrBVSNode Root, int Level) {
    int LMax = Level, RMax = Level;
    if (Root->Left != NULL) LMax = BVSGetLevel(Root->Left, Level + 1);
    if (Root->Right != NULL) RMax = BVSGetLevel(Root->Right, Level + 1);
    if (LMax > RMax) return LMax;
    else return RMax;
}

// vrati vysku stromu, vyuziva funkciu BVSGetLevel()
int BVSGetMaxLevel(PtrBVSNode Root) {
    if (Root == NULL) return 0;
    else return BVSGetLevel(Root, 1);
}

void BVSPrintLevel(PtrBVSNode Root, int LevelToPrint, int StartLevel) {
    if (Root == NULL) return;
    if (LevelToPrint == StartLevel) printf("%d ", Root->Item);
    if (Root->Left != NULL) BVSPrintLevel(Root->Left, LevelToPrint, StartLevel + 1);
    if (Root->Right != NULL) BVSPrintLevel(Root->Right, LevelToPrint, StartLevel + 1);
}

// vypise prvky stromu strategiou Level order, vyuziva proceduru BVSPrintLevel()
void BVSPrintLevelOrder(PtrBVSNode Root) {
    if (Root == NULL) return;
    int i, MaxLevel = BVSGetMaxLevel(Root);
    for (i = 1; i <= MaxLevel; i++)
        BVSPrintLevel(Root, i, 1);
}

int BVSGetMinItem(PtrBVSNode Root) {
    if (Root == NULL) {
        printf("\nNo Tree!");
        exit(-1);
    }
    if (Root->Left == NULL) return Root->Item;
    else return BVSGetMinItem(Root->Left);
}

int BVSGetMaxItem(PtrBVSNode Root) {
    if (Root == NULL) {
        printf("\nNo Tree!");
        exit(-1);
    }
    if (Root->Right == NULL) return Root->Item;
    else return BVSGetMaxItem(Root->Right);
}

// vymaze a uvolmi z pamati strom, parametrom je smernik na smernik, aby bolo mozne zmazat koren
void BVSDeleteTree(PtrBVSNode *PtrRoot) {
    PtrBVSNode Root = (PtrBVSNode) *PtrRoot;
    if (Root == NULL) return;
    if (Root->Left != NULL) BVSDeleteTree(&Root->Left);
    if (Root->Right != NULL) BVSDeleteTree(&Root->Right);
    printf(" deleting %d", Root->Item);
    free(Root);
    *PtrRoot = NULL;
    return;
}

// odstrani zadany prvok zo stromu, ak sa v nom nachadza
// ako parameter prijima smernik na smernik (koren stromu) a polozku na odstranenie
// navratova hodnota: 1 - polozka odstranena, 0 - polozka neodstranena
int BVSDeleteItem(PtrBVSNode *PtrRoot, int ItemToDelete) {
    PtrBVSNode Root = (PtrBVSNode) *PtrRoot;
    if (Root == NULL) return 0;
    if (ItemToDelete < Root->Item) return BVSDeleteItem(&Root->Left, ItemToDelete);
    if (ItemToDelete > Root->Item) return BVSDeleteItem(&Root->Right, ItemToDelete);
    if (Root->Left == NULL && Root->Right == NULL) {      // prvok je listom
        free(Root);
        *PtrRoot = NULL;
        return 1;
    }
    if (Root->Left == NULL) {         // nema L-podstrom
        *PtrRoot = Root->Right;
        free(Root);
        return 1;
    }
    if (Root->Right == NULL) {        // nema P-podstrom
        *PtrRoot = Root->Left;
        free(Root);
        return 1;
    }
    // odstranovany vrchol ma obidvoch potomkov, substitucia minimalnym prvkom P-podstromu
    Root->Item = BVSGetMinItem(Root->Right);
    return BVSDeleteItem(&Root->Right, Root->Item);
}

void BVSFillArrLevel(PtrBVSNode Root, int ArrWidth, int Arr[ArrWidth], int LevelToFill, int StartLevel, int Left,
                     int Right) {
    if (Root == NULL) return;
    if (LevelToFill == StartLevel) Arr[ArrWidth / 2 - Left + Right] = Root->Item;
    if (Root->Left != NULL)
        BVSFillArrLevel(Root->Left, ArrWidth, Arr, LevelToFill, StartLevel + 1,
                        Left + ArrWidth / pow(2, StartLevel + 1), Right);
    if (Root->Right != NULL)
        BVSFillArrLevel(Root->Right, ArrWidth, Arr, LevelToFill, StartLevel + 1, Left,
                        Right + ArrWidth / pow(2, StartLevel + 1));
}

void BVSPrintArrLevel(PtrBVSNode Root, int ArrWidth, int Arr[ArrWidth]) {
    int i;
    char form[4] = "%d", spc[3] = " ";
    if (BVSGetMaxItem(Root) > 9) {
        strcpy(form, "%2d");
        strcpy(spc, "  ");
    }
    for (i = 1; i < ArrWidth; i++)
        if (Arr[i] != -1) printf(form, Arr[i]);
        else printf("%s", spc);
}

void BVSClearArray(int ArrWidth, int Arr[ArrWidth]) {
    int i;
    for (i = 0; i < ArrWidth; i++)
        Arr[i] = -1;
}

// vypise polozky stromu v tvare stromu
void BVSPrintTree(PtrBVSNode Root) {
    if (Root == NULL) return;
    int i, MaxLevel = BVSGetMaxLevel(Root);
    int ArrWidth = pow(2, MaxLevel);
    int Arr[ArrWidth];
    printf("\n");
    for (i = 1; i <= MaxLevel; i++) {
        BVSClearArray(ArrWidth, Arr);
        BVSFillArrLevel(Root, ArrWidth, Arr, i, 1, 0, 0);
        BVSPrintArrLevel(Root, ArrWidth, Arr);
        if (i != MaxLevel) printf("\n");
    }
}
