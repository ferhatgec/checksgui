// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "checksgui.h"
#include "./ui_checksgui.h"
#include "ui_checksum.h"

#include <QFile>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QGuiApplication>

checksgui::checksgui(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::checksgui)
{
    this->clipboard = QGuiApplication::clipboard();
    this->ui->setupUi(this);
}

checksgui::~checksgui()
{
    delete this->ui;
}

QString checksgui::checksum_file(const QString& file_name,
                                 QCryptographicHash::Algorithm algorithm) noexcept
{
    QFile sourceFile(file_name);
    qint64 fileSize = sourceFile.size();
    const qint64 bufferSize = 10240;

    if(sourceFile.open(QIODevice::ReadOnly))
    {
        char buffer[bufferSize];
        int bytesRead;
        int readSize = qMin(fileSize, bufferSize);

        QCryptographicHash hash(algorithm);

        while(readSize > 0 && (bytesRead = sourceFile.read(buffer, readSize)) > 0)
        {
            fileSize -= bytesRead;
            hash.addData(buffer, bytesRead);
            readSize = qMin(fileSize, bufferSize);
        }

        sourceFile.close();

        return QString(hash.result().toHex());
    }

    return QString("");
}

void checksgui::on_dialog_button_clicked()
{
    this->file_name = QFileDialog::getOpenFileName(nullptr,
                                                   QObject::tr("Open file"),
                                                   QDir::currentPath(),
                                                   QObject::tr("All files (*.*)"));

    this->setWindowTitle(QString("checksgui - %1").arg(this->file_name));

    if(!this->ui->md4_skip->isChecked())
        this->ui->md4_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Md4));

    if(!this->ui->md5_skip->isChecked())
        this->ui->md5_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Md5));

    if(!this->ui->sha1_skip->isChecked())
        this->ui->sha1_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha1));

    if(!this->ui->sha224_skip->isChecked())
        this->ui->sha224_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha224));

    if(!this->ui->sha256_skip->isChecked())
        this->ui->sha256_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha256));

    if(!this->ui->sha384_skip->isChecked())
        this->ui->sha384_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha384));

    if(!this->ui->sha512_skip->isChecked())
        this->ui->sha512_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha512));

    if(!this->ui->sha3_224_skip->isChecked())
        this->ui->sha3_224_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha3_224));

    if(!this->ui->sha3_256_skip->isChecked())
        this->ui->sha3_256_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha3_256));

    if(!this->ui->sha3_384_skip->isChecked())
        this->ui->sha3_384_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha3_384));

    if(!this->ui->sha3_512_skip->isChecked())
        this->ui->sha3_512_line->setText(this->checksum_file(this->file_name, QCryptographicHash::Sha3_512));
}


void checksgui::on_copy_md4_clicked()
{
    this->clipboard->setText(this->ui->md4_line->text());
}


void checksgui::on_copy_md5_clicked()
{
    this->clipboard->setText(this->ui->md5_line->text());
}


void checksgui::on_copy_sha1_clicked()
{
    this->clipboard->setText(this->ui->sha1_line->text());
}


void checksgui::on_copy_sha224_clicked()
{
    this->clipboard->setText(this->ui->sha224_line->text());
}


void checksgui::on_copy_sha256_clicked()
{
    this->clipboard->setText(this->ui->sha256_line->text());
}


void checksgui::on_copy_sha384_clicked()
{
    this->clipboard->setText(this->ui->sha384_line->text());
}


void checksgui::on_copy_sha512_clicked()
{
    this->clipboard->setText(this->ui->sha512_line->text());
}


void checksgui::on_copy_sha3_224_clicked()
{
    this->clipboard->setText(this->ui->sha3_224_line->text());
}


void checksgui::on_copy_sha3_256_clicked()
{
    this->clipboard->setText(this->ui->sha3_256_line->text());
}


void checksgui::on_copy_sha3_384_clicked()
{
    this->clipboard->setText(this->ui->sha3_384_line->text());
}


void checksgui::on_copy_sha3_512_clicked()
{
    this->clipboard->setText(this->ui->sha3_512_line->text());
}

void checksgui::on_copy_checksum_clicked()
{
    if(this->file_name.length() == 0)
    {
        return;
    }

    this->checksum_window.ui->checksum_text->setPlainText(QString("CHECKSUM of file '%1'\n"
                                                                  "\n"
                                                                  "MD4: %2\n"
                                                                  "MD5: %3\n"
                                                                  "SHA1: %4\n"
                                                                  "SHA224: %5\n"
                                                                  "SHA256: %6\n"
                                                                  "SHA384: %7\n"
                                                                  "SHA512: %8\n"
                                                                  "SHA3-224: %9\n"
                                                                  "SHA3-256: %10\n"
                                                                  "SHA3-384: %11\n"
                                                                  "SHA3-512: %12").arg(this->file_name,
                                                                                       this->ui->md4_line->text(),
                                                                                       this->ui->md5_line->text(),
                                                                                       this->ui->sha1_line->text(),
                                                                                       this->ui->sha224_line->text(),
                                                                                       this->ui->sha256_line->text(),
                                                                                       this->ui->sha384_line->text(),
                                                                                       this->ui->sha512_line->text(),
                                                                                       this->ui->sha3_224_line->text(),
                                                                                       this->ui->sha3_256_line->text(),
                                                                                       this->ui->sha3_384_line->text(),
                                                                                       this->ui->sha3_512_line->text()));
    this->checksum_window.show();
}

