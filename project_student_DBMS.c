#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     

// MNL = Maximum Name Length
#define MNL 100

// TFILE = Text File name used to store student records
#define TFILE "student_records.txt"

// BFILE = Binary File name used to store student records
#define BFILE "student_records.bin"

// Structure to store Student information
typedef struct {
    int rn;             // rn = Roll Number
    char n[MNL];        // n = Name
    int a;              // a = Age
    float m;            // m = Marks
} Stu;                  // Stu = Student

// Structure to manage a dynamic Student List
typedef struct {
    Stu *s;             // s = Pointer to Students array
    int sz;             // sz = Current Size (number of students)
    int c;              // c = Capacity (maximum students that can currently be stored)
} SList;                // SList = Student List

// Initialize Student List
void init_sl(SList *l) {
    l->sz = 0;                              // Initially no student records
    l->c = 10;                              // Initial capacity is 10 students
    l->s = (Stu *)malloc(l->c * sizeof(Stu)); // Allocate memory for 10 students
}

// Resize Student List when capacity becomes full
void resize_sl(SList *l) {
    l->c *= 2;                                // Double the capacity
    l->s = (Stu *)realloc(l->s, l->c * sizeof(Stu)); // Reallocate memory
}

// Add Student Record
void add_sr(SList *l) {

    // Check if list is full
    if (l->sz == l->c) {
        resize_sl(l); // Increase capacity
    }

    // Get address of next student position
    Stu *st = &l->s[l->sz];

    // Input Roll Number
    printf("Enter roll number: ");
    scanf("%d", &st->rn);

    // Input Name
    printf("Enter name: ");
    getchar(); // Remove newline left by previous scanf()
    fgets(st->n, MNL, stdin);

    // Remove newline character from entered name
    st->n[strcspn(st->n, "\n")] = 0;

    // Input Age
    printf("Enter age: ");
    scanf("%d", &st->a);

    // Input Marks
    printf("Enter marks: ");
    scanf("%f", &st->m);

    // Increase student count
    l->sz++;
}

// Display all Student Records
void display_srs(SList *l) {

    // Traverse entire student list
    for (int i = 0; i < l->sz; i++) {

        Stu *st = &l->s[i];

        printf("Roll Number: %d\n", st->rn);
        printf("Name: %s\n", st->n);
        printf("Age: %d\n", st->a);
        printf("Marks: %.2f\n", st->m);
        printf("-----------------------\n");
    }
}

// Search Student Record using Roll Number
Stu* search_sr(SList *l, int rn) {

    // Linear Search
    for (int i = 0; i < l->sz; i++) {

        // Check Roll Number
        if (l->s[i].rn == rn) {

            // Return address of matching student
            return &l->s[i];
        }
    }

    // Return NULL if not found
    return NULL;
}

// Delete Student Record using Roll Number
void delete_sr(SList *l, int rn) {

    int found = 0; // Flag to indicate record found

    for (int i = 0; i < l->sz; i++) {

        // Check if Roll Number matches
        if (l->s[i].rn == rn) {
            found = 1;
        }

        // Shift remaining records left
        if (found && i < l->sz - 1) {
            l->s[i] = l->s[i + 1];
        }
    }

    // If record found
    if (found) {
        l->sz--; // Reduce size
        printf("Student with roll number %d deleted.\n", rn);
    }
    else {
        printf("Student with roll number %d not found.\n", rn);
    }
}

// Save Student Records to Text File
void save_srs(SList *l) {

    FILE *f = fopen(TFILE, "w"); // Open text file in write mode

    // Check file opening
    if (!f) {
        printf("Unable to open file for writing\n");
        return;
    }

    // Save total number of records
    fprintf(f, "%d\n", l->sz);

    // Save each student record
    for (int i = 0; i < l->sz; i++) {

        Stu *st = &l->s[i];

        fprintf(f,
                "%d %s %d %.2f\n",
                st->rn,
                st->n,
                st->a,
                st->m);
    }

    fclose(f); // Close file

    printf("Student records saved to file.\n");
}

