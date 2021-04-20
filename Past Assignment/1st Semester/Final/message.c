#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50];
    char mode[50];
    char parameter[50];
    for(;;)
    {
        printf("\n1.init(n,metode)\n");
        printf("\n2.sort(array,pul_urut,pilihan_sorting)\n");
        printf("\n3.Search(n,array,pil_urut)\n");
        printf("\n4.insert(n,pil_urut)\n");
        printf("\n5.update(n,m,pil_urut)\n");
        printf("\n6.delete(n,pil_urut)\n");
        printf("\n7.count(array)\n");
        printf("\n8.min(array)\n");
        printf("\n9.max(array)\n");
        printf("\n10.average(array)\n");
        printf("\n11.ganjil(array)\n");
        printf("\n12.genap(array)\n");
        printf("\n13.exit\n\n");
        printf("Input : ");
        // fflush(stdin);
        scanf("%[^\n]s",input);

        char * token = strtok(input,"(");
        strcpy(mode,token);
        //printf("%s\n",mode);

        token = strtok(NULL,")");
        strcpy(parameter,token);
        //printf("%s\n",parameter);

        if(strcmp(mode,"init\n")){
            printf("init mode\n");
            char NorP;
            int inputAssignedArray, array[20], pilihan_sorting, pil_urut;

            do{
            printf ("input:init(");scanf ("%d, %c", &inputAssignedArray, &NorP);
            getchar();
            } while (!(inputAssignedArray > 0 && (NorP == 'n'|| NorP == 'p')));
    
            init(inputAssignedArray, NorP, array);
        }
        else if(strcmp(mode,"sort\n")){
            printf("sort mode\n");
        }
        else if(strcmp(mode,"exit\n")){
            exit(0);
        }
        else{
            printf("pilihan salah\n");
        }
    }


    return 0;
}

int isPrime(int randomNum){
    int sqrtRandom = sqrt(randomNum);
    if (randomNum == 2 || randomNum == 3){
        return 1;
    }
    else if (randomNum == 0 || randomNum == 1){
        return 0;
    }
    else{
        for (int randomNumDivider = 2; randomNumDivider <= sqrtRandom; randomNumDivider++){
            if (randomNum % randomNumDivider == 0){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void init(int inputSignedArray, int NorP, int* arrayInit){
    int a = 0, random, sqrtRandom;
    srand(time(0));
    if (NorP=='n'){
        while(a < inputSignedArray){
            random = rand();
            srand(random);
            arrayInit[a] = random;
            a++;
        }
    }
    else if (NorP == 'p'){
        while(a < inputSignedArray){
            random = rand();
            srand(random);
            if (isPrime(random)){
                arrayInit[a] = random;
                a++;
            }
        }
    }
    puts("Output:");
    for ( int i = 0; i < inputSignedArray; i++)
        printf("[%d]", arrayInit[i]);
    for (int j = 0; j < 20 - inputSignedArray; j++)
        printf("[]");
    // return arrayInit
}
