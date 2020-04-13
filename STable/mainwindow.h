#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <QWidget>
#include "Source2_1.h"
#include <QDesktopWidget>
#include <math.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>
#include <QComboBox>
#include <QBarLegendMarker>
#include <QTableWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QTableWidget>
#include <QSlider>
#include <QLabel>
#include <QScrollArea>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QDebug>
#include <QComboBox>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/qchartview.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QValueAxis>
#include "stable.h"
QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout * topLayout;
    QVBoxLayout * leftLayout;
    QTableWidget * myTable;
    QComboBox * algorithm;
    QLabel * Quantum;
    QLineEdit * quantumValue;
    QPushButton * add;
    QPushButton * start;
    QPushButton * remove;
    QPushButton * reset;
    QTableWidget * ganttChart;
    QLabel * avgTime;
    QHorizontalStackedBarSeries *series;
    QChart *chart;
    QChartView *chartView;

    static int numOfUsedColors;
    QMap<int,QColor> ProcessColors;
    QVector<QColor> Palette;
    vector <vector<string> >data ;
    vector <vector<float>> result;
    void draw();
    QColor getAndAssignColor(int);
    void colorGenerator();
private slots:
    void on_add_clicked();
    void on_remove_clicked();
    void on_myTable_itemChanged(QTableWidgetItem *item);
    void on_start_clicked();
    void on_reset_clicked();
    void on_algorithm_change(int);
    void draw_ganttChart();
    void draw_chart();

};
#endif // MAINWINDOW_H
