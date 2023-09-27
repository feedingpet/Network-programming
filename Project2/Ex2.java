import java.io.*;
import java.util.Scanner;

/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: nhập tên file và các chuỗi ký tự từ bàn phím cho đến khi nhập 'end' kết thúc.
 * Lưu các chuỗi ký tự đã nhập vào file và xuất kích thước file ra màn hình
 */

public class Ex2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập tên file: ");
        String fileName = scanner.nextLine();

        try {
            FileWriter fileWriter = new FileWriter(fileName);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            System.out.println("Nhập các chuỗi ký tự (Nhập 'end' để kết thúc):");

            String line;
            while (!(line = scanner.nextLine()).equals("end")) {
                bufferedWriter.write(line);
                bufferedWriter.newLine();
            }

            bufferedWriter.close();

            File file = new File(fileName);
            long fileSize = file.length();

            System.out.println("Kích thước file: " + fileSize + " bytes");

        } catch (IOException e) {
            System.err.println("Lỗi khi ghi vào file: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