// Load Student Records from Text File
void load_srs(SList *l) {

    FILE *f = fopen(TFILE, "r"); // Open text file in read mode

    // Check file opening
    if (!f) {
        printf("Unable to open file for reading\n");
        return;
    }

    int sz;

    // Read total number of student records
    fscanf(f, "%d\n", &sz);

    l->sz = sz;

    // Allocate required memory
    l->s = (Stu *)realloc(l->s, l->sz * sizeof(Stu));

    // Read each student record
    for (int i = 0; i < l->sz; i++) {

        Stu *st = &l->s[i];

        fscanf(f,
               "%d %s %d %f\n",
               &st->rn,
               st->n,
               &st->a,
               &st->m);
    }

    fclose(f); // Close file

    printf("Student records loaded from file.\n");
}

// Save Student Records to Binary File
void save_srs_bin(SList *l) {

    FILE *f = fopen(BFILE, "wb"); // wb = Write Binary mode

    // Check file opening
    if (!f) {
        printf("Unable to open binary file for writing\n");
        return;
    }

    // Write number of records
    fwrite(&l->sz, sizeof(int), 1, f);

    // Write all student records
    fwrite(l->s, sizeof(Stu), l->sz, f);

    fclose(f); // Close file

    printf("Student records saved to binary file.\n");
}

// Load Student Records from Binary File
void load_srs_bin(SList *l) {

    FILE *f = fopen(BFILE, "rb"); // rb = Read Binary mode

    // Check file opening
    if (!f) {
        printf("Unable to open binary file for reading\n");
        return;
    }

    // Read total number of records
    fread(&l->sz, sizeof(int), 1, f);

    // Allocate memory
    l->s = (Stu *)realloc(l->s, l->sz * sizeof(Stu));

    // Read all student records
    fread(l->s, sizeof(Stu), l->sz, f);

    fclose(f); // Close file

    printf("Student records loaded from binary file.\n");
}

// Free allocated memory of Student List
void free_sl(SList *l) {
    free(l->s);
}

int main() {

    SList l; // Student List

    // Initialize Student List
    init_sl(&l);

    int n;

    // Input initial number of student records
    printf("Enter the number of student records to add initially: ");
    scanf("%d", &n);

    // Add initial records
    for (int i = 0; i < n; i++) {
        add_sr(&l);
    }

    char c; // Choice variable

    // Ask user whether more records need to be added
    while (1) {

        printf("Do you want to add another student record? (y/n): ");
        scanf(" %c", &c);

        if (c == 'y' || c == 'Y') {
            add_sr(&l);
        }
        else {
            break;
        }
    }

    // Menu Driven Program
    while (1) {

        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record by Roll Number\n");
        printf("4. Delete Student Record by Roll Number\n");
        printf("5. Save Student Records to Text File\n");
        printf("6. Load Student Records from Text File\n");
        printf("7. Save Student Records to Binary File\n");
        printf("8. Load Student Records from Binary File\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");

        int mc; // mc = Menu Choice
        scanf("%d", &mc);

        int rn;     // Roll Number
        Stu *st;    // Student pointer

        switch (mc) {

            case 1:
                add_sr(&l);
                break;

            case 2:
                display_srs(&l);
                break;

            case 3:

                printf("Enter roll number to search: ");
                scanf("%d", &rn);

                st = search_sr(&l, rn);

                if (st) {

                    printf("Roll Number: %d\n", st->rn);
                    printf("Name: %s\n", st->n);
                    printf("Age: %d\n", st->a);
                    printf("Marks: %.2f\n", st->m);
                }
                else {

                    printf("Student with roll number %d not found.\n", rn);
                }

                break;

            case 4:

                printf("Enter roll number to delete: ");
                scanf("%d", &rn);

                delete_sr(&l, rn);

                break;

            case 5:

                save_srs(&l);

                break;

            case 6:

                load_srs(&l);

                break;

            case 7:

                save_srs_bin(&l);

                break;

            case 8:

                load_srs_bin(&l);

                break;

            case 9:

                // Free memory before exiting
                free_sl(&l);

                exit(0);

            default:

                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
