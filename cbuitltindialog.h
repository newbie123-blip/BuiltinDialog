#ifndef CBUITLTINDIALOG_H
#define CBUITLTINDIALOG_H

#include <QDialog>
#include <QtWidgets>

class CBuitltinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CBuitltinDialog(QWidget *parent = nullptr);
    ~CBuitltinDialog() override;
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* fontPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
    QPushButton* textcolorchange;
private slots:
    void doPushBtn();
};
#endif // CBUITLTINDIALOG_H
