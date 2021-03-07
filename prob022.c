#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int getvalue(char *string);
long read_input(char **);
void sort(char **, int, int);
// void partition(char **, int, int, int *, int *);
int partition(char **, int, int);

long read_input(char **bufptr) {
    FILE *file = fopen("p022_names.txt", "r");
    if (!file) {
        fprintf(stderr, "file not found\n");
        exit(1);
    }
    // https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
    fseek(file, 0, SEEK_END); // seek to end of file
    long size = ftell(file)+1; // get current file pointer
    fseek(file, 0, SEEK_SET); // seek back to beginning of file

    *bufptr = malloc((unsigned long)size * sizeof(char));

    fgets(*bufptr, (int)size, file);
    return size;
}

static inline void swap(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// void sort(char **arr, int lo, int hi) {
//     if (lo < hi) {
//         swap(arr, (lo + hi) / 2, hi);
//         int left = lo;
//         int right = lo;
//         partition(arr, lo, hi, &left, &right);
//         sort(arr, lo, left - 1);
//         sort(arr, right, hi);
//     }
// }

void sort(char **arr, int lo, int hi) {
    if (lo < hi) {
        swap(arr, (lo + hi) / 2, hi);
        int p = partition(arr, lo, hi);
        sort(arr, lo, p - 1);
        sort(arr, p + 1, hi);
    }
}

int partition(char **arr, int lo, int hi) {
    char *pivot = arr[hi];
    int i = lo;
    for (int j = lo; j <= hi; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, hi);
    return i;
}

int getvalue(char *string) {
    int sum = 0;
    for (unsigned i = 0; i < strlen(string); i++) {
        sum += string[i] - 64;
    }
    return sum;
}

// void partition(char **arr, int lo, int hi, int *left, int *right) {
//     char *pivot = arr[hi];
//     for (int curr = lo; curr <= hi; curr++) {
//         if (strcmp(arr[curr], pivot) == 0) {
//             swap(arr, curr, *right);
//             (*right)++;
//         } else if (strcmp(arr[curr], pivot) < 0) {
//             swap(arr, *left, curr);
//             swap(arr, curr, *right);
//             (*left)++;
//             (*right)++;
//         }
//     }
// }

int main() {
    // read file into string
    char *buf;
    long size;
    size = read_input(&buf);

    long comma_count = 0;
    for (int i = 0; i < size; i++) {
        if (buf[i] == ',')
            comma_count++;
    }
    long num_names = comma_count + 1;

    char **names = malloc((unsigned long)num_names * sizeof(char *));

    char *delims = ",\"";
    names[0] = strtok(buf, delims);
    for (int i = 1; i < num_names; i++)
        names[i] = strtok(NULL, delims);
    
    sort(names, 0, (int)num_names - 1);

    long sum = 0;
    for (int i = 0; i < num_names; i++) {
        sum += (i + 1) * getvalue(names[i]);
    }
    printf("%ld\n", sum);
}
