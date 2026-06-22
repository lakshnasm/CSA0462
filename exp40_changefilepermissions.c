#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    char filename[] = "file.txt";

    int new_permissions =
        S_IRUSR | S_IWUSR |    // Owner: rw-
        S_IRGRP | S_IWGRP |    // Group: rw-
        S_IROTH;               // Others: r--

    if (chmod(filename, new_permissions) == 0)
    {
        printf("File permissions changed successfully.\n");
    }
    else
    {
        perror("chmod");
        return 1;
    }

    return 0;
}
