// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <QDialog>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui { class checksum; }
QT_END_NAMESPACE

class checksum : public QDialog
{
    Q_OBJECT

public:
    explicit checksum(QWidget *parent = nullptr);
    ~checksum();

    Ui::checksum* ui;
private slots:
    void on_copy_button_clicked();

private:
    QClipboard* clipboard;
};

#endif // CHECKSUM_H
