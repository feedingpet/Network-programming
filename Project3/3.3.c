/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Viết chương trình thực hiện các tác vụ sau:
 * nhập thông tin về kích thước file, kiểu file, tên file
 * Lưu các thông tin về file theo định dạng JSON vào file có tên pkt_hdr_json.txt.
 * So sánh kích thước file pkt_hdr.txt và pkt_hdr_json.txt
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
    
    // Nhập thông tin từ người dùng
    printf("Nhập kích thước file (byte): ");
    scanf("%hu", &fileInfo.fileSize);

    printf("Nhập loại file (0x00 - text, 0x01 - binary): ");
    scanf("%hhu", &fileInfo.fileType);

    printf("Nhập tên file: ");
    scanf("%s", fileInfo.fileName);

    // Lưu thông tin vào file JSON
    FILE *fileJson = fopen("pkt_hdr_json.txt", "w");
    if (fileJson == NULL) {
        printf("Không thể mở file pkt_hdr_json.txt để ghi dữ liệu.\n");
        return 1;
    }

    fprintf(fileJson, "{\n");
    fprintf(fileJson, "\"fileSize\": %hu,\n", fileInfo.fileSize);
    fprintf(fileJson, "\"fileType\": %hhu,\n", fileInfo.fileType);
    fprintf(fileJson, "\"fileName\": \"%s\"\n", fileInfo.fileName);
    fprintf(fileJson, "}\n");

    fclose(fileJson);
    printf("Thông tin đã được lưu vào file pkt_hdr_json.txt.\n");

    // So sánh kích thước file pkt_hdr.txt và pkt_hdr_json.txt
    FILE *fileTxt = fopen("pkt_hdr.txt", "r");
    if (fileTxt == NULL) {
        printf("Không thể mở file pkt_hdr.txt.\n");
        return 1;
    }

    fseek(fileTxt, 0, SEEK_END);
    long txtFileSize = ftell(fileTxt);
    fclose(fileTxt);

    fileJson = fopen("pkt_hdr_json.txt", "r");
    if (fileJson == NULL) {
        printf("Không thể mở file pkt_hdr_json.txt.\n");
        return 1;
    }

    fseek(fileJson, 0, SEEK_END);
    long jsonFileSize = ftell(fileJson);
    fclose(fileJson);

    printf("Kích thước file pkt_hdr.txt: %ld byte\n", txtFileSize);
    printf("Kích thước file pkt_hdr_json.txt: %ld byte\n", jsonFileSize);

    return 0;
}
