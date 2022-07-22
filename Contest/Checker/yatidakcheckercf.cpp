#include "testlib.h"
 
std::string upper(std::string sa)
{
    for (size_t i = 0; i < sa.length(); i++)
        if ('a' <= sa[i] && sa[i] <= 'z')
            sa[i] = sa[i] - 'a' + 'A';
    return sa;
}
 
int main(int argc, char * argv[])
{
    setName("YA atau TIDAK (case insensetive)");
    registerTestlibCmd(argc, argv);
 
    std::string ja = upper(ans.readWord());
    std::string pa = upper(ouf.readWord());
 
    if (pa != "YA" && pa != "TIDAK")
        quitf(_pe, "Diharapkan YA atau TIDAK, namun ditemukan %s", pa.c_str());
 
    if (ja != "YA" && ja != "TIDAK")
        quitf(_fail, "Diharapkan YA atau TIDAK, namun ditemukan %s", ja.c_str());
 
    if (ja != pa)
        quitf(_wa, "diharapkan %s, ditemukan %s", ja.c_str(), pa.c_str());
 
    quitf(_ok, "jawaban adalah %s", ja.c_str());
}


