# PNUCS353
Các bài tập QT Creator
Vào link: https://github.com/tranthangdong/PNUCS353

Widgets: Thành phần mà chúng ta sử dụng để thiết kế GUI  (giao diện)
========================================================================================================
+ QPushButton: Nút bấm
+ QLabel: Nhãn thông tin, hiển thị văn bản
+ QTextEdit: Nhập văn bản, hiển thị văn bản, hàm dữ liệu: toPlainText
+ QTableWidget: Chứa dữ liệu dòng và cột
+ QComboBox: Lưu trữ các dữ liệu theo dòng --> để lựa chọn thông tin bằng cách clik chuột; hàm dữ liệu: currentText
			 https://doc.qt.io/qt-5/qcombobox.html
+ RadioButton: Lựa chọn duy nhất
+ Checkbox: Nhiều lựa chọn
+ Load hình lên Label

-- Class (lớp)
-- Object (đối tượng) <-- Class
-- Property (thuộc tính) <-- Object


+ Lớp QString

1. Khởi tạo chuỗi: String str1, str2...	;
2. append và prepend.
3. toUpper và toLower..
4. các hàm lấy độ dài: size(), count() và length().
5. các hàm lấy chuỗi con: left(số_ký_tự), mid(vị_trí_bắt_đầu, số_ký_tự) và right(số_ký_tự).
6. duyệt chuỗi tìm thông tin.
7. so sánh chuỗi QString::compare()
8. chuyển đổi kiểu dữ liệu:  toInt(), toFloat(), toLong(), setNum()
9. kiểm tra dạng ký tự: isDigit(), isLetter(), isSpace()
10. edit chuỗi: remove, replace, clear





Thao tác cần làm khi load một widget ra giao diện layout
1. Đặt tên cho widget (pushButton_Exit, pushButton_Ok, label_HoTen, label_CoQuan....)
2. Thiết lập text cho widget
3. Thiết lập signal và slot cho widget

Buổi 3: Bài tập về nhà
Viết chức năng tự check vào radiobutton Nam khi chương trình chạy lên.
Viết chức năng cho listWidget
Load image và GraphicsView và Button




