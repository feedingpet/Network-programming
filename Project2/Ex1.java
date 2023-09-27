import java.util.Scanner;

/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: Viết chương trình nhập chuỗi ký tự từ bàn phím
 * Xuất ra số ký tự là chữ cái, số ký tự là số và số ký tự là các ký hiệu
 */

public class Ex1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập chuỗi ký tự: ");
        String input = scanner.nextLine();

        int soChuCai = 0;
        int soChuSo = 0;
        int soKyHieu = 0;

        // Check every single character
        for (int i = 0; i < input.length(); i++) {
            char kyTu = input.charAt(i);
            if (Character.isLetter(kyTu)) {
                soChuCai++;
            } else if (Character.isDigit(kyTu)) {
                soChuSo++;
            } else {
                soKyHieu++;
            }
        }

        System.out.println("Số ký tự chữ cái: " + soChuCai);
        System.out.println("Số ký tự số: " + soChuSo);
        System.out.println("Số ký tự ký hiệu: " + soKyHieu);

        scanner.close();
    }
}
