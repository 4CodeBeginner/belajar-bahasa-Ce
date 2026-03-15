#include <stdio.h>
#include "tries.h"

int main()
{
    TrieNode *root = createNode();
    int pilihan;
    char kata[100];

    printf("====================================\n");
    printf(" PROGRAM PEMBELAJARAN STRUKTUR TRIE\n");
    printf("====================================\n");

    do
    {
        printf("\nMenu:\n");
        printf("1. Masukkan kata ke Trie\n");
        printf("2. Cari kata di Trie\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:

            printf("Masukkan kata (huruf kecil): ");
            scanf("%s", kata);

            insertWord(root, kata);
            break;

        case 2:

            printf("Masukkan kata yang ingin dicari: ");
            scanf("%s", kata);

            if (searchWord(root, kata))
                printf("KESIMPULAN: Kata ada di dalam Trie\n");
            else
                printf("KESIMPULAN: Kata tidak ada di Trie\n");

            break;

        case 3:
            printf("Program selesai\n");
            break;

        default:
            printf("Pilihan tidak valid\n");
        }

    } while (pilihan != 3);

    return 0;
}