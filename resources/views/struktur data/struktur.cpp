#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

typedef struct {
    char npm[20];
    char nama[100];
    char tempat_lahir[100];
    char tanggal_lahir[20];
    char prodi[100];
} Mahasiswa;

Mahasiswa mahasiswa_list[MAX_MAHASISWA];
int jumlah_mahasiswa = 0;

// Fungsi untuk Menambahkan Data Mahasiswa (Create)
void tambah_mahasiswa(const char *nama, const char *npm, const char *tempat_lahir, const char *tanggal_lahir, const char *prodi) {
    if (jumlah_mahasiswa < MAX_MAHASISWA) {
        Mahasiswa mhs;
        strcpy(mhs.npm, npm);
        strcpy(mhs.nama, nama);
        strcpy(mhs.tempat_lahir, tempat_lahir);
        strcpy(mhs.tanggal_lahir, tanggal_lahir);
        strcpy(mhs.prodi, prodi);
        
        mahasiswa_list[jumlah_mahasiswa++] = mhs;
        printf("Mahasiswa %s berhasil ditambahkan.\n", nama);
    } else {
        printf("Kapasitas maksimum mahasiswa telah tercapai.\n");
    }
}

// Fungsi untuk Menampilkan Data Mahasiswa (Read)
void tampilkan_mahasiswa() {
    if (jumlah_mahasiswa == 0) {
        printf("Tidak ada data mahasiswa.\n");
    } else {
        for (int i = 0; i < jumlah_mahasiswa; i++) {
            printf("%d. Nama: %s, NPM: %s, Tempat Lahir: %s, Tanggal Lahir: %s, Prodi: %s\n",
                   i + 1, mahasiswa_list[i].nama, mahasiswa_list[i].npm,
                   mahasiswa_list[i].tempat_lahir, mahasiswa_list[i].tanggal_lahir,
                   mahasiswa_list[i].prodi);
        }
    }
}

// Fungsi untuk Mengubah Data Mahasiswa (Update)
void ubah_mahasiswa(int index, const char *nama, const char *npm, const char *tempat_lahir, const char *tanggal_lahir, const char *prodi) {
    if (index < 0 || index >= jumlah_mahasiswa) {
        printf("Indeks mahasiswa tidak valid.\n");
        return;
    }

    if (npm != NULL) strcpy(mahasiswa_list[index].npm, npm);
    if (nama != NULL) strcpy(mahasiswa_list[index].nama, nama);
    if (tempat_lahir != NULL) strcpy(mahasiswa_list[index].tempat_lahir, tempat_lahir);
    if (tanggal_lahir != NULL) strcpy(mahasiswa_list[index].tanggal_lahir, tanggal_lahir);
    if (prodi != NULL) strcpy(mahasiswa_list[index].prodi, prodi);

    printf("Data mahasiswa pada indeks %d berhasil diubah.\n", index + 1);
}

// Fungsi untuk Menghapus Data Mahasiswa (Delete)
void hapus_mahasiswa(int index) {
    if (index < 0 || index >= jumlah_mahasiswa) {
        printf("Indeks mahasiswa tidak valid.\n");
        return;
    }

    for (int i = index; i < jumlah_mahasiswa - 1; i++) {
        mahasiswa_list[i] = mahasiswa_list[i + 1];
    }
    jumlah_mahasiswa--;
    printf("Mahasiswa pada indeks %d berhasil dihapus.\n", index + 1);
}

// Fungsi utama untuk menjalankan program
int main() {
    tambah_mahasiswa("Agus", "062028999", "Palembang", "2001-03-04", "Sistem Informasi");
    tambah_mahasiswa("Yeni", "036986548", "Bandung", "2000-10-12", "Teknik Informatika");

    printf("\nDaftar Mahasiswa:\n");
    tampilkan_mahasiswa();

    printf("\nMengubah data mahasiswa pertama:\n");
    ubah_mahasiswa(0, "Agustian", NULL, "Kalimantan", NULL, NULL);

    printf("\nDaftar Mahasiswa setelah diubah:\n");
    tampilkan_mahasiswa();

    printf("\nMenghapus mahasiswa kedua:\n");
    hapus_mahasiswa(1);

    printf("\nDaftar Mahasiswa setelah dihapus:\n");
    tampilkan_mahasiswa();

    return 0;
}
