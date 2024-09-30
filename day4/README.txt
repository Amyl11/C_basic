Cho danh sách sinh viên, thông tin về mỗi sinh viên được cho trên 1 dòng theo định dạng:
STT,MSSV,Họ và tên,Điểm HP
Giới hạn: MSSV có không quá 9 ký tự
Họ và tên: Không quá 99 ký tự.
Điểm HP: Lẻ đến 1 chữ số phần thập phân.
Mỗi MSSV xác định đúng 1 sinh viên.
Danh sách sinh viên được kết thúc bằng 1 dòng chứa ***** (5 dấu *).
Sau đó là các mã số sinh viên, mỗi mã số trên 1 dòng, danh sách mã số kết thúc bằng ***** (5 dấu *).
Viết chương trình đọc vào danh sách sinh viên rồi in ra:
n - số lượng sinh viên trong danh sách (trên 1 dòng).
Tiếp theo là n dòng, mỗi dòng là thông tin về 1 sv được sắp xếp theo thứ tự
giảm dần điểm HP, nếu điểm học phần bằng nhau thì sắp xếp tăng dần MSSV.
m - số lượng MSSV đọc được.
Cuối cùng là m dòng, mỗi dòng là thông tin chi tiết về 1 sv có mã số tương ứng.
Ví dụ:
Đầu vào:
1,112239,Nguyễn Văn A,9.5
2,112235,Nguyễn B,3.5
3,221156,Trần Thị C,4.0
4,112233,Nguyễn AB,9.5
5,221256,Trần Văn D,6.0
*****
112235
112233
*****
Đầu ra:
5
4,112233,Nguyễn AB,9.5
1,112239,Nguyễn Văn A,9.5
5,221256,Trần Văn D,6.0
3,221156,Trần Thị C,4.0
2,112235,Nguyễn B,3.5
2
2,112235,Nguyễn B,3.5
4,112233,Nguyễn AB,9.5