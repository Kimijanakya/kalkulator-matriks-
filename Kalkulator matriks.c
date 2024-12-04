#include <stdio.h>
#define MAX 10 

void inputmatriks(int matriks[MAX][MAX], int baris, int kolom);
void tambahmatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int baris, int kolom);
void kurangmatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int baris, int kolom);
void kalimatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int baris1, int kolom1, int kolom2);
void transmatriks(int mat1[MAX][MAX], int baris, int kolom);
void outputmat(int mat[MAX][MAX], int baris, int kolom);

int main() {
    int op;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int baris1, kolom1, baris2, kolom2;
    char stop;

    printf("========================= Kalkulator Matriks =========================\n");
    printf("Masukkan jumlah (baris,kolom) matriks 1: ");
    scanf("%d,%d", &baris1, &kolom1);
    printf("Masukkan elemen matriks pertama:\n");
    inputmatriks(mat1, baris1, kolom1);

    while (1) {
        printf("\n1. Penjumlahan Matriks\n");
        printf("2. Pengurangan Matriks\n");
        printf("3. Perkalian Matriks\n");
        printf("4. Transpose Matriks\n");
        printf("Pilih operasi (1-4): ");
        scanf("%d", &op);

        if (op == 1 || op == 2) {
            printf("\nMasukkan jumlah (baris,kolom) matriks 2: ");
            scanf("%d,%d", &baris2, &kolom2);

            if (baris1 != baris2 || kolom1 != kolom2) {
                printf("Operasi tidak bisa dilanjutkan.\nBaris dan kolom matriks harus sama.\n");
                while (getchar() != '\n');
                continue;
            } else {
                printf("\nMasukkan elemen matriks kedua:\n");
                inputmatriks(mat2, baris2, kolom2);

                if (op == 1) {
                    tambahmatriks(mat1, mat2, baris1, kolom1);
                    printf("\nHasil Penjumlahan Matriks:\n");
                    outputmat(mat1, baris1, kolom1);
                } else {
                    kurangmatriks(mat1, mat2, baris1, kolom1);
                    printf("\nHasil Pengurangan Matriks:\n");
                    outputmat(mat1, baris1, kolom1);
                }
            }
        }
		else if (op == 3) {
            printf("\nMasukkan jumlah (baris,kolom) matriks 2: ");
            scanf("%d,%d", &baris2, &kolom2);
            if (kolom1 != baris2) {
                printf("\nOperasi tidak bisa dilanjutkan.\nKolom matriks 1 dan baris matriks 2 harus sama.\n");
                while (getchar() != '\n');
                continue;
            }
			else {
                printf("Masukkan elemen matriks kedua:\n");
                inputmatriks(mat2, baris2, kolom2);
                kalimatriks(mat1, mat2, result, baris1, kolom1, kolom2);
                printf("\nHasil Perkalian Matriks:\n");
                outputmat(result, baris1, kolom2);

                for (int i = 0; i < baris1; i++) {
                    for (int j = 0; j < kolom2; j++) {
                        mat1[i][j] = result[i][j];
                    }
                }
                kolom1 = kolom2;
            }  
        }
        else if (op == 4) {
		transmatriks(mat1, baris1, kolom1);
    	int temp = baris1;
    	baris1 = kolom1;
    	kolom1 = temp;
    	printf("\nHasil transpose matriks:\n");
    	outputmat(mat1, baris1, kolom1);
		}

		else {
            printf("Operasi tidak valid.\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Apakah anda ingin berhenti?\nMasukkan y bila ingin berhenti: ");
        scanf(" %c", &stop);
        if (stop == 'y' || stop == 'Y') {
        	printf("\n====================================================================");
            printf("\nTerima kasih telah menggunakan kalkulator matriks. Program berhenti.\n");
            printf("====================================================================");
			break;
        }
    }

    return 0;
}

void inputmatriks(int matriks[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriks[i][j]);
        }
    }
}

void tambahmatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void kurangmatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            mat1[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void kalimatriks(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int baris1, int kolom1, int kolom2) {
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < kolom1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void transmatriks(int mat1[MAX][MAX], int baris, int kolom) {
    int temp[MAX][MAX]; 
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            temp[j][i] = mat1[i][j]; 
        }
    }
    for (int i = 0; i < kolom; i++) { 
        for (int j = 0; j < baris; j++) { 
            mat1[i][j] = temp[i][j];
        }
    }
}

void outputmat(int mat[MAX][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

