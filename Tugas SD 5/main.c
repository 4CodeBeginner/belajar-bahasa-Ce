#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main()
{
    HashMap map;
    initHashMap(&map);

    int pilihan;
    int nim;
    char nama[50];

    do
    {
        printf("\n===== MENU HASHMAP MAHASISWA =====\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data\n");
        printf("3. Hapus Data\n");
        printf("4. Tampilkan Semua Data\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {

        case 1:
            printf("\nMasukkan NIM: ");
            scanf("%d", &nim);

            printf("Masukkan Nama: ");
            scanf(" %[^\n]", nama);

            insert(&map, nim, nama);
            break;

        case 2:
            printf("\nMasukkan NIM yang dicari: ");
            scanf("%d", &nim);

            search(&map, nim);
            break;

        case 3:
            printf("\nMasukkan NIM yang akan dihapus: ");
            scanf("%d", &nim);

            deleteNode(&map, nim);
            break;

        case 4:
            printf("\nData dalam HashMap:\n");
            display(&map);
            break;

        case 5:
            printf("\nProgram selesai.\n");
            break;

        default:
            printf("\nPilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    return 0;
}