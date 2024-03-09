#include "cipher.h"
#include"qdebug.h"
Cipher::Cipher(QWidget *parent)
    :QWidget(parent)
{
    qDebug() <<"Cipher()";
}
Cipher::~Cipher()
{
    qDebug() <<"~Cipher()";
}

bool Cipher::is_true(const std::string &str)
{
    return password == str;
}

void Cipher::set(const std::string &str)
{
    password = str;
}

std::string Cipher::get()
{
    return password;
}
