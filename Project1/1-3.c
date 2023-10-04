/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: đọc dữ liệu từ một file text và lưu các ký tự là chữ cái sang một file khác.
 * Tên file văn bản đầu vào và đầu ra có thể tùy chỉnh và yêu cầu cần có file văn bản đã tạo sẵn
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100], input_char;

    printf("Nhap ten file input: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Khong the mo file input!\n");
        return 1;
    }

    printf("Nhap ten file output: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Khong the mo file output!\n");
        return 1;
    }

    while ((input_char = fgetc(input_file)) != EOF) {
        if (isalpha(input_char)) {
            fputc(input_char, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
