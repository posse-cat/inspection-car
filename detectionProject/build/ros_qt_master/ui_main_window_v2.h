/********************************************************************************
** Form generated from reading UI file 'main_window_v2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_V2_H
#define UI_MAIN_WINDOW_V2_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <image_widget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *action_img_streaming;
    QAction *action_img_save;
    QAction *action_img_stop;
    QAction *action_para_config;
    QAction *action_denoise;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    CameraWidget *image_widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QListView *view_logging;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QCheckBox *checkbox_remember_settings;
    QLabel *label_1;
    QLineEdit *line_edit_host;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_connect;
    QCheckBox *checkbox_use_environment;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_save;
    CameraWidget *front_view;
    QWidget *track_view;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(944, 729);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowDesign->sizePolicy().hasHeightForWidth());
        MainWindowDesign->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        action_img_streaming = new QAction(MainWindowDesign);
        action_img_streaming->setObjectName(QString::fromUtf8("action_img_streaming"));
        action_img_save = new QAction(MainWindowDesign);
        action_img_save->setObjectName(QString::fromUtf8("action_img_save"));
        action_img_stop = new QAction(MainWindowDesign);
        action_img_stop->setObjectName(QString::fromUtf8("action_img_stop"));
        action_para_config = new QAction(MainWindowDesign);
        action_para_config->setObjectName(QString::fromUtf8("action_para_config"));
        action_denoise = new QAction(MainWindowDesign);
        action_denoise->setObjectName(QString::fromUtf8("action_denoise"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        image_widget = new CameraWidget(centralwidget);
        image_widget->setObjectName(QString::fromUtf8("image_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(8);
        sizePolicy2.setHeightForWidth(image_widget->sizePolicy().hasHeightForWidth());
        image_widget->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(image_widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        view_logging = new QListView(centralwidget);
        view_logging->setObjectName(QString::fromUtf8("view_logging"));
        view_logging->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(view_logging->sizePolicy().hasHeightForWidth());
        view_logging->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(view_logging);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkbox_remember_settings = new QCheckBox(groupBox_2);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 5, 0, 1, 2);

        label_1 = new QLabel(groupBox_2);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setFrameShape(QFrame::StyledPanel);
        label_1->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        line_edit_host = new QLineEdit(groupBox_2);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(170, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 0, 1, 1);

        button_connect = new QPushButton(groupBox_2);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(button_connect, 7, 1, 1, 1);

        checkbox_use_environment = new QCheckBox(groupBox_2);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 4, 0, 1, 2);

        line_edit_master = new QLineEdit(groupBox_2);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy5);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_start = new QPushButton(groupBox_3);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        gridLayout_2->addWidget(pushButton_start, 1, 0, 1, 2);

        pushButton_stop = new QPushButton(groupBox_3);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout_2->addWidget(pushButton_stop, 2, 1, 1, 1);

        pushButton_save = new QPushButton(groupBox_3);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(pushButton_save, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        front_view = new CameraWidget(centralwidget);
        front_view->setObjectName(QString::fromUtf8("front_view"));

        verticalLayout_2->addWidget(front_view);

        track_view = new QWidget(centralwidget);
        track_view->setObjectName(QString::fromUtf8("track_view"));

        verticalLayout_2->addWidget(track_view);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 8);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 28));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindowDesign);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindowDesign->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_img_streaming);
        toolBar->addAction(action_img_stop);
        toolBar->addAction(action_img_save);
        toolBar->addAction(action_para_config);
        toolBar->addAction(action_denoise);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", nullptr));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        action_img_streaming->setText(QApplication::translate("MainWindowDesign", "\347\233\270\346\234\272\345\217\226\346\265\201", nullptr));
        action_img_save->setText(QApplication::translate("MainWindowDesign", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        action_img_stop->setText(QApplication::translate("MainWindowDesign", "\346\232\202\345\201\234\351\207\207\351\233\206", nullptr));
        action_para_config->setText(QApplication::translate("MainWindowDesign", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
#ifndef QT_NO_TOOLTIP
        action_para_config->setToolTip(QApplication::translate("MainWindowDesign", "\351\205\215\347\275\256\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
        action_denoise->setText(QApplication::translate("MainWindowDesign", "\345\233\276\345\203\217\345\216\273\345\231\252", nullptr));
        label_5->setText(QApplication::translate("MainWindowDesign", "Image Show--->>", nullptr));
        label->setText(QApplication::translate("MainWindowDesign", "Messages --->>", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", nullptr));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings", nullptr));
        label_1->setText(QApplication::translate("MainWindowDesign", "Ros Master Url", nullptr));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", nullptr));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", nullptr));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", nullptr));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Auto select master", nullptr));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", nullptr));
        label_2->setText(QApplication::translate("MainWindowDesign", "Ros IP", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindowDesign", "Manipulation", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindowDesign", "Camera Streaming", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindowDesign", "Stop", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindowDesign", "Save", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindowDesign", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_V2_H
