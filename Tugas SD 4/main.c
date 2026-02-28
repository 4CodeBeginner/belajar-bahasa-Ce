#include <stdio.h>
#include "tree.h"

int main() {
    Tree *t = createTree();

    int pilihan;
    char parent[50], child[50], rootName[50];

    do {
        printf("\n=== STRUKTUR ORGANISASI UKM ===\n");
        printf("1. Buat Root\n");
        printf("2. Tambah Jabatan\n");
        printf("3. Tampilkan Struktur\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan Jabatan Root: ");
                scanf(" %[^\n]", rootName);
                createRoot(t, rootName);
                break;

            case 2:
                printf("Masukkan Nama Parent: ");
                scanf(" %[^\n]", parent);
                printf("Masukkan Nama Child: ");
                scanf(" %[^\n]", child);
                addChild(t, parent, child);
                break;

            case 3:
                printf("\nStruktur Organisasi:\n");
                printTree(t);
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    destroyTree(t);
    return 0;
}