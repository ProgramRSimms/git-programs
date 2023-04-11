/*assign5.c Roderick Simms/aak759*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>

//void errExit(const char szFmt[], ... );
//#define BLOCK_SZ 4096L


typedef struct {
    char course_Name[80];//course name
    char course_Sched[4];//string MWF or TR
    unsigned course_Hours;//credit hours
    unsigned course_Size;//numb of students in course
    unsigned padding;
} COURSE;

//C
int create_Course(char* filename){
    FILE* f;//file ptr
    COURSE course;

    // Open file in write mode
    f = fopen(filename, "w+");//open

    //check for error opening f
    if (!f){
        printf("Error opening file\n");
        return 0;
    }
    //prompt for/store user data
    printf("Enter course name: \n");
    fgets(course.course_Name, 80, stdin);
    printf("Enter course schedule as \"MWF\" or \"TR\"\n");
    fgets(course.course_Sched, 4, stdin);
    printf("Enter course hours: \n");
    scanf("%u", &course.course_Hours);
    printf("Enter course hours: \n");
    scanf("%u", &course.course_Size);
    printf("Enter course padding: \n");
    scanf("%u", &course.padding);

    fwrite(&course, sizeof(COURSE), 1, f);
    fclose(f);//close

    return 1;
}

//R
void read_Course (char* filename, char* course_name){
    FILE* f;
    COURSE course;
    int found = 0;

    // Open file for reading
    f = fopen(filename, "r+");//open in read
    if (!f){
        printf("Error opening file\n");
        //return 0;
    }

    while (fread(&course, sizeof(COURSE), 1, f) != '\0'){
        //check if already exists
        if(strcmp(course_name, course.course_Name) == 0){
            found = 1;
            break;
        }
    }
    if (found){
        printf("COURSE:");
        printf("Course name: %s\n", course.course_Name);
        printf("Course schedule: %s\n", course.course_Sched);
        printf("Course hours: %u\n", course.course_Hours);
        printf("Course size: %u\n", course.course_Size);
        printf("Course padding: %d\n", course.padding);
    }
    else{
        printf("Error finding course\n");
    }
    fclose(f);//close f
    //void return
}

//U
int update_Course(char* filename, char* course_name){
    FILE *f, *temp_f;
    COURSE course;
    int found = 0;

    // Open file for reading
    f = fopen(filename, "r+");
    temp_f = fopen(".temp", "w+");
    if (!f && !temp_f){
        printf("File open error\n");

        return 0;
    }

    while (fread(&course, sizeof(COURSE), 1, f) != '\0'){
        if(strcmp(course_name, course.course_Name) == 0){
            printf("Course found!\n");
            printf("Enter new course name: ");
            fgets(course.course_Name, 80, stdin);
            printf("Enter new course schedule: ");
            fgets(course.course_Sched, 4, stdin);
            printf("Enter new course hours: ");
            scanf("%u", &course.course_Hours);
            printf("Enter new course hours: ");
            scanf("%u", &course.course_Size);
            printf("Enter new course padding: ");
            scanf("%d", &course.padding);
            found = 1;
        }
        fwrite(&course, sizeof(course), 1, temp_f);
    }
    if (!found){
        printf("Course not found!\n");
    }

    fclose(f);
    fclose(temp_f);

    remove(filename);
    rename(".temp", filename);

    return 1;
}

//D
int delete_Course(char* filename, char* course_name){
    FILE *f, *temp_f;
    COURSE course;
    int found = 0;

    // Open file for reading
    f = fopen(filename, "r+");
    temp_f = fopen(".temp", "w");
    if (!f && !temp_f){
        printf("File open error\n");
        return 0;
    }

    while (fread(&course, sizeof(COURSE), 1, f) != '\0'){
        if(strcmp(course_name, course.course_Name) == 0){
            printf("Course found!\n");
            found = 1;
        }
        else{
            fwrite(&course, sizeof(course), 1, temp_f);
        }
    }

    if (!found){
        printf("Course not found!\n");
    }

    fclose(f);
    fclose(temp_f);

    remove(filename);
    rename(".temp", filename);

    return 1;
}

int main(int argc, char *argv[]){
    char* filename = "courses.dat";
    char course_name[80], selection;

/*
        int iFdRd; // FD for file to be read
        int iFdWr; // FD for file to be written
        char sbBuff[BLOCK_SZ]; // buffer for copying data
        int iRead; // number of bytes read
        int iWrite; // number of bytes written
        int iTotal = 0; // total number of bytes written // check the number of arguments

        if (argc < 3){
            errExit("Too few arguments for copy"); // Open the file to read
            iFdRd = open(argv[1], O_RDONLY);
        }
        if (iFdRd < 0){
            errExit("Open file for read: %s", strerror(errno));
        }
        // Open the file for create and give an error
        // if it exists. Give permissions 00660
        iFdWr = open(argv[2], O_WRONLY|O_CREAT|O_EXCL , S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
        if (iFdWr < 0){
            errExit("Open file for write: %s", strerror(errno));
        }
        printf("Files:\nFD Filename\n"); printf("%2d %s\n", iFdRd, argv[1]);
        printf("%2d %s\n", iFdWr, argv[2]); // read until EOF (iRead will be 0)
        while ((iRead = read(iFdRd, sbBuff, BLOCK_SZ)) > 0) {
            iWrite = write(iFdWr, sbBuff, iRead);
            if (iWrite < 0) errExit("writing copy: %s", strerror(errno));
            iTotal += iWrite;
            printf ("Read %d bytes, wrote %d bytes\n", iRead, iWrite);
        }
        close(iFdRd);
        close(iFdWr);
        printf("Total bytes written = %d bytes\n", iTotal);
        */

    //continue prompting unless CTRL D entered
    while (fgets(&selection, 1000, stdin) != NULL){
        printf("Please make a selection:\n");
        printf("Enter \"C\" to create a course.\n");
        printf("Enter \"R\" to read course data.\n");
        printf("Enter \"U\" to update course data.\n");
        printf("Enter \"D\" to delete a course.\n");
        printf("Enter CTRL-D to exit\n");
        //get input
        scanf("%c", &selection);

        //switch case for selection
        switch (selection){
            case 'C':
            case 'c':
                //function call for Create
                create_Course(filename);
                break;
            case 'R':
            case 'r':
                //get the course number to read
                printf("Enter the course you wish to read data from.\n");
                fgets(course_name, 80, stdin);
                read_Course(filename, course_name);
                break;
            case 'U':
            case 'u':
                //get the course number to read for the update
                printf("Enter course you wish to update.\n");
                fgets(course_name, 80, stdin);
                if(update_Course(filename, course_name))
                    printf("You updated the course data.\n");
                break;
            case 'D':
            case 'd':
                //get the course number to read for deletion
                printf("Enter the course number you wish to delete.\n");
                fgets(course_name, 80, stdin);
                if(delete_Course(filename, course_name))
                    printf("You deleted the course.\n");
                break;
            default:
                //control D to exit
                printf("Please make a valid selection.\n");
                //exit (0);
        }
    }
    return 0;
}
