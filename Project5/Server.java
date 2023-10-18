import java.io.*;
import java.net.*;
import java.util.Scanner;

/**
 Họ và Tên: Nguyễn Ngọc Cường
 MSSV: 21020285
 Viết chương trình phía client và phía server cho phép giao tiếp với nhau
 Giao thức: Mô tả trong file Word đề bài.
 File: Server
 */

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);
            System.out.println("Server is running...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());

                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

                out.println("200 Hello Client");
                String request = in.readLine();
                System.out.println("Client: " + request);

                while (!request.equals("QUIT")) {
                    if (request.equals("USER NAME")) {
                        out.println("210 User name OK");
                        String username = in.readLine();
                        System.out.println("Client: " + username);

                        if (isValidUsername(username)) {
                            out.println("211 User name " + username + " OK");
                        } else {
                            out.println("410 User name error");
                        }
                    } else if (request.equals("USER AGE")) {
                        out.println("220 User age OK");
                        String ageStr = in.readLine();
                        System.out.println("Client: " + ageStr);

                        if (isValidAge(ageStr)) {
                            out.println("221 User age " + ageStr + " OK");
                        } else {
                            out.println("420 User age error");
                        }
                    }
                    request = in.readLine();
                }

                out.println("500 bye");
                clientSocket.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean isValidUsername(String username) {
        // Kiểm tra tính hợp lệ của tên người dùng (không chứa ký tự số hoặc ký tự đặc biệt)
        // Trong ví dụ này, tôi sẽ giả sử rằng nó luôn hợp lệ nếu không chứa ký tự số hoặc ký tự đặc biệt
        return !username.matches(".*\\d.*") && !username.matches(".*\\W.*");
    }

    private static boolean isValidAge(String ageStr) {
        try {
            int age = Integer.parseInt(ageStr);
            // Kiểm tra tính hợp lệ của tuổi (phải là số)
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
