/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: nhập thông tin về kích thước file, kiểu file, tên file theo định dạng cho trước
 * ghi chuỗi byte này vào file có tên là pkt_hdr.bin (tự nhập tên file)
 * Xuất ra màn hình kích thước file
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
    
    // Nhập thông tin về kích thước file
    printf("Nhập kích thước file: ");
    scanf("%hu", &header.fileSize);
    
    // Nhập loại file (0x00 cho text, 0x01 cho binary)
    printf("Nhập loại file (00 cho text, 01 cho binary): ");
    scanf("%hhu", &header.fileType);
    
    // Nhập tên file
    printf("Nhập tên file: ");
    scanf("%s", header.fileName);
    
    // Tính độ dài của tên file và cập nhật vào header
    header.fileNameLength = (unsigned char)strlen(header.fileName);
    
    // Ghi cấu trúc dữ liệu vào file pkt_hdr.bin
    FILE *file = fopen("pkt_hdr.bin", "wb");
    if (file == NULL) {
        printf("Không thể mở file pkt_hdr.bin để ghi.\n");
        return 1;
    }
    
    fwrite(&header, sizeof(struct udphdr), 1, file);
    fclose(file);
    
    // Xuất kích thước file ra màn hình
    printf("Kích thước file là: %hu\n", header.fileSize);
    
    return 0;
}
