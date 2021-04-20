#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int init();
void bubble_sort_asc();
void bubble_sort_desc();
void selection_sort_asc();
void selection_sort_desc();
void insertion_sort_asc();
void insertion_sort_desc();
void print_array();
void swap();

int main()
{
    char input[50];

    char mode[50];
    char parameter[50];

    char nama_file[50];

    int arr[20];
    int n_arr;
    //char n[3];
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
        fflush(stdin);
        scanf("%[^\n]s",input);
        //potong input sampai ( untuk mementukan mode program
        //printf("%s",input);
        char * token = strtok(input,"(");
        strcpy(mode,token);
        //hasil output mode : init/sort/search/dll
        //printf("mode = %s \n\n\n",mode);
        token = strtok(NULL,")");
        strcpy(parameter,token);
        // dan ambil string dalam tanda ( ), copy ke paramter
        //printf("%s\n",parameter);
        //contoh hasil paramter 10,p

        if(strcmp(mode,"init")==0){
            //fungsi init
            //printf("init mode\n");

            char * input_n = strtok(parameter,",");
            char * metode = strtok(NULL,"\n");
            int n = atoi(input_n);
            printf("n = %d\n",n);
            printf("metode = %s\n",metode);

            n_arr = n;
            

            init(n_arr, metode, arr);
        }
        else if(strcmp(mode,"sort")==0){
            //fungsi sort
            printf("sort mode\n");
            char * parameter_array = strtok(parameter,",");
            char * mode_sorting = strtok(NULL,",");
            char * metode_sorting = strtok(NULL,"\n");

            int metode_sorting_int = atoi(metode_sorting);

            printf("parameter = %s\n",parameter_array);
            printf("mode sorting = %s\n",mode_sorting);
            printf("metode sorting = %s\n",metode_sorting);


            if(metode_sorting_int==1){
                //bubble sort
                if(strcmp(mode_sorting,"asc")==0){
                    //bubble sort asc
                    bubble_sort_asc(arr,n_arr);
                    print_array(arr,n_arr);

                }
                else{
                    //bubbe sort desc
                    bubble_sort_desc(arr,n_arr);
                    print_array(arr,n_arr);

                }
            }
            else if(metode_sorting_int==2){
                    //selection sort
                if(strcmp(mode_sorting,"asc")==0){
                    //selection sort asc
                    selection_sort_asc(arr,n_arr);
                    print_array(arr,n_arr);

                }
                else{
                    //selection sort desc
                    selection_sort_desc(arr,n_arr);
                    print_array(arr,n_arr);


                }
            }
            else{
                //insertion sort
                if(strcmp(mode_sorting,"asc")==0){
                    //insertion sort asc
                    insertion_sort_asc(arr,n_arr);
                    print_array(arr,n_arr);


                }
                else{
                    //insertion sort desc
                    insertion_sort_desc(arr,n_arr);
                    print_array(arr,n_arr);

                }
            }

        }
        else if(strcmp(mode,"search")==0){
            //fungsi search
            printf("search mode\n");
            char * n_search = strtok(parameter,",");
            char * parameter_array = strtok(NULL,",");
            char * mode_urut = strtok(NULL,"\n");

            printf("n_search = %s\n",n_search);
            printf("parameter_array = %s\n",parameter_array);
            printf("mode_urut = %s\n",mode_urut);


        }
        else if(strcmp(mode,"insert")==0){
            //fungsi insert
            printf("insert mode\n");
            char * n_insert = strtok(parameter,",");
            char * mode_urut = strtok(NULL,"\n");

            printf("n_insert = %s\n",n_insert);
            printf("mode_urut = %s\n",mode_urut);

        }
        else if(strcmp(mode,"update")==0){
            //fungsi update
            printf("update mode\n");
            char * n_update = strtok(parameter,",");
            char * m_update = strtok(NULL,",");
            char * metode_urut = strtok(NULL,"\n");

            printf("n_update = %s\n",n_update);
            printf("m_update = %s\n",m_update);
            printf("metode_urut = %s\n",metode_urut);
        }
        else if(strcmp(mode,"delete")==0){
            //fungsi delete
            printf("delete mode\n");
            char * n_delete = strtok(parameter,",");
            char * mode_urut = strtok(NULL,"\n");

            printf("n_delete = %s\n",n_delete);
            printf("mode_urut = %s\n",mode_urut);

        }
        else if(strcmp(mode,"count")==0){
            //fungsi count
            printf("count mode\n");

        }
        else if(strcmp(mode,"min")==0){
                //fungsi min
            printf("min mode\n");
        }
        else if(strcmp(mode,"max")==0){
                //fungsi max
            printf("max mode\n");
        }
        else if(strcmp(mode,"average")==0){
                //fungsi average
            printf("average mode\n");
        }
        else if(strcmp(mode,"ganjil")==0){
                //fungsi ganjil
            printf("ganjil mode\n");
        }
        else if(strcmp(mode,"genap")==0){
                //fungsi genap
            printf("genap mode\n");
        }
        else if(strcmp(mode,"exit")==0){
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

int init(int inputSignedArray, char *NorP, int arrayInit[]){
    int a = 0, random, sqrtRandom;
    srand(time(0));
    if (strcmp(NorP, "n")==0){

        while(a < inputSignedArray){
            random = rand();
            srand(random);
            arrayInit[a] = random;
            a++;
        }
    }
    else if (strcmp(NorP, "p")==0){
        while(a < inputSignedArray){
            random = rand();
            srand(random);
            if (isPrime(random)){
                arrayInit[a] = random;
                a++;
            }
        }
    }
    //puts("Output:");
    for ( int i = 0; i < inputSignedArray; i++)
        printf("[%d]", arrayInit[i]);
    for (int j = 0; j < 20 - inputSignedArray; j++)
        printf("[]");
    // return arrayInit
}

void bubble_sort_asc(int *input_array, int panjang_array){

    int i,j;
    for(i =0 ; i< panjang_array ; i++){
        for (j=0 ; j< panjang_array - i - 1; j++){
            if(input_array[j] > input_array[j+1]){
                swap(&input_array[j],&input_array[j+1]);
            }
        }
    }
}


void bubble_sort_desc(int *input_array, int panjang_array){

    int i,j;
    for(i =0 ; i< panjang_array ; i++){
        for (j=0 ; j< panjang_array - i - 1; j++){
            if(input_array[j] < input_array[j+1]){
                swap(&input_array[j],&input_array[j+1]);
            }
        }
    }
}

void selection_sort_asc(int *input_array, int panjang_array){
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < panjang_array-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < panjang_array; j++)
        if (input_array[j] < input_array[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&input_array[min_idx], &input_array[i]);
    }

}

void selection_sort_desc(int *input_array, int panjang_array){
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < panjang_array-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < panjang_array; j++)
        if (input_array[j] > input_array[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&input_array[min_idx], &input_array[i]);
    }

}

void insertion_sort_asc(int *input_array, int panjang_array){
    int i, key, j;
    for (i = 1; i < panjang_array; i++)
    {
        key = input_array[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && input_array[j] > key)
        {
            input_array[j + 1] = input_array[j];
            j = j - 1;
        }
        input_array[j + 1] = key;
    }
}
void insertion_sort_desc(int *input_array, int panjang_array){
    int i, key, j;
    for (i = 1; i < panjang_array; i++)
    {
        key = input_array[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && input_array[j] < key)
        {
            input_array[j + 1] = input_array[j];
            j = j - 1;
        }
        input_array[j + 1] = key;
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *input_array,int panjang_array){
for ( int i = 0; i < panjang_array; i++)
        printf("[%d]", input_array[i]);
    for (int j = 0; j < 20 - panjang_array; j++)
        printf("[]");
}
