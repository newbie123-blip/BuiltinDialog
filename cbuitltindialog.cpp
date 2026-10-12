#include "cbuitltindialog.h"
#include <QDebug>
#include <QString>

CBuitltinDialog::CBuitltinDialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit("QT內建對話盒示範"); //產生物件記憶體位址存在displayTextEdit變數中
    colorPushBtn = new QPushButton("顏色產生器");
    errorPushBtn = new QPushButton("錯誤訊息對話盒");
    filePushBtn = new QPushButton("檔案對話盒");
    fontPushBtn = new QPushButton("字體對話盒");
    inputPushBtn = new QPushButton("輸入對話框");
    pagePushBtn = new QPushButton("分頁設定對話框");
    progressPushBtn = new QPushButton("進度對話盒");
    printPushBtn = new QPushButton("列印對話盒");
    textcolorchange = new QPushButton("改變文字顏色");

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);
    gridLayout->addWidget(textcolorchange,2,2,1,1);

    setLayout(gridLayout);
    setWindowTitle("內建對話盒視窗示範");
    resize(400,300);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(textcolorchange,SIGNAL(clicked()),this,SLOT(doPushBtn()));
}

void CBuitltinDialog :: doPushBtn(){
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(btn == colorPushBtn)
    {
        QPalette palette = displayTextEdit->palette(); //調出物件所屬的調色盤物件
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Base),this,"選擇顏色");

        if(color.isValid())
        {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn == textcolorchange)
    {
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Base),this,"選擇顏色");

        if(color.isValid())
        {
            palette.setColor(QPalette::Text, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn == filePushBtn)
    {
        QString fileName =QFileDialog::getOpenFileName(this,"挑選",".","任何檔案(*.*);;文字檔(*.txt);;HTML檔(*.html)");
        displayTextEdit->setText(fileName);
        /*QString fileName = QFileDialog::getSaveFileName(this,"儲存檔案",".");
        displayTextEdit->setText(fileName);*/
    }
}

CBuitltinDialog::~CBuitltinDialog() = default;
