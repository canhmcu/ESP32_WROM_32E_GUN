Ý TƯỞNG 

- một bộ điều khiển cho súng bắn tạo giật, dựa trên sự phóng nạp của tụ điện và cuộn dây, esp32 sẽ điều khiển ic tạo xung, xung này qua biến thế và đưa áp lên 400v, áp 400v nuôi trong tụ rất to, khi bóp cò thì tụ này xả điện vào cuộn cảm, cuộn cảm tạo ra từ trường đẩy cò súng.
- khi khởi động thì esp32 sẽ kết nối mạng và nháy đèn, esp32 mở IC tạo xung SG3525AN, IC điều khiển đóng mở 2 tran trước biến thế. Khi con tran nào mở thì tụ C1 xả áp dc 12V ra biến thế, biến thế kích lên 400v để ở tụ C2, đồng thời có điện áp đi về phản hồi tạo xung âm
- esp32 điều khiển đóng mở con fet Q2 để thông mạch và bắn điện áp ra cuộn dây phía sau
- 2 con diot cuối để chống dòng ngược vì cuộn dây sau khi xả điện sẽ có hiện tượng trở thành máy phát điện và đưa dòng ngược về.

CODE
- Đầu tiên cài đặt thư viện cần thiết, tìm hiểu về giao thức UDP 
User Datagram Protocol (UDP) là một trong các giao thức trong hệ thống truyền thông mạng Internet Protocol (IP). UDP là một giao thức giao tiếp không kết nối, không đảm bảo độ tin cậy của dữ liệu và không duy trì trạng thái kết nối giữa các điểm cuối. Điều này có nghĩa là khi gửi dữ liệu qua UDP, không có quá trình thiết lập kết nối hay xác nhận nhận dạng dữ liệu.

Các đặc điểm chính của UDP bao gồm:

-Không Kết Nối (Connectionless): UDP không yêu cầu quá trình thiết lập kết nối trước khi gửi dữ liệu. Nó chỉ đơn giản là gửi gói tin mà không cần xác nhận.

-Không Đảm Bảo Tin Cậy (Unreliable): UDP không đảm bảo rằng dữ liệu sẽ được gửi hoặc nhận đúng và đầy đủ. Nếu có mất mát hoặc lỗi trên đường truyền, UDP không thực hiện việc chuyển gói tin lại.

-Không Duy Trì Trạng Thái (Stateless): UDP không lưu trữ thông tin trạng thái về các kết nối. Mỗi gói tin được xử lý độc lập với các gói khác.

-Hiệu Suất Cao: Do không có quá trình thiết lập kết nối và không yêu cầu xác nhận, UDP thường có hiệu suất cao hơn trong môi trường mạng nhanh và ổn định.

UDP thường được sử dụng trong các ứng dụng yêu cầu truyền dữ liệu nhanh và không cần tính tin cậy cao như trò chơi trực tuyến, audio/video streaming, và các ứng dụng IoT (Internet of Things). Tuy nhiên, do tính chất không đảm bảo tin cậy, nó không phù hợp cho các ứng dụng yêu cầu độ chính xác và đồng bộ cao.

- xem hình ảnh sử dụng ứng dụng USR-TCP232-Test-V1.3 ở file ảnh phanmem.png
- giao thức UDP cho phép trao đổi thông tin giữa 2 thiết bị cùng truy cập 1 IP và 1 port.
- trong code thì chú ý khi nhấn nút sẽ cho mở con mosfet và đóng con ic dao động trong 200ms 
- sau này phát triển khi ko bắn thì gửi mã gì qua UDP khi bắn thì gửi mã gì
