#include<stdio.h>
#include<string.h>

int vertex[10][10];
int i,j,n;
char jenis_graf[10];
int jml_terhubung=0;

void input(){
	printf("masukan jumlah vertex : ");
	scanf("%i",&n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("vertex[%i][%i]: ",i,j);
			scanf("%i",&vertex[i][j]);
		}
	}
}

void terhubung(){
	printf("menu 2\n");
	int terhubung = 1;
	int vertex_terhubung[10];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(vertex[i][j]==1){
				terhubung = 1;
				break;
			}
			else{
				terhubung = 0;
			}
		}
		if(terhubung == 1){
			vertex_terhubung[i]= i; 
			jml_terhubung = jml_terhubung+1;
		}
	}
	printf("vertex terhubung\n");
	for(i=i;i<=n;i++){
		printf("%i\n",vertex_terhubung[i]);
	}
}
void tipegraf(){
	int berarah;
	int transpose[10][10];
	//matriks transpose
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			transpose[i][j]=vertex[j][i];
		}
	}
	//membandingkan dengan tranpose
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(vertex[i][i]==transpose[i][j]){
				berarah = 0;
			}
			else{
				berarah = 1;
				break;
			}
		}
	}
	if(berarah == 1){
		strcpy(jenis_graf,"berarah");
		printf("Graf tersebut adalah Graf berarah\n");
	}
	else{
		strcpy(jenis_graf,"noberarah");
		printf("Graf tersebut adalah Graf tidak berarah\n");
	}
}
void derajat(){
	int derajat[10],derajat_masuk[10];
	if(strcmp(jenis_graf,"berarah")==0){
		for(i=1;i<=n;i++){
			derajat[i]=0;
			derajat_masuk[i]=0;
			for(j=1;j<=n;j++){
				//derajat keluar
				if(vertex[i][j]==1){
					derajat[i] = derajat[i]+1;
				}
				if(vertex[j][i]==1){
					derajat_masuk[i]=derajat_masuk[i]+1;
				}
			}
		}
	}
	else{
		for(i=1;i<=n;i++){
			derajat[i]=0;
			for(j=1;j<=n;j++){
				if(vertex[i][j]==1){
					derajat[i] = derajat[i]+1;
				}
			}
		}
	}
	printf("\nderajat\n");
	for(i=1;i<=n;i++){
		printf("vertex %i = %i\n",i,derajat[i]);
	}
}
void lintasan(){
	int ada;
	int next;
	int lintasan[10];
	
	next = 1;
	lintasan[next] = 1;
	do{
		for(j=1;j<=n;j++){
			if(vertex[lintasan[next]][j] == 1){
				for(i=1;i<=next;i++){
					if(lintasan[i]==j){
						ada = 1;
						break;
					}
					else{
						ada = 0;
					}
				}
				if(ada == 0){
					next++;
					lintasan[next] = j;
				}
			}
		}
	}while(next!=jml_terhubung);
	
	printf("\nlintasa\n");
	for(i=1;i<6;i++){
		printf("%i\n",lintasan[i]);
	}
	
}

int main(){
	int menu;
	
	do{
		printf("========menu===========\n");
		printf("|1. INPUT              |\n");
		printf("|2. CEK TERHUBUNG      |\n");
		printf("|3. CEK JENIS GRAF     |\n");
		printf("|4. MENGHITUNG DERAJAT |\n");
		printf("|5. MENCARI LINTASAN   |\n");
		printf("|6. KELUAR             |\n");
		printf("=======================\n");
		printf("pilih menu : ");
		scanf("%i",&menu);
		switch(menu){
			case 1:
				input();
				break;
			case 2:
				terhubung();
				break;
			case 3:
				tipegraf();
				break;
			case 4:
				derajat();
				break;
			case 5:
				lintasan();
				break;
		}
	}while(menu != 6);
	printf("Terimakasih Telah Menggunakan Program Kami\n");
	return 0;
}
