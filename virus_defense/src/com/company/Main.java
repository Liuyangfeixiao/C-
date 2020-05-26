package com.company;

import javax.swing.*;

public class Main {

    public static void main(String[] args) {
        // 制作一个窗口
        JFrame frame = new JFrame();
        //设置窗口大小
        frame.setSize(1100, 800);
        //设置标题
        frame.setTitle("virus_defense");
        //设置窗口屏幕在正中间
        frame.setLocationRelativeTo(null);
        //设置窗口的默认关闭按钮
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //添加一个面板对象。用于绘图
        MainPanel panel = new MainPanel();
        //添加面板到窗口
        frame.add(panel);
        //显示窗口
        frame.setVisible(true);


        //创建新线程
        Thread t = new Thread(panel);
        t.start();
    }
}
