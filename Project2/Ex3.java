import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: đọc dữ liệu từ một file text và lưu các ký tự là chữ cái sang một file khác.
 * Tên file văn bản đầu vào và đầu ra có thể tùy chỉnh và yêu cầu cần có file văn bản đã tạo sẵn
 */

public class Ex3 {
    public static void main(String[] args) {
        String inputFile = "input.txt"; // Tên file đầu vào
        String outputFile = "output.txt"; // Tên file đầu ra

        try {
            FileReader fileReader = new FileReader(inputFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            FileWriter fileWriter = new FileWriter(outputFile);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            int character;
            while ((character = bufferedReader.read()) != -1) {
                char ch = (char) character;
                if (Character.isLetter(ch)) {
                    bufferedWriter.write(ch);
                }
            }

            bufferedReader.close();
            bufferedWriter.close();

            System.out.println("Dữ liệu đã được lọc và lưu vào " + outputFile);
        } catch (IOException e) {
            System.err.println("Lỗi: " + e.getMessage());
        }
    }
}
