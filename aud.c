#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Create_data_file
void create_data_file(int count, char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error : cannot create file\n");
        return;
    }

    srand(time(NULL));
    
    printf("Creating data file and saving data to the file %s:\n", filename); 
    for (int i = 0; i < count; i++) {
        int randomNumber = rand() % 1000;
        fprintf(file, "%d\n", randomNumber);
    }

    printf("\nFile saved!\n\n");

    fclose(file);
    
} //read_numbers_to_array
int* read_numbers_to_array(char *filename, int *output_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error : file not found %s\n", filename);
        *output_size = 0;
        return NULL;
}

int count = 0;
int temp;
while (fscanf(file, "%d", &temp) == 1) {
    count++;
}
*output_size = count;

if (count == 0) {
    fclose(file);
    return NULL;
}

rewind(file);
int *array = (int *)malloc(count * sizeof(int));
if (array == NULL) {
    printf("Error : Cannot create array\n");
    fclose(file);
    return NULL;
}

for (int i = 0; i < count; i++) {
    fscanf(file, "%d", &array[i]);
}
    fclose(file);
    return array;
}

    //show_array
void show_array(int *array, int size)
{
    printf("\n|");

    for (int i = 0; i < size; i++) {
        printf(" %d |", array[i]);
    }
    printf("\n");
}

//selection_sort
int* selection_sort(int *x, int size) {
    int i, j, k, c;

    for(i = 0; i <size; i++) {
        k = i;
        for(j = i + 1; j < size; j++) {
            if(x[j] < x[k]) {
                k = j;
            }
        }

        if(i != k) {
            c = x[k];
            x[k] = x[i];
            x[i] = c;
        }

        printf("==== ROUND %d, INDEX %d ====\n", i + 1, i);
        show_array(x, size);
    }
    

return x;
}

//bubble_sort
int* bubble_sort(int *x, int size) {
    int flag = 1, pass = 1;
    int j, temp;

    show_array(x, size);

    while((pass <= size -1) && flag == 1) {
        printf("\npass=%d, flag=%d", pass, flag);

        flag = 0;
        for( j = size -1; j >=pass +1; j--) {
            printf("\nx[j] = %d, x[j - 1] = %d, x[j], x[j - 1]");

            if (x[j] <x[j-1]) {
                printf(", SWAP");
                temp = x[j];
                x[j] = x[j - 1];
                x[j -1] = temp;
                flag = 1;
            }
        }
        pass +=1;

        show_array(x, size);
    }
}

int main ()
{
    int number_to_create;
    int size = 0;
    char *filename = "random_numbersm.txt";

    //Create data file
    //number_to_create = 20;
    //create_data_file(number_to_create, filename);

     //Read data to array
    int *myDynamicArray = read_numbers_to_array(filename, &size);
    //printf("\n\nSize : %d\n", size);
    //for (int i  = 0; i < size; i++)
       // printf("index[%d] = %d\n", i, myDynamicArray[i]);

    //selection_sort(myDynamicArray, size);
     bubble_sort(myDynamicArray, size);


    free(myDynamicArray);
    myDynamicArray = NULL;
    return 0;
}
