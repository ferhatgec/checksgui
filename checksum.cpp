// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "checksum.h"
#include "ui_checksum.h"

#include <QGuiApplication>

checksum::checksum(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::checksum)
{
    this->clipboard = QGuiApplication::clipboard();
    this->ui->setupUi(this);
}

checksum::~checksum()
{
    delete this->ui;
}

void checksum::on_copy_button_clicked()
{
    this->clipboard->setText(this->ui->checksum_text->toPlainText());
}
