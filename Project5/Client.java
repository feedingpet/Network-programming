import java.io.*;
import java.net.*;
import java.util.Scanner;

/**
Họ và Tên: Nguyễn Ngọc Cường
MSSV: 21020285
    Viết chương trình phía client và phía server cho phép giao tiếp với nhau
	Giao thức: Mô tả trong file Word đề bài.
    File: Client
*/


public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 12345);

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            Scanner scanner = new Scanner(System.in);

            String response = in.readLine();
            System.out.println("Server: " + response);

            while (true) {
                String request = scanner.nextLine();
                out.println(request);

                response = in.readLine();
                System.out.println("Server: " + response);

                if (request.equals("QUIT")) {
                    break;
                }
            }

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
