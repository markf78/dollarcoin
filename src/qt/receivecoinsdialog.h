// Copyright (c) 2011-2013 The Bitcoin developers
// Copyright (c) 2013-2014 The Dollarcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RECEIVECOINSDIALOG_H
#define RECEIVECOINSDIALOG_H

#include <QDialog>
#include <QVariant>

namespace Ui {
    class ReceiveCoinsDialog;
}
class WalletModel;
class OptionsModel;

/** Dialog for requesting payment of bitcoins */
class ReceiveCoinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiveCoinsDialog(QWidget *parent = 0);
    ~ReceiveCoinsDialog();

    void setModel(WalletModel *model);

public slots:
    void clear();
    void reject();
    void accept();

private:
    Ui::ReceiveCoinsDialog *ui;
    WalletModel *model;

private slots:
    void on_receiveButton_clicked();
    void updateDisplayUnit();
};

#endif // RECEIVECOINSDIALOG_H
