Viết chương trình nhập 1 danh sách sinh viên theo định dạng:
Dòng đầu tiên là số nguyên dương n - số lượng sinh viên,
sau đó mỗi dòng chứa thông tin về 1 sinh viên theo định dạng:
STT,MSSV,Họ và tên,Điểm HP
Sau đó in ra: 
Số lượng SV có Điểm HP < 4 
Số lượng SV có điểm HP >= 4
Sinh viên đầu tiên trong danh sách có điểm HP cao nhất theo cùng định dạng như dữ liệu nhập.
Giới hạn: MSSV có không quá 9 ký tự
Họ và tên: Không quá 100 ký tự.
Điểm HP: Lẻ đến 1 chữ số phần thập phân.
Ví dụ:
3
1,112233,Nguyễn Văn A,9.5
2,112235,Nguyễn B,3.5
3,221156,Trần Thị C,4.0
Đầu ra:
1
2
1,112233,Nguyễn Văn A,9.5
Lưu ý: Tập sử dụng vec-tơ
Gợi ý: Định nghĩa cấu trúc SinhVien, sau đó typedef struct SinhVien vec_elem_t;