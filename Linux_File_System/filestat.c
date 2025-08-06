#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) printf("File type: Regular file\n");
    else if (S_ISDIR(mode)) printf("File type: Directory\n");
    else if (S_ISLNK(mode)) printf("File type: Symbolic link\n");
    else if (S_ISCHR(mode)) printf("File type: Character device\n");
    else if (S_ISBLK(mode)) printf("File type: Block device\n");
    else if (S_ISFIFO(mode)) printf("File type: FIFO/pipe\n");
    else if (S_ISSOCK(mode)) printf("File type: Socket\n");
    else printf("File type: Unknown\n");
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (lstat(argv[1], &st) == -1) {
        perror("lstat");
        return 1;
    }

    printf("======= File information: %s =======\n", argv[1]);
    print_file_type(st.st_mode);
    printf("Size: %ld bytes\n", st.st_size);

    struct passwd *pw = getpwuid(st.st_uid);
    struct group  *gr = getgrgid(st.st_gid);
    printf("Owner: %s\n", pw ? pw->pw_name : "Unknown");
    printf("Group: %s\n", gr ? gr->gr_name : "Unknown");
    printf("Permissions: %o\n", st.st_mode & 0777);

    char time_str[50];
    struct tm *time_info = localtime(&st.st_mtime);
    strftime(time_str, sizeof(time_str), "%d/%m/%Y, %H:%M:%S", time_info);
    printf("Last Modified: %s\n", time_str);

    return 0;
}

