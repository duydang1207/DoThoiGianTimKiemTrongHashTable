#include "algorithms.h"


void RandomStringGenerator(string code[], int codeLength)
{
    string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
    int boxLength = box.length();
    for (int i = 0; i < codeLength; i++)
    {
        code[0] = code[0] + box[rand() % boxLength];
    }
}

void sinh(string url[])
{
    int k = 1;
    int r = 7;
    int count = 0;
    string a[1];
    a[0] = "https://utex.hcmute.edu.vn";
    string* b = a;
    url[0] = *b;
    for (int m = 0; m < 10; m++)
    {
        a[0] = "https://utex.hcmute.edu.vn/";
        RandomStringGenerator(a, r);
        string* b = a;
        url[k] = *b;
        int temp1 = k;
        for (int h = 0; h < 10; h++)
        {
            k++;
            a[0] = url[temp1] + '/';
            RandomStringGenerator(a, r);
            string* c = a;
            url[k] = *c;
            int temp2 = k;
            for (int l = 0; l < 10; l++)
            {
                k++;
                a[0] = url[temp2] + '/';
                RandomStringGenerator(a, r);
                string* d = a;
                url[k] = *d;
            }
        }
    }
}
int main()
{
    string url[2000];
    sinh(url);
    return 0;
}