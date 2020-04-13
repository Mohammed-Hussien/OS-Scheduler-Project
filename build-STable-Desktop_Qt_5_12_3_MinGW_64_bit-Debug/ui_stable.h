/********************************************************************************
** Form generated from reading UI file 'stable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STABLE_H
#define UI_STABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_STable
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QGroupBox *data;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *Priority;
    QRadioButton *SJF;
    QRadioButton *RR;
    QRadioButton *FCFS;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *pre;
    QSpacerItem *verticalSpacer_3;
    QRadioButton *nonpre;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *STable)
    {
        if (STable->objectName().isEmpty())
            STable->setObjectName(QString::fromUtf8("STable"));
        STable->resize(1123, 680);
        STable->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"border: 2px solid red;\n"
"background-color:yellow;\n"
"border-color: skyblue;\n"
"font-size: 14px;\n"
"border-radius: 15px;\n"
" margin-top: 2ex; /* leave space at the top for the title */\n"
"\n"
"}\n"
"QGroupBox::title {\n"
"color:red;\n"
"padding-top:-10px;\n"
"  padding-left:2px;\n"
"\n"
"}"));
        pushButton = new QPushButton(STable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(710, 390, 75, 23));
        tableWidget = new QTableWidget(STable);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(600, 28, 501, 341));
        data = new QGroupBox(STable);
        data->setObjectName(QString::fromUtf8("data"));
        data->setGeometry(QRect(20, 20, 561, 391));
        layoutWidget = new QWidget(data);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 531, 341));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 221, 281));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Priority = new QRadioButton(widget);
        Priority->setObjectName(QString::fromUtf8("Priority"));

        verticalLayout->addWidget(Priority);

        SJF = new QRadioButton(widget);
        SJF->setObjectName(QString::fromUtf8("SJF"));

        verticalLayout->addWidget(SJF);

        RR = new QRadioButton(widget);
        RR->setObjectName(QString::fromUtf8("RR"));

        verticalLayout->addWidget(RR);

        FCFS = new QRadioButton(widget);
        FCFS->setObjectName(QString::fromUtf8("FCFS"));

        verticalLayout->addWidget(FCFS);


        verticalLayout_3->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 31, 221, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pre = new QRadioButton(layoutWidget1);
        pre->setObjectName(QString::fromUtf8("pre"));

        verticalLayout_2->addWidget(pre);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        nonpre = new QRadioButton(layoutWidget1);
        nonpre->setObjectName(QString::fromUtf8("nonpre"));

        verticalLayout_2->addWidget(nonpre);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(STable);
        QObject::connect(RR, SIGNAL(toggled(bool)), lineEdit, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(STable);
    } // setupUi

    void retranslateUi(QDialog *STable)
    {
        STable->setWindowTitle(QApplication::translate("STable", "STable", nullptr));
        pushButton->setText(QApplication::translate("STable", "Add Process", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("STable", "PID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("STable", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("STable", "Burst Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("STable", "Priority", nullptr));
        data->setTitle(QApplication::translate("STable", "data", nullptr));
        groupBox_3->setTitle(QApplication::translate("STable", "Algorithm", nullptr));
        Priority->setText(QApplication::translate("STable", "Priority", nullptr));
        SJF->setText(QApplication::translate("STable", "SJF", nullptr));
        RR->setText(QApplication::translate("STable", "RR", nullptr));
        FCFS->setText(QApplication::translate("STable", "FCFS", nullptr));
        pushButton_2->setText(QApplication::translate("STable", "start", nullptr));
        groupBox_2->setTitle(QApplication::translate("STable", "Settings", nullptr));
        pre->setText(QApplication::translate("STable", "Preemtive", nullptr));
        nonpre->setText(QApplication::translate("STable", "non-preemtive", nullptr));
        label->setText(QApplication::translate("STable", "time slice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class STable: public Ui_STable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STABLE_H
