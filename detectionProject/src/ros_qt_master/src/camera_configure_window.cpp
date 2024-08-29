#include <QtGui>
#include <QSettings>
#include "camera_configure_window.h"
#include "ui_camera_configure_window.h"

camera_configure_window::camera_configure_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::camera_configure_window)
{
    ui->setupUi(this);

    roi_region = new unsigned int[4];
    exposure = new float;
    gain=new float;

    *(roi_region+0)=0;      //offset_x
    *(roi_region+1)=0;      //offset_y
    *(roi_region+2)=4096;      //width
    *(roi_region+3)=3000;      //height

    *exposure = 5000.;
    *gain     = 0.;


    // init shape of slider
    init_shape_Slider_SpinBox();

    // init the value of QSlider and QDoubleSpinBox according to last setting
    init_setting_Slider_SpinBox();

    // harmonize between QSlider and QDoubleSpinBox
    makeVariantSimultaneous();

    // once value occur changing in any Slider,
    // we will send request to change the camera parameter.
    // QObject::connect(ui->horizontalSlider_imgsize,&QSlider::valueChanged,this,&camera_configure_window::changeCameraValue);
    // QObject::connect(ui->horizontalSlider_exposure,&QSlider::valueChanged,this,&camera_configure_window::changeCameraValue);
    // QObject::connect(ui->horizontalSlider_gain,&QSlider::valueChanged,this,&camera_configure_window::changeCameraValue);

    /*************************************
    *** sub_window close when main_window close
    **************************************/
   this->setAttribute(Qt::WA_QuitOnClose,false); 
}

camera_configure_window::~camera_configure_window()
{
    delete roi_region;
    delete exposure;
    delete gain;
    delete ui;
}

void camera_configure_window::saveCurrentParameterSettings()
{
    QSettings settings("config.ini", QSettings::IniFormat);

    settings.setValue("image_scale_factor",ui->spinBox_imgsize->value());
    settings.setValue("camera_exposure_time",ui->spinBox_exposure->value());
    settings.setValue("camera_gain_factor",ui->spinBox_gain->value());
}

void camera_configure_window::closeEvent(QCloseEvent *event)
{
    saveCurrentParameterSettings();

    QObject::disconnect(this);
    QMainWindow::closeEvent(event);
}

void camera_configure_window::init_shape_Slider_SpinBox()
{
    /*           part one: image scale factor ( ROI )            */
    ui->horizontalSlider_imgsize->setRange(0, 100);
    ui->horizontalSlider_imgsize->setSingleStep(1); // 设置步长为1
    ui->horizontalSlider_imgsize->setPageStep(10);

    ui->spinBox_imgsize->setRange(0, 100);
    ui->spinBox_imgsize->setSingleStep(1);
    ui->spinBox_imgsize->setSuffix("%");         //设置后缀名称
    ui->spinBox_imgsize->setSpecialValueText(tr("No-Image-Show"));

    /*              part two: exposure time ( /ms )              */
    ui->horizontalSlider_exposure->setRange(1000,20000);
    ui->horizontalSlider_exposure->setSingleStep(1); // 设置步长为1ms
    ui->horizontalSlider_exposure->setPageStep(10);

    ui->spinBox_exposure->setRange(1000,20000);
    ui->spinBox_exposure->setSingleStep(1);
    ui->spinBox_exposure->setSuffix("us");

    /*              part three: gain factor              */
    ui->horizontalSlider_gain->setRange(0,100);
    ui->horizontalSlider_gain->setSingleStep(1);
    ui->horizontalSlider_gain->setPageStep(10);

    ui->spinBox_gain->setRange(0.,1.);
    ui->spinBox_gain->setSingleStep(0.1);
}

void camera_configure_window::init_setting_Slider_SpinBox()
{
    QSettings settings("config.ini", QSettings::IniFormat);

    double image_scale_factor = settings.value("image_scale_factor",100).toInt();
    double camera_exposure_time = settings.value("camera_exposure_time",5000.).toInt();
    double camera_gain_factor = settings.value("camera_gain_factor",0.0).toDouble();

    ui->horizontalSlider_imgsize->setValue(int(image_scale_factor));
    ui->spinBox_imgsize->setValue(image_scale_factor);

    ui->horizontalSlider_exposure->setValue(int(camera_exposure_time));
    ui->spinBox_exposure->setValue(camera_exposure_time);

    ui->horizontalSlider_gain->setValue(int(camera_gain_factor*100));
    ui->spinBox_gain->setValue(camera_gain_factor);
}

