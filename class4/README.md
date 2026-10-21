工程名：class4
环境：Ubuntu20.04，OpenCV 4.5.4
编译运行：
 
bash
  
cd build
cmake ..
make -j2
./homework
 
 
运行：弹出图片窗口后，点击窗口，按任意按键进入下一题。
 
基础题1 Lena、Mat与ROI
 
输出：lena_marked.png（512×512）、lena_roi.png（220×240）
参数：Rect(200,180,220,240)
现象：共享ROI会修改原图副本；clone后的ROI不会修改原图副本。通道顺序BGR。
 
基础题2 硬币计数
 
输出：coins_binary.png（384×303）、coins_counted.png（384×303）
参数：阈值135，THRESH_BINARY，RETR_EXTERNAL，面积250~4000
现象：不做面积筛选时，噪点和小块背景也会被识别成轮廓，统计数量偏大。统计结果24。
 
基础题3 透视矫正
 
输出：sudoku_points.png（558×563）、sudoku_corrected.png（450×450）
源点：(74,85)、(520,50)、(496,516)、(60,520)
目标点：(0,0)、(449,0)、(449,449)、(0,449)
现象：450尺寸图像有效像素下标范围是0~449。
 

自查
 
重新编译运行，所有图片均可正常读取、保存。
 
