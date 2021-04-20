// Albertus Ivan Suryawan
// NIM. 2008561093

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int MAX_SIZE = 10;

int main() {
    // Inisialisasi variable
    int len;
    int isDirected = 0;

    printf("masukkan ukuran matrix: ");
    scanf("%d", &len);

    int graph[len][len];
    int degree[len];
    
    // Input Graph dalam bentuk matrix ordo NxN
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            if (i!=j) {
                int temp = 0;
                printf("Masukkan 1 bila vertex %d dan %d berhubungan: ", i, j);
                scanf("%d", &(graph[i][j]));
            } else {
                graph[i][j] = 0;
            }
        }
    }

    // Menampilkan representasi graph yang telah diterima dalam bentuk Matrix
    printf("\nGraph: \n");
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Memeriksa apakah graph berarah atau tidak dengan
    // menggunakan pendekatan bruteforce, dan keluar dari loop
    // bila (1) semua elemen dalam matrix simetris atau 
    // ada nilai elemen dalam matrix yang tidak simetris
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            if (graph[i][j] != graph[j][i]) {
                isDirected = 1;
                break;
            }
        }
        if (isDirected) break;
    }
    printf("Graph ini %s\n", (isDirected ? "Berarah" : "Tidak berarah"));

    // Menghitung derajat masing-masing vertex berdasarkan
    // sifat graph (Berarah atau Tidak Berarah)
    if (isDirected) {

        for (int i=0; i<len; i++) {
            int inset = 0;
            int outset = 0;
            for (int j=0; j<len; j++) outset += graph[i][j];
            for (int j=0; j<len; j++) inset += graph[j][i];

            printf("[%d] Keluar: %d Masuk: %d\n", i, outset, inset);
        }
    } else {
        printf("Derajat Masing-Masing Vertex: \n");
        for (int i=0; i<len; i++) {
            degree[i] = 0;
            for (int j=0; j<len; j++) {
                degree[i] += graph[i][j];
            }
            printf("[%d] Derajat = %d\n", i, degree[i]);
        }
    }
    
}