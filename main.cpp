#include  "modAlphaChip.h"

void check(const string& Text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        if (stoi(key) > 0) {
            modAlphaChip cipher(stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
            cout<<"key="<<key<<endl;
            cout<<"Encrypted text:  "<<cipherText<<endl;
            cout<<"Decrypted text:  "<<decryptedText<<endl;
        } else
            throw cipher_error(std::string("Invalid key ")+key);
    } catch (const cipher_error & e) {
        cerr<<"Error:  "<<e.what()<<endl;
    }
    cout<<""<<endl;
}

int main(int argc, char **argv)
{
    check ("SDR","");
    check ("MENIA","0");
    check ("INFORMATIKA", "7");
    check("I N F O R M A T I K A","7");
    check("585858","58");
}