void camera_configure_window::makeVariantSimultaneous()
{
    /*           part one: image size            */
    //QSlider移动 QSpinBox跟着移动
    QObject::connect(ui->horizontalSlider_imgsize,&QSlider::valueChanged,ui->spinBox_imgsize,&QDoubleSpinBox::setValue);
    //QSpinBox移动 QSlider跟着移动
    void(QDoubleSpinBox:: *spinSignal_img)(double)=&QDoubleSpinBox::valueChanged;//通过函数指针确定所用重载函数
    QObject::connect(ui->spinBox_imgsize,spinSignal_img,ui->horizontalSlider_imgsize,&QSlider::setValue);

    /*           part two: exposure time            */
    QObject::connect(ui->horizontalSlider_exposure,&QSlider::valueChanged,ui->spinBox_exposure,&QDoubleSpinBox::setValue);
    void(QDoubleSpinBox:: *spinSignal_ept)(double)=&QDoubleSpinBox::valueChanged;//通过函数指针确定所用重载函数
    QObject::connect(ui->spinBox_exposure,spinSignal_ept,ui->horizontalSlider_exposure,&QSlider::setValue);

    /*           part three: gain factor            */
    //这里涉及到spinBox 和 slider 控件之间的值不一致，需要经过自行进行值之间的转化
    // measurement from slider to spinBox
    QObject::connect(ui->horizontalSlider_gain,&QSlider::valueChanged,this,&camera_configure_window::measurement_slider2spinBox);
    QObject::connect(this,&camera_configure_window::slider2spinBox,ui->spinBox_gain,&QDoubleSpinBox::setValue);
    // measurement from spinBox to slider
    void(QDoubleSpinBox:: *spinSignal_gain)(double)=&QDoubleSpinBox::valueChanged;//通过函数指针确定所用重载函数
    QObject::connect(ui->spinBox_gain,spinSignal_gain,this,&camera_configure_window::measurement_spinBox2slider);
    QObject::connect(this,&camera_configure_window::spinBox2slider,ui->horizontalSlider_gain,&QSlider::setValue);
    /*
    QObject::connect(ui->horizontalSlider_gain,&QSlider::valueChanged,ui->spinBox_gain,&QDoubleSpinBox::setValue);
    void(QDoubleSpinBox:: *spinSignal_gain)(double)=&QDoubleSpinBox::valueChanged;//通过函数指针确定所用重载函数
    QObject::connect(ui->spinBox_gain,spinSignal_gain,ui->horizontalSlider_gain,&QSlider::setValue);
    */
}

void camera_configure_window::measurement_slider2spinBox(int source)
{
    double target;
    target = double(source/100.);
    Q_EMIT this->slider2spinBox(target);
}

void camera_configure_window::measurement_spinBox2slider(double source)
{
    int target;
    target = int(source*100);
    Q_EMIT this->spinBox2slider(target);
}

double camera_configure_window::getImageScaleFactor()
{
    return ui->spinBox_imgsize->value();
}

double camera_configure_window::getExposureTime()
{
    return ui->spinBox_exposure->value();
}

double camera_configure_window::getGainFactor()
{
    return ui->spinBox_gain->value();
}

void camera_configure_window::on_pushButton_returnMain_pressed()
{    
    this->close();
}

void camera_configure_window::on_pushButton_OK_pressed()
{
    this->changeCameraValue();
}

void camera_configure_window::changeCameraValue()
{
    unsigned int sub_w,sub_h;
    //在C++中，将不同类型转换为unsigned int可以使用类型转换（cast）操作。 --来自AI搜索
    sub_w=static_cast<unsigned int>(IMAGE_WIDTH * ui->spinBox_imgsize->value()/100.);
    sub_h=static_cast<unsigned int>(IMAGE_HEIGHT * ui->spinBox_imgsize->value()/100.);

    *(roi_region+0)=static_cast<unsigned int>((IMAGE_WIDTH-sub_w)/2);      //offset_x
    *(roi_region+1)=static_cast<unsigned int>((IMAGE_HEIGHT-sub_h)/2);      //offset_y
    *(roi_region+2)=sub_w;      //width
    *(roi_region+3)=sub_h;      //height

    *exposure = float(ui->spinBox_exposure->value());
    *gain     = float(ui->spinBox_gain->value());

    Q_EMIT camera_conf(roi_region,exposure,gain);
}





