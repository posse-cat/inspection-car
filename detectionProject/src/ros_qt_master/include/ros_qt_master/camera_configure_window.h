#ifndef CAMERA_CONFIGURE_WINDOW_H
#define CAMERA_CONFIGURE_WINDOW_H

#define IMAGE_WIDTH 4096
#define IMAGE_HEIGHT 3000

#include <QMainWindow>

namespace Ui {
class camera_configure_window;
}

class camera_configure_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit camera_configure_window(QWidget *parent = nullptr);
    ~camera_configure_window();

    void saveCurrentParameterSettings();
    void closeEvent(QCloseEvent *event); // Overloaded function

    void init_shape_Slider_SpinBox();
    void init_setting_Slider_SpinBox();
    void makeVariantSimultaneous();
    void measurement_slider2spinBox(int);
    void measurement_spinBox2slider(double);

    double getImageScaleFactor();
    double getExposureTime();
    double getGainFactor();

    void changeCameraValue();

signals:
    void camera_conf(unsigned int *,float*,float*);
    void slider2spinBox(double);
    void spinBox2slider(int);

public Q_SLOTS:

    void on_pushButton_returnMain_pressed();
    void on_pushButton_OK_pressed();

private:
    Ui::camera_configure_window *ui;

    //https://blog.csdn.net/l2014010671/article/details/104467958
    //https://blog.csdn.net/jsjgogogo/article/details/115491301
    unsigned int *roi_region;
    float *gain;
    float *exposure;
};

#endif // CAMERA_CONFIGURE_WINDOW_H
