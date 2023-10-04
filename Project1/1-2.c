/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: nhập tên file và các chuỗi ký tự từ bàn phím cho đến khi nhập 'end' kết thúc.
 * Lưu các chuỗi ký tự đã nhập vào file và xuất kích thước file ra màn hình
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fileName[100];
    printf("Nhập tên file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Lỗi khi mở file\n");
        return 1;
    }

    printf("Nhập các chuỗi ký tự (Nhập 'end' để kết thúc):\n");
    char line[100];
    while (1) {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "end") == 0) {
            break;
        }
        fprintf(file, "%s\n", line);
    }

    fclose(file);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Lỗi khi mở file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    printf("Kích thước file: %ld bytes\n", fileSize);

    fclose(file);

    return 0;
}