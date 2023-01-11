#ifndef STRING_H
#define STRING_H

class String
{
    public:
        String();
        ~String();
        String(const char *pC);
        String(const String &rS);
        String & operator=(const String &rS);
        String & operator+=(const String &rS);

        String operator+(const String &rS);
        bool operator==(const String &rS) const;

        /// @brief Converts string to char array
        /// @return Pointer to String as char array
        const char * print() const;
        char & operator[](int i) const;
        /// @brief Length of text in String
        /// @return Length of String excluding NULL terminator
        int getLength() const;

        /// @brief Changes all letters to uppercase
        void toUpper();
        /// @brief Changes all letters to lowercase
        void toLower();

    private:
        static const char TERMINATOR = '\0';
        char *pData;
        int length;     //Length of String excluding NULL terminator

        /// @brief Copies pData from rS
        /// @param rS String to copy data from
        /// @return Pointer to new char array copy of rS->pData
        char * copyData(const String &rS);

        /// @brief Finds length of char array pC
        /// @param pC Char array to find length of
        /// @return Length of pC as an int
        int findLength(const char *pC);
};

#endif
