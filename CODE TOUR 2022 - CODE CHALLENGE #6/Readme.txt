Jimmy and Lucky Money
Tết năm nay Jimmy được rất nhiều người mừng tuổi bằng những phong bao có chứa những tờ tiền với các mệnh giá khác nhau. Jimmy muốn xếp tiền vào ví sao cho các tờ tiền luôn tăng dần theo giá trị của chúng.

Giả sử ví của Jimmy là một mảng AA không giảm và các giá trị của AA là mệnh giá tương ứng của các tờ tiền theo thứ tự. Ví của Jimmy luôn trong trạng thái các tờ tiền tăng dần theo giá trị. Ví dụ, mảng AA có thể là [1, 2, 5][1,2,5] hoặc [1, 1, 2, 5, 5][1,1,2,5,5] nhưng không thể là [1, 5, 2][1,5,2].

Có QQ bao lì xì, mỗi bao chứa những tờ tiền có mệnh giá tăng dần. Jimmy lần lượt xếp từng bao lì xì vào ví theo thứ tự từ bao lì xì thứ 11 đến bao lì xì thứ QQ. Để sắp xếp những bao lì xì vào trong ví, các thao tác Jimmy có thể làm bao gồm:

Bỏ cả xấp tiền trong bao lì xì đang cầm vào một vị trí bất kì trong ví
Lấy ra bất kì một số tờ tiền cạnh nhau trong ví (giữ nguyên thứ tự) và đặt xấp tiền vừa lấy ra vào lại một vị trí bất kì trong ví.
Sau mỗi lần xếp bao lì xì vào ví thì cần thực hiện các thao tác sao cho giá trị các tờ tiền trong ví phải luôn không giảm.

Chẳng hạn, ví của Jimmy ban đầu là [1, 2, 2, 5][1,2,2,5] và bao lì xì cần xếp vào ví có chứa các tờ tiền mệnh giá lần lượt là [2, 5, 10][2,5,10]. Một trong những giải pháp tối ưu sẽ là để bao lì xì này vào vị trí sau cùng của ví, tức ví của Jimmy lúc này sẽ là [1, 2, 2, 5, 2, 5, 10][1,2,2,5,2,5,10], sau đó chuyển tờ tiền giá trị 55 ở vị trí thứ 33 về đúng vị trí của nó. Tổng số thao tác là 22.

Với bao lì xì thứ ii (1 \le i \le Q)(1≤i≤Q), Jimmy muốn tìm số lượng thao tác ít nhất để xếp bao lì xì thứ ii vào ví sao cho giá trị các tờ tiền trong ví luôn không giảm.

Lưu ý: ví của Jimmy SẼ THAY ĐỔI sau mỗi lần sắp xếp.

Ban đầu, ví của Jimmy không chứa bất kì tờ tiền nào.


input
2
4 1 2 2 5
3 2 5 10

output
1
2

Giải thích ví dụ
Ở ví dụ phía trên, Jimmy có 22 bao lì xì [1,2,2,5][1,2,2,5] và [2,5,10][2,5,10].

Để xếp tiền ở bao lì xì 11 vào ví, Jimmy cần đúng duy nhất 1 thao tác là lấy tất cả tờ tiền bỏ vào ví.
Tiếp theo, lúc này ví của Jimmy đã có các tờ tiền [1,2,2,5][1,2,2,5], Jimmy thực hiện tương tự các thao tác phía trên đề bài. Lần này Jimmy tốn 2 thao tác để sắp xếp bao lì xì thứ 2 vào trong ví.