#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOGFILE "audit.log"
#define BUFFER_SIZE 1024

void write_str(const char *s) {
    write(1, s, strlen(s));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        write_str("Usage:\n./auditlog --add \"message\"\n./auditlog --view\n");
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0) {
        if (argc != 3) {
            write_str("Usage: ./auditlog --add \"message\"\n");
            return 1;
        }
        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) {
            write_str("Error opening file\n");
            return 1;
        }
        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);
        close(fd);
    }
    else if (strcmp(argv[1], "--view") == 0) {
        int fd = open(LOGFILE, O_RDONLY);
        if (fd < 0) {
            write_str("No log file found.\n");
            return 1;
        }
        char buffer[BUFFER_SIZE];
        int bytesRead;
        int line = 1;
        char num[20];
        int atLineStart = 1;

        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
            for (int i = 0; i < bytesRead; i++) {
                if (atLineStart) {
                    int len = sprintf(num, "%d: ", line++);
                    write(1, num, len);
                    atLineStart = 0;
                }
                write(1, &buffer[i], 1);
                if (buffer[i] == '\n') {
                    atLineStart = 1;
                }
            }
        }
        close(fd);
    }
    else {
        write_str("Invalid command.\n./auditlog --add \"message\"\n./auditlog --view\n");
    }
    return 0;
}
