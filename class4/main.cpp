#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//=====第一题 Lena 任务=====
void task1_lena()
{
    // imread：读取lena图片，存入Mat对象
    Mat lena = imread("../assets/lena.jpg");
    if(lena.empty())
    {
        cout << "lena图片读取失败" << endl;
        return;
    }

    // clone：深度拷贝原图，用来画图，不破坏原始图像
    Mat mark_img = lena.clone();

    // 定义矩形区域
    Rect roi_rect(200,200,120,120);
    // ROI截取：直接引用原图内存（共享ROI）
    Mat roi_share = lena(roi_rect);
    // clone：得到独立副本，修改不会影响原图
    Mat roi_clone = roi_share.clone();

    // 在共享ROI区域填红色，用来观察共享特性
    roi_share.setTo(Scalar(0,0,255));

    // rectangle：绘制矩形框
    rectangle(mark_img, roi_rect, Scalar(0,255,0),2);

    // imwrite：保存带框原图
    imwrite("../results/lena_marked.png", mark_img);
    // imwrite：保存单独ROI截图
    imwrite("../results/lena_roi.png", roi_clone);

    cout << "Lena图像宽:" << lena.cols << "，高：" << lena.rows << "，通道数：" << lena.channels() << endl;
    cout << "步长：" << lena.step << endl;

    imshow("lena_marked", mark_img);
    imshow("lena_roi", roi_clone);
    waitKey(0);
    destroyAllWindows();
}

//=====第二题 硬币计数任务=====
void task2_coins()
{
    // imread：读取硬币图片
    Mat coins = imread("../assets/coins.png");
    if(coins.empty())
    {
        cout << "coins图片读取失败!" << endl;
        return;
    }

    Mat gray, binary;
    // cvtColor：转灰度图
    cvtColor(coins, gray, COLOR_BGR2GRAY);
    // threshold：二值化，阈值135
    threshold(gray, binary, 135, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    // findContours：寻找轮廓
    findContours(binary, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat draw_img = coins.clone();
    int count = 0;
    for(auto &cont : contours)
    {
        double area = contourArea(cont);
        // 筛选面积：250 ~ 8000
        if(area >= 250 && area <= 4000)
        {
            drawContours(draw_img, vector<vector<Point>>{cont}, 0, Scalar(0,255,0),2);
            count++;
        }
    }

    imwrite("../results/coins_binary.png", binary);
    imwrite("../results/coins_counted.png", draw_img);
    cout << "硬币数量：" << count << endl;

    imshow("coins_binary", binary);
    imshow("coins_counted", draw_img);
    waitKey(0);
    destroyAllWindows();
}

//=====第三题 数独透视矫正任务=====
void task3_sudoku()
{
    // imread：读取数独图片
    Mat sudoku = imread("../assets/sudoku.png");
    if(sudoku.empty())
    {
        cout << "sudoku图片读取失败！" << endl;
        return;
    }

    Mat point_img = sudoku.clone();
    // 题目给定4个源点顺序：左上、右上、右下、左下
    vector<Point2f> src_points = {
        Point2f(74, 85),
        Point2f(520, 50),
        Point2f(496, 516),
        Point2f(60, 520)
    };
    // 目标四点：450×450画布四角
    vector<Point2f> dst_points = {
        Point2f(0, 0),
        Point2f(449, 0),
        Point2f(449, 449),
        Point2f(0, 449)
    };

    // 画红点+编号
    for(int i=0;i<4;i++)
    {
        circle(point_img, src_points[i],5,Scalar(0,0,255),-1);
        putText(point_img, to_string(i+1), Point(src_points[i].x+8, src_points[i].y),
                FONT_HERSHEY_SIMPLEX,0.6,Scalar(0,0,255),1);
    }
    imwrite("../results/sudoku_points.png", point_img);

    // getPerspectiveTransform：计算透视矩阵
    Mat warp_mat = getPerspectiveTransform(src_points, dst_points);
    Mat corrected;
    // warpPerspective：执行透视变换
    warpPerspective(sudoku, corrected, warp_mat, Size(450,450));
    imwrite("../results/sudoku_corrected.png", corrected);

    cout << "矫正图宽：" << corrected.cols << "，高：" << corrected.rows << endl;

    imshow("sudoku_points", point_img);
    imshow("sudoku_corrected", corrected);
    waitKey(0);
    destroyAllWindows();
}

int main()
{
    task1_lena();
    task2_coins();
    task3_sudoku();
    return 0;
}