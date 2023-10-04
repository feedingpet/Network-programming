/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: Viết chương trình nhập chuỗi ký tự từ bàn phím
 * Xuất ra số ký tự là chữ cái, số ký tự là số và số ký tự là các ký hiệu
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char chuoi[100];
    int chu_cai = 0, so = 0, ky_hieu = 0;

    printf("Nhập một chuỗi ký tự: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    // Loại bỏ ký tự newline (nếu có) khỏi chuỗi
    chuoi[strcspn(chuoi, "\n")] = '\0';

    for (int i = 0; chuoi[i] != '\0'; i++) {
        if (isalpha(chuoi[i])) {
            chu_cai++;
        } else if (isdigit(chuoi[i])) {
            so++;
        } else {
            ky_hieu++;
        }
    }

    printf("Số ký tự là chữ cái: %d\n", chu_cai);
    printf("Số ký tự là số: %d\n", so);
    printf("Số ký tự là các ký hiệu: %d\n", ky_hieu);

    return 0;
}
