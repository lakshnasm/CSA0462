#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy()
{
    const char *sourcefile="sasi.txt";
    const char *destination_file="sk.txt";

    int source_fd=open(sourcefile,O_RDONLY);
    int dest_fd=open(destination_file,O_WRONLY|O_CREAT|O_TRUNC,0666);

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while((bytesRead=read(source_fd,buffer,BUFFER_SIZE))>0)
        write(dest_fd,buffer,bytesRead);

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
}

void create()
{
    FILE *fp;
    fp=fopen("sasi.txt","w");
    printf("File created successfully");
    fclose(fp);
}

int main()
{
    int n;

    printf("1.Create\t2.Copy\t3.Delete\n");
    scanf("%d",&n);

    switch(n)
    {
        case 1: create(); break;
        case 2: copy(); break;
        case 3:
            remove("sasi.txt");
            printf("Deleted successfully");
            break;
    }
}
