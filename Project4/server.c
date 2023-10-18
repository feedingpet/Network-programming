/*
Họ và Tên: Nguyễn Ngọc Cường
MSSV: 21020285
    Viết chương trình phía client và phía server cho phép giao tiếp với nhau
	Giao thức: Mô tả trong file Word đề bài.  
    File: Server
*/

#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#include <ctype.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

// Function designed for chat between client and server. 
void func(int connfd) 
{ 
    char buff[MAX]; 
    int n; 
    int check = 0;
    int check_name = 0; // require name
    int check_age = 0;   // require age
    int userValid = 0;
    int ageValid = 0;
    int i;
    int send = 0;    // send to client or not
    
    // for loop infi
    for (;;) { 
        bzero(buff, MAX); 
   
        // đọc tin nhắn của client vào buff
        read(connfd, buff, sizeof(buff)); 
        //in ra màn hình tin nhắn của client
        printf("From client: %s\t To client : ", buff); 
        // check xem client đang yêu cầu nhập tên hay tuổi
        if (check == 1) {
            if (check_name == 1) {
                int valid = 1;
                //kiểm tra tên có hợp lệ không
                for (i = 0; i < strlen(buff)-1; i++) {
                    if (!isalpha(buff[i])) {
                        valid = 0;
                        break;
                    }
                }
                if (valid == 1) {
                    write(connfd, "211 User name OK ", 17);
                    write(connfd, buff, strlen(buff));
                    ageValid = 1;
                    check_name = 0;
                    check = 0;
                    send = 1;
                } else {
                    write(connfd, "sai o day", 8);
                    write(connfd, "410 User name error ", 20);
                    send = 1;
                    // Optionally, clear the userName to start over.
                    
                }
            }
            if (check_age == 1) {
                int valid = 1;
                // kiểm tra tuổi có hợp lệ không
                for (i = 0; i < strlen(buff)-1; i++) {
                    if (buff[i] > '9' || buff[i] < '0') {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                        write(connfd, "221 User age OK ", 16);
                        write(connfd, buff, strlen(buff));
                        ageValid = 1;
                        check_age = 0;
                        check = 0;
                        send = 1;
                } else {
                    write(connfd, "420 User age error", 19);
                    send = 1;
                }
            }
        }
        
        // nếu yêu cầu từ người dùng là gì thì tương ứng trả về thông báo đó
        if (strncmp(buff, "HELLO", 4) == 0) {
            write(connfd, "200 Hello Client\n", 16);
            send = 1;
        }
        if (strncmp(buff, "USER NAME", 9) == 0) {
            write(connfd, "210 User name OK\n", 16);
            check = 1;
            check_name = 1;
            send = 1;
        }
        if (strncmp(buff, "USER AGE", 8) == 0) {
            write(connfd, "220 User age OK\n", 16);
            check = 1;
            check_age = 1;
            send = 1;
        }
        
        if(check == 0){
        bzero(buff, MAX); 
        n = 0; 
        // Yêu cầu bình thường thì nhập trả lại dữ liệu cho client
        
        while ((buff[n++] = getchar()) != '\n')
        // send to client
        write(connfd, buff, sizeof(buff)); 
        }
   
        // exit to program
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
    send = 0;
    
} 

// Driver function 
int main() { 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 
	// create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// address ip & port
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else printf("Socket successfully binded..\n"); 

	
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else printf("Server listening..\n"); 


	len = sizeof(cli); 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server accept failed...\n"); 
		exit(0); 
	} 
	else printf("server accept the client...\n"); 

	func(connfd); 

	
	close(sockfd); 
}

