package org.example;

import java.io.*;
import java.security.MessageDigest;

/**
 * Họ tên: Nguyễn Ngọc Cường
 * MSV: 21020285
 * Chuơng trình: Viết chương trình đọc dữ liệu từ một file ảnh và lưu dữ liệu đó sang một file khác.
 * Sử dụng hàm md5 hoặc md5sum để kiểm tra xem dữ liệu của 2 file có trùng nhau không
 * Tên file ảnh và đường dẫn file ảnh có thể tùy chỉnh theo ý muốn.
 * Lưu ý: Để chạy file này cần tạo project mới với build system là Maven để thêm thư viện Apache Commons Codec.
 */

public class Ex4 {
    public static void main(String[] args) {
        String sourceFilePath = "file1.png"; // Thay đổi thành đường dẫn của file ảnh nguồn
        String targetFilePath = "file2.png"; // Thay đổi thành đường dẫn của file ảnh đích

        try {
            // Đọc dữ liệu từ file nguồn
            FileInputStream sourceFileInputStream = new FileInputStream(sourceFilePath);
            byte[] sourceData = new byte[sourceFileInputStream.available()];
            sourceFileInputStream.read(sourceData);
            sourceFileInputStream.close();

            // Lưu dữ liệu vào file đích
            FileOutputStream targetFileOutputStream = new FileOutputStream(targetFilePath);
            targetFileOutputStream.write(sourceData);
            targetFileOutputStream.close();

            System.out.println("Dữ liệu đã được sao chép vào file đích.");

            // Tính toán mã MD5 cho cả hai file
            String sourceFileMD5 = calculateMD5(sourceFilePath);
            String targetFileMD5 = calculateMD5(targetFilePath);

            // So sánh mã MD5
            if (sourceFileMD5.equals(targetFileMD5)) {
                System.out.println("Dữ liệu của hai file trùng nhau.");
            } else {
                System.out.println("Dữ liệu của hai file không trùng nhau.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Hàm tính toán mã MD5 cho một file
    private static String calculateMD5(String filePath) throws IOException {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            FileInputStream fis = new FileInputStream(filePath);
            byte[] dataBytes = new byte[1024];

            int bytesRead;
            while ((bytesRead = fis.read(dataBytes)) != -1) {
                md.update(dataBytes, 0, bytesRead);
            }

            byte[] mdBytes = md.digest();

            StringBuilder sb = new StringBuilder();
            for (byte mdByte : mdBytes) {
                sb.append(Integer.toString((mdByte & 0xff) + 0x100, 16).substring(1));
            }

            return sb.toString();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
