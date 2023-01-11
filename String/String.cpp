#include "String.h"

String::String(): pData(new char[1]), length(0)
{
    pData[0] = TERMINATOR;
}

String::String(const char *pC): length(findLength(pC))
{
    pData = new char[length + 1];
    for (int i = 0; i < length; i++)
        pData[i] = pC[i];
    pData[length] = TERMINATOR;
}

String::~String()
{
    delete []pData;
}

String::String(const String &rS)
{
    length = rS.getLength();
    pData = new char[length + 1];
    pData = copyData(rS);
    pData[length] = TERMINATOR;
}

String & String::operator=(const String &rS)
{
    if (this == &rS)
        return *this;
    delete []pData;
    length = rS.getLength();
    pData = new char[length + 1];
    pData = copyData(rS);
    pData[length] = TERMINATOR;
    return *this;
}

String & String::operator+=(const String &rS)
{
    *this = *this + rS;
    return *this;
}

String String::operator+(const String &rS)
{
    int copyLength = length + rS.getLength();
    char *pCopy = new char[copyLength + 1];
    for (int i = 0; i < length; i++)
        pCopy[i] = pData[i];
    for (int i = 0; i < copyLength - length; i++)
        pCopy[length + i] = rS[i];
    pCopy[copyLength] = TERMINATOR;
    String copy = pCopy;

    return copy;
}

bool String::operator==(const String &rS) const
{
    if (length != rS.getLength())
        return false;
    for (int i = 0; i < length; i++)
        if (pData[i] != rS[i])
            return false;
    return true;
}

const char * String::print() const
{
    return pData;
}

char & String::operator[](int i) const
{
    if (i > length)
        return pData[length];
    return pData[i];
}

int String::getLength() const
{
    return length;
}

void String::toUpper()
{
    for (int i = 0; i < length; i++)
        if (pData[i] >= 97 && pData[i] <= 122)
            pData[i] -= 32;
}

void String::toLower()
{
    for (int i = 0; i < length; i++)
        if (pData[i] >= 65 && pData[i] <= 90)
            pData[i] += 32;
}

char * String::copyData(const String &rS)
{
    int stringLength = rS.getLength();
    char *pCopy = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++)
	    pCopy[i] = rS[i];
    return pCopy;
}

int String::findLength(const char *pC)
{
    if (pC == nullptr)
        return 0;
    int i = 0;
    while (pC[i] != TERMINATOR)
        i++;
    return i;
}
