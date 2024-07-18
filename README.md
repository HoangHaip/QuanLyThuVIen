# CTDL & GT - Giảng Viên: Nguyễn Duy Diệu 
Phạm Hoàng Hải - 2302700162
Trần Ngọc Hương Quế - 2302700252

Thư viện: Ta tổ chức các danh sách sau: 
- `Đầu sách` : danh sách tuyến tính là 1 mảng con trỏ (ISBN , Tên sách, Số trang, Tác giả, năm xuất bản, thể loại, con trỏ dms): con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng
- `Danh mục sách` : danh sách liên kết đơn( Mã sách,  trạng thái, vị trí (chuỗi)  ). Mỗi cuốn sách chỉ có 1 mã duy nhất; trạng thái của sách bao gồm: 0: cho mượn được, 1: đã có độc giả mượn, 2: sách đã thanh lý . 
- `Danh sách thẻ độc giả`: cây nhị phân tìm kiếm (MATHE (số nguyên ngẫu nhiên tự động), Ho, Ten,  Phai, trạng thái của thẻ, con trỏ): con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.
- `Danh sách MUONTRA` : danh sách liên kết kép ( MASACH,  NgayMuon, NgayTra, trạng thái): trạng thái =0 là sách đang mượn (chưa trả), =1 là đã trả, =2 : làm mất sách 

Chương trình có các chức năng sau: 
* a. Nhập thẻ độc giả: thêm / xóa / hiệu chỉnh thông tin thẻ độc giả. Mã thẻ độc giả được chương trình tự động lấy ngẫu nhiên và không trùng với các mã thẻ độc giả cũ; Phái chỉ nhận ‘Nam’ hoặc ‘Nữ’; trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động (được quyền mượn sách). 
* b. In danh sách độc giả : in ra màn hình theo thứ tự tên+họ tăng dần hoặc theo thứ tự mã độc giả tăng dần theo yêu cầu của thủ thư.
* c. Nhập thông tin đầu sách và đánh mã sách tự động
* d. In danh sách các đầu sách trong thư viện theo từng thể loại, trong từng thể loại thì in theo thứ tự tên sách tăng dần.
* e. Tìm thông tin sách dựa vào tên sách : in ra các thông tin mã ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách , trạng thái mã sách trong thư viện.
* f. Mượn sách : nhập vào mã thẻ độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn. Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (7 ngày)
* g. Trả sách : nhập vào mã độc giả
* h. Liệt kê danh sách các sách mà 1 độc giả đang mượn
* i. In danh sách độc giả mượn sách quá hạn theo thứ tự thời gian quá hạn giảm dần
* j. In 10 sách có số lượt mượn nhiều nhất.

