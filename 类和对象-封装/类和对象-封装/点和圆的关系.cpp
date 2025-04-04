#include <iostream>
using namespace std;
#include<string>
/*
设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。
与半径距离相比较
*/

//点和圆的关系
// 点类
class Point {
public: //行为设置为公共
    //设置x坐标
    void setX(int x) {
        m_X = x;
    }
    //获取x坐标
    int getX()
    {
        return m_X;
    }

    //设置y坐标
    void setY(int y) {
        m_Y = y;
    }
    //获取y坐标
    int getY()
    {
        return m_Y;
    }

private:  //建议类中的属性都设置为私有
    int m_X;
    int m_Y;

};
//圆类  类是抽象的模板（
// 定义“是什么，能做什么”）
class Circle {
public:    //行为设置为公共
//设置半径
    void setR(int r) {
        m_R = r;
}
 //获取半径
    int getR()
    {
        return m_R;
    }
//设置圆心
    void setCenter(Point center)
    {
        m_Center =  center;
    }
//获取圆心
    Point getCenter() {
        return m_Center;
    }

private:  //属性设置为私有
    int m_R; //半径
    // 在类中，可以让另一个类，作为本类的成员
    // 点类作为圆类的一个成员
    Point m_Center; //圆心  点类的数据类型
};

//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
    //计算两点之间的距离 平方 圆心和点的x、y坐标
    int distance =
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
        //计算半径的平方
        int rDistance = c.getR() * c.getR();

        //判断关系
        if (distance == rDistance) {
            cout << "点在圆上" << endl;
        }
        else if (distance > rDistance)
        {
            cout << "点在圆外" << endl;
        }
        else {
            cout << "点在圆内" << endl;
        }
}


int main7() {

    //实现是什么：对象是根据类创建的具体实体，
    // 是类的具体实现。
    //创建圆实例(对象）对象（Object）—具体实例
    Circle c;
    c.setR(10);
    //创建点实例 分为圆心这个点和三个其他点
    Point center;   //设置圆心实例
    center.setX(10);//圆心x 坐标
    center.setY(0); //圆心y 坐标
    //设置圆心，把坐标放圆心
    c.setCenter(center);
    
    //创建三个点的对象
    //对象是具体的实体
    // （根据模板创建，有实际数据）

    Point p1;
    p1.setX(10);
    p1.setY(0);

    Point p2;
    p2.setX(20);
    p2.setY(0);

    Point p3;
    p3.setX(21);
    p3.setY(0);
    //判断关系
    isInCircle(c, p1);
    isInCircle(c, p2);
    isInCircle(c, p3);


    system("pause");
    return 0;
}