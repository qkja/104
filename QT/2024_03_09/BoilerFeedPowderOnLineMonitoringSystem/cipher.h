#ifndef CIPHER_H
#define CIPHER_H
#include <string>
#include <QWidget>
class Cipher :public QWidget
{
    Q_OBJECT
public:
   explicit Cipher(QWidget *parent = nullptr);
   ~Cipher();

   bool is_true(const std::string &str);
   void set(const std::string& str);
   std::string get();
private:
    std::string password;
};

#endif // CIPHER_H
