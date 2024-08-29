/********************************************************************************
** Form generated from reading UI file 'camera_configure_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_CONFIGURE_WINDOW_H
#define UI_CAMERA_CONFIGURE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera_configure_window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSlider *horizontalSlider_exposure;
    QSlider *horizontalSlider_gain;
    QSlider *horizontalSlider_imgsize;
    QPushButton *pushButton_returnMain;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *spinBox_imgsize;
    QDoubleSpinBox *spinBox_exposure;
    QDoubleSpinBox *spinBox_gain;
    QPushButton *pushButton_OK;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *camera_configure_window)
    {
        if (camera_configure_window->objectName().isEmpty())
            camera_configure_window->setObjectName(QString::fromUtf8("camera_configure_window"));
        camera_configure_window->resize(655, 577);
        centralwidget = new QWidget(camera_configure_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalSlider_exposure = new QSlider(centralwidget);
        horizontalSlider_exposure->setObjectName(QString::fromUtf8("horizontalSlider_exposure"));
        horizontalSlider_exposure->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_exposure, 1, 1, 1, 1);

        horizontalSlider_gain = new QSlider(centralwidget);
        horizontalSlider_gain->setObjectName(QString::fromUtf8("horizontalSlider_gain"));
        horizontalSlider_gain->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_gain, 2, 1, 1, 1);

        horizontalSlider_imgsize = new QSlider(centralwidget);
        horizontalSlider_imgsize->setObjectName(QString::fromUtf8("horizontalSlider_imgsize"));
        horizontalSlider_imgsize->setMaximum(1);
        horizontalSlider_imgsize->setSingleStep(1);
        horizontalSlider_imgsize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_imgsize, 0, 1, 1, 1);

        pushButton_returnMain = new QPushButton(centralwidget);
        pushButton_returnMain->setObjectName(QString::fromUtf8("pushButton_returnMain"));

        gridLayout->addWidget(pushButton_returnMain, 3, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_imgsize = new QDoubleSpinBox(centralwidget);
        spinBox_imgsize->setObjectName(QString::fromUtf8("spinBox_imgsize"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox_imgsize->sizePolicy().hasHeightForWidth());
        spinBox_imgsize->setSizePolicy(sizePolicy);
        spinBox_imgsize->setMinimumSize(QSize(98, 26));
        spinBox_imgsize->setMaximumSize(QSize(99, 26));

        gridLayout->addWidget(spinBox_imgsize, 0, 2, 1, 1);

        spinBox_exposure = new QDoubleSpinBox(centralwidget);
        spinBox_exposure->setObjectName(QString::fromUtf8("spinBox_exposure"));

        gridLayout->addWidget(spinBox_exposure, 1, 2, 1, 1);

        spinBox_gain = new QDoubleSpinBox(centralwidget);
        spinBox_gain->setObjectName(QString::fromUtf8("spinBox_gain"));

        gridLayout->addWidget(spinBox_gain, 2, 2, 1, 1);

        pushButton_OK = new QPushButton(centralwidget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        gridLayout->addWidget(pushButton_OK, 3, 1, 1, 1);

        camera_configure_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(camera_configure_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 655, 32));
        camera_configure_window->setMenuBar(menubar);
        statusbar = new QStatusBar(camera_configure_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        camera_configure_window->setStatusBar(statusbar);

        retranslateUi(camera_configure_window);

        QMetaObject::connectSlotsByName(camera_configure_window);
    } // setupUi

    void retranslateUi(QMainWindow *camera_configure_window)
    {
        camera_configure_window->setWindowTitle(QApplication::translate("camera_configure_window", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("camera_configure_window", "\345\242\236\347\233\212\345\233\240\345\255\220\357\274\232", nullptr));
        pushButton_returnMain->setText(QApplication::translate("camera_configure_window", "\350\277\224\345\233\236\344\270\273\351\241\265\351\235\242", nullptr));
        label->setText(QApplication::translate("camera_configure_window", "\345\233\276\345\203\217\347\274\251\346\224\276\357\274\232", nullptr));
        label_2->setText(QApplication::translate("camera_configure_window", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", nullptr));
        pushButton_OK->setText(QApplication::translate("camera_configure_window", "\347\241\256\350\256\244\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class camera_configure_window: public Ui_camera_configure_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_CONFIGURE_WINDOW_H
