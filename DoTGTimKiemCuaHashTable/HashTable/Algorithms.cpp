#include "algorithms.h"

using namespace std;
int Search(HashTable* URL[], string url, int prime)
{
    int hashValue = HashFunction(url, prime); //gọi hash function để tạo hash value
    int valueQuadratic = 1;
    while (URL[hashValue]->key != url && valueQuadratic < prime)
    {
        hashValue = (hashValue + valueQuadratic * valueQuadratic) % prime;
        valueQuadratic++;
        //cout << "-";
    }
    if (URL[hashValue]->key == url)
        return hashValue;
    return -1;
}
void Insert(HashTable* URL[], string url, int prime)
{
    int hashValue = HashFunction(url, prime);
    int valueQuadratic = 1;
    //xử lý đụng độ
    while (URL[hashValue]->check && valueQuadratic < prime)
    {
        hashValue = (hashValue + valueQuadratic * valueQuadratic) % prime;
        valueQuadratic++;
    }
    if (URL[hashValue]->check == true)
    {
        cout << "-";
    }
    URL[hashValue]->check = true;
    URL[hashValue]->key = url;

    //Tìm url cha
    string url2 = url;
    url2.erase(url2.rfind('/'), url.length());//url2 là url phân cấp trước nó
    int indexParent = Search(URL, url2, prime); //tìm index cha

    if (indexParent >= 0 && URL[indexParent]->check)
    {
        Node* temp = URL[indexParent]->next;
        if (temp == nullptr)
        {
            temp = new Node();
            temp->next = nullptr;
            temp->index = hashValue;
            URL[indexParent]->next = temp;
        }
        else
        {
            while (temp->next != nullptr) temp = temp->next;
            Node* node = new Node();
            node->next = nullptr;
            node->index = hashValue;
            temp->next = node;
        }
        URL[hashValue]->prev = indexParent;
    }
}
void RandomStringGenerator(string code[], int codeLength)   // Hàm dùng để lấy ngẫu nhiên các kí tự
{
    string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
    int boxLength = box.length();
    for (int i = 0; i < codeLength; i++)
    {
        code[0] = code[0] + box[rand() % boxLength];
    }
}
void sinh(string url[])     // Hàm dùng để sinh ngẫu nhiên các URL
{
    int k = 1;
    int r=7;
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
int Prime(int k)
{
    int n = 1.2 * k + 1;
    while (1)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                count++;
        }
        if (count == 2)
            return n;
        n++;
    }
    return 0;
}
int main()
{
    string url[2000];
    sinh(url);
    int prime;
    int t = 100;
    while (t<=1000)
    {   
        HashTable* h[2000];
        for (int i = 0; i < 2000; i++)
        {
            h[i] = new HashTable;
        }
        prime = Prime(t);
        for (int i = 0; i < t; i++)
        {
            Insert(h, url[i], prime);
        }
        double max = 0, min = 10, sum = 0;
        for (int i = 0; i < t; i++)
        {
            auto begin = std::chrono::high_resolution_clock::now();
            int key = Search(h, url[i], prime);
            auto end = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            sum += result.count();
            if (result.count() < min)
                min = result.count();
            if (result.count() > max)
                max = result.count();
        }
        double avg = (double)sum / t;
        std::cout << "The number of URLs: " << t << endl;
        std::cout << "Max execution time: " << max * 1e-6 << endl;
        std::cout << "Min execution time: " << min * 1e-6 << endl;
        std::cout << "Average execution time: " << avg * 1e-6 << endl << endl;
        t+=100;
    }   
}
