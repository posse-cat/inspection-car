#ifndef IMAGE_WIDGET_H
#define IMAGE_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QImage>

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = nullptr);
    virtual ~CameraWidget() override;

    void showImage(bool b);      // show image in window
    void setImage(const QImage& img);     // update data
    void saveImage(); //acquire image in this widget

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap cvImage;                // 相机图像
    QPixmap gbImage;                // 窗口截取的图像
    QTimer *noShowCameraImage;      // 不显示图像定时器
    bool showCameraImage = true;    // 显示图像
    bool camerIsOpened = true;     // 相机打开

signals:

};

#endif // CAMERAWIDGET_H


