
Bài thực hành 4 
- Viết chương trình client-server giao tiếp đơn giản 
- A. Mục tiêu 
- Sinh viên hiểu cách viết chương trình phía client và phía server bằng ngôn ngữ C 
- B. Lưu ý chung: 
- Lập trình với ngôn ngữ Java


- C. Nội dung thực hành 

-  Cho giao thức như dưới đây 
- Client:  HELO Server 
- Server:  200 Hello Client 
- Client:  USER NAME 
- Server: 210  User name OK 
- Client: abc123 
- Server: 410 User name error      // Nếu tên có ký tự số hoặc ký tự đặc biệt thì trả lại mã 400 báo lỗi 
- Client:  USER NAME 
- Server: 210  User name OK 
- Client: Hoang 
- Server: 211 User name Hoang OK  
- Client:  USER AGE  
- Server: 220 User age OK 
- Client:  abc123                            
- Server: 420 User age error         // Nếu tuổi k phải là số thì trả lại mã 400 báo lỗi 
- Client:  USER AGE  
- Server: 220 User age OK 
- Client: 20 
- Server: 221 User age 20 OK 
- Client: QUIT  
- Server: 500 bye 
- Viết chương trình phía client và phía server cho phép giao tiếp với nhau bằng giao thức như trên.  