# Cài đặt
Đồ án sử dụng thư viện giao diện winbgim.h, chạy trên IDE DevC++.
1. Cài đặt thư viện winbgim. [Xem hướng dẫn cài đặt tại đây](https://cachhoc.net/2013/10/03/cc-do-hoa-trong-dev-c/)
2. Tải về và giải nén source code.
3. Mở file `QuanLyThuVien.dev` bằng DevC++ và run project.

**Lưu ý:** Đồ án hiển thị trên màn hình Full HD (1920x1080), cỡ chữ 100%.

# Quá trình phát triển:
1. Thiết lặp giao diện:
   Để tránh việc mất thời gian chỉnh sửa vị trí trục tọa độ tung, hoành, chúng tôi xem xét việc chọn QT Designer hoặc Visual Studio để thiết kế giao diện và sau đó chuyển sang Dev C++.
   * a. Tạo file từ Visual Studio để thiết kế các nút từ kho ToolBox.
   * b. sau khi lưu file nó sẽ sản sinh mã nguồn của các thiết kế tương ứng và lấy các tọa độ cần thiết như trục tung, trục hoành, weight và height của các button nếu có.
   * c. Bên cạnh đó cần cài MingGW làm trình biên dịch cho DevC++ rồi chỉnh sửa sao cho phù hợp
2. Cấu trúc dữ liệu từng thành phần
   * a. Quản Lý đầu sách:
     Đoạn mã bạn đưa ra là một ví dụ về cách triển khai cấu trúc dữ liệu và các thao tác trong hệ thống quản lý sách, bao gồm:
   
      A. Cấu trúc dữ liệu
      
      Struct `DauSach`
      - **Mô tả**: Định nghĩa một cuốn sách với các thông tin như ISBN, tên sách, số trang, tác giả, nhà xuất bản, thể loại.
      - **Thuộc tính**:
        - `ISBN`: Mã số sách.
        - `tensach`: Tên sách.
        - `sotrang`: Số trang của sách.
        - `tacgia`: Tên tác giả.
        - `nxb`: Nhà xuất bản.
        - `theloai`: Thể loại sách.
        - `First`: Con trỏ đến danh sách liên kết các cuốn sách (node `NodeSach`).
        - `soluotmuon`: Số lượt mượn sách.
        - `soluong`: Số lượng sách có sẵn của đầu sách.
      
      Struct `DS_DauSach`
      - **Mô tả**: Lưu trữ danh sách các cuốn sách.
      - **Thuộc tính**:
        - `n`: Số lượng cuốn sách trong danh sách.
        - `nodes`: Mảng các con trỏ đến các đối tượng `DauSach`.
      
      B. Các hàm và thao tác
      
      Hàm `InsertDauSach`
      - **Mô tả**: Chèn một đầu sách vào vị trí `position` trong danh sách `DS_DauSach`.
      - **Tham số**:
        - `DSDS`: Tham chiếu đến danh sách `DS_DauSach`.
        - `dausach`: Con trỏ đến đối tượng `DauSach` cần chèn.
        - `position`: Vị trí cần chèn.
      - **Công việc**:
        - Di chuyển các phần tử sau vị trí `position` sang phải.
        - Chèn `dausach` vào vị trí `position`.
      
      Hàm `AddDauSach`
      - **Mô tả**: Thêm một đầu sách vào danh sách `DS_DauSach` theo thứ tự sắp xếp theo thể loại và tên sách.
      - **Tham số**:
        - `DSDS`: Tham chiếu đến danh sách `DS_DauSach`.
        - `dausach`: Con trỏ đến đối tượng `DauSach` cần thêm.
      - **Công việc**:
        - Duyệt qua danh sách để tìm vị trí thích hợp để chèn `dausach` sao cho danh sách vẫn được sắp xếp.
      
      Hàm `ExistsDauSach`
      - **Mô tả**: Kiểm tra xem một cuốn sách có tồn tại trong danh sách `DS_DauSach` hay không.
      - **Tham số**:
        - `DSDS`: Tham chiếu đến danh sách `DS_DauSach`.
        - `ISBN`: Mã số sách cần kiểm tra.
      - **Trả về**: Vị trí của cuốn sách trong danh sách nếu tồn tại, `-1` nếu không tồn tại.
      
      Các hàm khác
      - `UpdateDauSach`: Cập nhật thông tin của một cuốn sách trong danh sách.
      - `GetDauSach`, `GetIndexDauSach`: Tìm kiếm một cuốn sách trong danh sách theo `ISBN`.
      - `IsPrefix`: Kiểm tra xem một chuỗi có phải là tiền tố của chuỗi khác không.
      - `GetListNodes`: Lọc danh sách các cuốn sách có tên bắt đầu bằng `strFind`.
      - `TopSach`: Cấu trúc để thống kê và sắp xếp sách theo số lượt mượn.
      
      C. Giải thuật sử dụng
      
      - **Sắp xếp**: Sử dụng giải thuật QuickSort để sắp xếp danh sách các sách theo số lượt mượn.
      - **Tìm kiếm**: Sử dụng tìm kiếm tuần tự để tìm vị trí của cuốn sách theo `ISBN`.
      - **Chèn và xóa**: Đảm bảo các hoạt động chèn và xóa đối tượng `DauSach` trong danh sách `DS_DauSach` được thực hiện một cách hiệu quả và bảo toàn dữ liệu.
   * b. Quản Lý Độc Giả:

      A. Cấu trúc dữ liệu:
      Struct `DocGia`.
     
      - **Mô tả**: Định nghĩa một độc giả với các thông tin như mã thẻ, họ, tên, giới tính, trạng thái, và danh sách mượn/trả sách.
      - **Thuộc tính**:
      - `MATHE`: Mã thẻ độc giả.
      - `ho`: Họ của độc giả.
      - `ten`: Tên của độc giả.
      - `phai`: Giới tính (0: Nam, 1: Nữ).
      - `trangthai`: Trạng thái (0: Khóa, 1: Hoạt động).
      - `mt`: Danh sách mượn/trả sách.
     
      Struct `NodeDocGia`.
      - **Mô tả**: Nút của cây nhị phân tìm kiếm lưu trữ thông tin độc giả.
      - **Thuộc tính**:
      - `docgia`: Thông tin độc giả.
      - `left`: Con trỏ đến nút con trái.
      - `right`: Con trỏ đến nút con phải.
        
      Struct `DS_DocGia`.
      - **Mô tả**: Lưu trữ danh sách các độc giả.
      - **Thuộc tính**:
      - `n`: Số lượng độc giả trong danh sách.
      - `nodes`: Mảng các con trỏ đến các đối tượng `DocGia`.
      - `soNgayQH`: Số ngày quá hạn.
      - `mode`: Chế độ sắp xếp.

         
      B. Các giải thuật
      * Giải thuật Insertion (Thêm độc giả)

        
      **Hàm `InsertDocGia`**:
      - **Mô tả**: Chèn một độc giả vào cây nhị phân tìm kiếm.
      - **Tham số**:
        - `node`: Tham chiếu đến nút trong cây nhị phân.
        - `dg`: Thông tin độc giả cần chèn.
      - **Công việc**:
        1. Nếu `node` là NULL:
           - Tạo một `NodeDocGia` mới và gán nó cho `node`.
           - Khởi tạo các giá trị cho `node->docgia`, `node->left`, và `node->right`.
        2. Nếu `dg.MATHE` nhỏ hơn `node->docgia.MATHE`:
           - Gọi đệ quy hàm `InsertDocGia` với `node->left`.
        3. Nếu `dg.MATHE` lớn hơn `node->docgia.MATHE`:
           - Gọi đệ quy hàm `InsertDocGia` với `node->right`.

      * Giải thuật tìm kiếm

        
      **Hàm `SearchDocGia`**:
      - **Mô tả**: Tìm kiếm độc giả trong cây nhị phân tìm kiếm theo mã thẻ.
      - **Tham số**:
        - `treeDG`: Tham chiếu đến cây nhị phân.
        - `maDocGia`: Mã thẻ của độc giả cần tìm.
      - **Trả về**: Con trỏ đến nút chứa thông tin độc giả nếu tìm thấy, NULL nếu không tìm thấy.


      * Giải thuật xóa
  
        
      **Hàm `RemoveDocGia`**:
      - **Mô tả**: Xóa một độc giả khỏi cây nhị phân tìm kiếm theo mã thẻ.
      - **Tham số**:
        - `node`: Tham chiếu đến nút trong cây nhị phân.
        - `maDocGia`: Mã thẻ của độc giả cần xóa.
      - **Công việc**:
        1. Nếu `node` là NULL, in ra thông báo không thể xóa.
        2. Nếu `maDocGia` nhỏ hơn `node->docgia.MATHE`, gọi đệ quy `RemoveDocGia` với `node->left`.
        3. Nếu `maDocGia` lớn hơn `node->docgia.MATHE`, gọi đệ quy `RemoveDocGia` với `node->right`.
        4. Nếu `maDocGia` bằng `node->docgia.MATHE`, thực hiện các bước xóa nút và giải phóng bộ nhớ.


      * Giải thuật duyệt cây (In-Order Traversal)
  
        
      **Hàm `LNR`**:
      - **Mô tả**: Duyệt cây nhị phân theo thứ tự In-Order.
      - **Tham số**:
        - `node`: Tham chiếu đến nút trong cây nhị phân.
      - **Công việc**:
        1. Nếu `node` không phải NULL, thực hiện:
           - Gọi đệ quy `LNR` với `node->left`.
           - Lưu thông tin của `node->docgia` vào danh sách.
           - Gọi đệ quy `LNR` với `node->right`.

      * Giải thuật sắp xếp (Quicksort)
  
        
      **Hàm `Partition` và `Quicksort`**:
      - **Mô tả**: Sắp xếp danh sách độc giả sử dụng giải thuật Quicksort.
      - **Tham số**:
        - `low`, `high`: Các chỉ số đầu và cuối của danh sách cần sắp xếp.
      - **Công việc**:
        1. Chọn một phần tử làm pivot.
        2. Phân chia danh sách thành hai phần: phần nhỏ hơn và lớn hơn pivot.
        3. Gọi đệ quy `Partition` cho từng phần.
        4. Đổi chỗ các phần tử để đảm bảo danh sách được sắp xếp.

# Một số hình ảnh
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/dausach.png "Đầu sách")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/sach.png "Sách")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/docgia.png "Độc giả")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/ms.png "Mượn Sách")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/top.png "Top 10 Độc giả best seller")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/trangchu.png "Trang Chủ")
![alt text](https://github.com/HoangHaip/QuanLyThuVien/blob/main/pictures/info.png "Thông tin")



