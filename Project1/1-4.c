/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: Viết chương trình đọc dữ liệu từ một file ảnh và lưu dữ liệu đó sang một file khác.
 * Sử dụng hàm md5 hoặc md5sum để kiểm tra xem dữ liệu của 2 file có trùng nhau không
 * Tên file ảnh và đường dẫn file ảnh có thể tùy chỉnh theo ý muốn.
 */
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define BUFFER_SIZE 1024

void calculateMD5(FILE *file, unsigned char *digest) {
    MD5_CTX context;
    size_t bytes;
    unsigned char buffer[BUFFER_SIZE];

    MD5_Init(&context);
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        MD5_Update(&context, buffer, bytes);
    }
    MD5_Final(digest, &context);
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    unsigned char input_digest[MD5_DIGEST_LENGTH];
    unsigned char output_digest[MD5_DIGEST_LENGTH];

    printf("Nhap ten file input: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Khong the mo file input!\n");
        return 1;
    }

    printf("Nhap ten file output: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Khong the mo file output!\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    input_file = fopen(input_filename, "rb");
    calculateMD5(input_file, input_digest);
    fclose(input_file);

    output_file = fopen(output_filename, "rb");
    calculateMD5(output_file, output_digest);
    fclose(output_file);

    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        if (input_digest[i] != output_digest[i]) {
            printf("File input va file output khong trung nhau.\n");
            return 0;
        }
    }

    printf("File input va file output trung nhau.\n");

    return 0;
}
