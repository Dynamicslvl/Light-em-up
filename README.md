# Light-em-up
A C++ game using SFML

Type: Top-down puzzle

Idea:
  -Sử dụng định luật phản xạ ánh sáng để điều khiển ánh sáng đi đến mục tiêu
  
Functions:
  -isBoxCollision: kiểm tra va chạm giữa 2 hình vuông
  -point_distance: lấy khoảng cách giữa 2 điểm
  -point_direction: lấy góc giữa 2 điểm so với phương 0 độ (phía bên phải)
  -...
  
Classes:
  -MovableBlock: class sử dụng cho việc điều khiển các khối vuông di chuyển được
  -UnmovableBlock: class sử dụng cho tường
  
Future:
  -Tạo class: Light, ReflecBlock:protected MovableBlock, Target
  -Load sprites
  -Load sounds & musics
