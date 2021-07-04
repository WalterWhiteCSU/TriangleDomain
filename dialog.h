//
// Created by WalterWhite on 2021/6/22.
//

#ifndef TRIANGLEDOMAIN_DIALOG_H
#define TRIANGLEDOMAIN_DIALOG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QWidget {
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

private:
    Ui::Dialog *ui;
};


#endif //TRIANGLEDOMAIN_DIALOG_H
