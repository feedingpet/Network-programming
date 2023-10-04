/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: Đọc thông tin về file lưu trong file pkt_hdr_json.txt tạo ra ở bài 3.3
 * Xuất giá trị (không bao gồm thuộc tính) của file ra màn hình
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

struct FileInfo {
    unsigned short fileSize; // Kích thước file
    unsigned char fileType; // Loại file (0x00 - text, 0x01 - binary)
    char fileName[MAX_NAME_LENGTH]; // Tên file
};

int main() {
    struct FileInfo fileInfo;
    
    // Mở file JSON để đọc thông tin
    FILE *fileJson = fopen("pkt_hdr_json.txt", "r");
    if (fileJson == NULL) {
        printf("Không thể mở file pkt_hdr_json.txt để đọc thông tin.\n");
        return 1;
    }

    // Đọc thông tin từ file JSON
    fscanf(fileJson, "{\n");
    fscanf(fileJson, "\"fileSize\": %hu,\n", &fileInfo.fileSize);
    fscanf(fileJson, "\"fileType\": %hhu,\n", &fileInfo.fileType);
    fscanf(fileJson, "\"fileName\": \"%s\"\n", fileInfo.fileName);
    fscanf(fileJson, "}\n");

    fclose(fileJson);

    // Xuất giá trị của file ra màn hình
    printf("Kích thước file: %hu byte\n", fileInfo.fileSize);
    printf("Loại file: 0x%02x\n", fileInfo.fileType);
    printf("Tên file: %s\n", fileInfo.fileName);

    return 0;
}
