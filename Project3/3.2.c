/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Đọc chuỗi byte từ file pkt_hdr.bin tạo ra ở bài 3.1
 * Xuất thông tin kích thước file, kiểu file, độ dài tên file, tên file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

struct udphdr {
    unsigned short fileSize; // Kích thước file
    unsigned char fileType; // Loại file (0x00 cho text file, 0x01 cho binary file)
    unsigned char fileNameLength; // Độ dài tên file
    char fileName[MAX_NAME_LENGTH]; // Tên file
};

int main() {
    struct udphdr header;

    // Mở tệp pkt_hdr.bin để đọc
    FILE *file = fopen("pkt_hdr.bin", "rb");
    if (file == NULL) {
        printf("Không thể mở tệp pkt_hdr.bin để đọc.\n");
        return 1;
    }

    // Đọc cấu trúc dữ liệu từ tệp pkt_hdr.bin
    fread(&header, sizeof(struct udphdr), 1, file);
    fclose(file);

    // Xuất thông tin từ cấu trúc dữ liệu
    printf("Kích thước file: %hu\n", header.fileSize);
    printf("Loại file: 0x%02X\n", header.fileType);
    printf("Độ dài tên file: %hhu\n", header.fileNameLength);
    printf("Tên file: %s\n", header.fileName);

    return 0;
}