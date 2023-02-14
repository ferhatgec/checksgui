// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef CHECKSGUI_H
#define CHECKSGUI_H

#include <QMainWindow>
#include <QClipboard>
#include <QCryptographicHash>

#include "checksum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class checksgui; }
QT_END_NAMESPACE

class checksgui : public QMainWindow
{
    Q_OBJECT

public:
    checksgui(QWidget *parent = nullptr);

    ~checksgui();

    QString checksum_file(const QString& file_name,
                          QCryptographicHash::Algorithm type) noexcept;
private slots:
    void on_dialog_button_clicked();

    void on_copy_md4_clicked();

    void on_copy_sha512_clicked();

    void on_copy_md5_clicked();

    void on_copy_sha1_clicked();

    void on_copy_sha224_clicked();

    void on_copy_sha256_clicked();

    void on_copy_sha384_clicked();

    void on_copy_sha3_224_clicked();

    void on_copy_sha3_256_clicked();

    void on_copy_sha3_384_clicked();

    void on_copy_sha3_512_clicked();

    void on_copy_checksum_clicked();

private:
    Ui::checksgui* ui;
    checksum checksum_window;

    QString file_name;
    QClipboard* clipboard;
};

#endif // CHECKSGUI_H
