const char* declension(int num, const char* str1, const char* str2,
                       const char* str3)
{
    if (num >= 10 && num <= 19)
    {
        return str3;
    }

    int mod = num % 10;

    if (mod == 1)
    {
        return str1;
    }

    if (mod >= 2 && mod <= 4)
    {
        return str2;
    }

    return str3;
}