#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char *argv[]) {

    struct stat st;

    if (argc != 2) {
        printf("give file path\n");
        return 1;
    }

    stat(argv[1], &st);

    printf("=== File Attributes for: %s ===\n", argv[1]);

    printf("File Type:            ");
    if (S_ISREG(st.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else
        printf("Other\n");

    printf("Permissions:          0%o\n", st.st_mode & 0777);
    printf("File Size:            %ld bytes\n", st.st_size);
    printf("Hard Links Count:     %ld\n", st.st_nlink);
    printf("Owner (UID):          %d\n", st.st_uid);
    printf("Group (GID):          %d\n", st.st_gid);
    printf("Last Access Time:     %s", ctime(&st.st_atime));
    printf("Last Modification:    %s", ctime(&st.st_mtime));
    printf("Status Change Time:   %s", ctime(&st.st_ctime));

    return 0;
}