#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <vector>
#include <thread>
#include <iomanip>             
#include <ctime>
using namespace std;
using namespace std::chrono;
int rrand(int range_min, int range_max)
{
    return rand() % (range_max - range_min + 1) + range_min;
}
const unsigned int arrSIZE = 100;
const int arrLIMIT = 99;
int arr[arrSIZE];
int Search_Binary(int arr[], int left, int right, int key)
{

    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void printArray(int arr[], int size)
{
    cout << "Несортированный массив:\n ";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n\n\n";
}
void printArrayS(int arr[], int size)
{
    cout << "Сортированный массив:\n";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}
void printMatrix(int**, int, bool = 1);
void printMatrix(int** matrix, int N, bool zero)
{
    if (zero) system("cls");
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            cout << setw(3) << *elemI;
            if (elemI != lastI) cout << " ";
        }
        cout << "\n";
    }
    std::this_thread::sleep_for(0.1s);
}
void zeroMatrix(int** matrix, int N) {
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            *elemI = 0;
        }
    }
}

void snakeMatrix(int** matrix, int N) {
    printMatrix(matrix, N);
    for (int lineNum = 0; lineNum < N / 2; ++lineNum) {
        for (int** elemJ = matrix, **lastJ = matrix + N - 1; elemJ <= lastJ; elemJ++)
        {
            *(*elemJ + lineNum * 2) = rand() % 101;
            printMatrix(matrix, N);
        }
        for (int** elemJ = matrix + N - 1, **lastJ = matrix; elemJ >= lastJ; elemJ--)
        {
            *(*elemJ + lineNum * 2 + 1) = rand() % 101;
            printMatrix(matrix, N);
        }
    }
}
void rotateMatrix(int** matrix, int N) {
    int** a = new int* [N / 2], ** b = new int* [N / 2], ** c = new int* [N / 2], ** d = new int* [N / 2], *** arr = new int** [4];
    arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
    for (int*** i = arr, ***ilast = arr + 3; i <= ilast; i++)
    {
        for (int** elem = *i, **last = elem + N / 2 - 1; elem <= last; elem++)
        {
            *elem = new int[N / 2];
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = a; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = b; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = c; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = d; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    int** pa, ** pb, ** pc, ** pd;
    pa = c; pb = d; pc = a; pd = b;

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = pa; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = pb; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = pc; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = pd; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }


    printMatrix(matrix, N, 0);
}
void sortMatrix(int** matrix, int N) {
    int* arr = new int[N * N];
    int i = 0;
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            *(arr + i) = *elemI;
            i++;
        }
    }
    bool reverse = 1;
    while (reverse) {
        reverse = 0;
        for (int* j = arr, *jlast = j + (N * N) - 2; j <= jlast; j++)
        {
            if (*j > *(j + 1))
            {
                reverse = 1;
                int t = *(j + 1);
                *(j + 1) = *j;
                *j = t;
            }
        }
    }

    i = 0;
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            *elemI = *(arr + i);
            i++;
        }
    }
    printMatrix(matrix, N, 0);
}
void increaseMatrix(int** matrix, int N, int k) {
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            *elemI *= k;
        }
    }
    printMatrix(matrix, N, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Выберите лабораторную работу: \n" << "1. Типы данных и их внутреннее представление в паняти. \n"
        << "2. Одномерные статические массивы. \n" << "3. Указатели. \n" << "4. Текстовые строки.\n";
    int a=0;
    cin >> a;
      switch (a) 
      {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
        {
            setlocale(0, "");
            cout << "~~~~~ 1 задание ~~~~~ \n";
            cout << "В памяти компьютера: \n";
            cout << "int занимает " << sizeof(int) << " байта \n";
            cout << "short int занимает " << sizeof(short int) << " байта \n";
            cout << "long int занимает " << sizeof(long int) << " байта \n";
            cout << "float занимает " << sizeof(float) << " байта \n";
            cout << "double занимает " << sizeof(double) << " байт \n";
            cout << "long double занимает " << sizeof(long double) << " байт \n";
            cout << "char занимает " << sizeof(char) << " байт \n";
            cout << "bool занимает " << sizeof(bool) << " байт \n";
            cout << "\n";


            cout << "~~~~~ 2 задание ~~~~~ \n";
            int imput;
            cout << "Введите любое целое число \n";
            cin >> imput;
            int idz = imput;
            cout << "Двоичное представление введенного числа: \n ";
            int a = sizeof(imput) * 8;
            int mask = 1 << (a - 1);
            for (int i = 0; i < a; i++) {
                if (i == 1 || i % 8 == 0) {
                    putchar(' ');
                }
                putchar(imput & mask ? '1' : '0');
                imput <<= 1;
            }
            cout << "\n";
            union {
                float value;
                int b;
            };
            cout << "\n";
            cout << "~~~~~ 3 задание ~~~~~\n";
            cout << "Введите любое значение типа float \n";
            cin >> value;
            cout << "Двоичное представление введенного числа: \n";
            for (int i = 0; i < a; i++) {
                if (i == 1 || i % 8 == 0) {
                    putchar(' ');

                }
                putchar(b & mask ? '1' : '0');
                b <<= 1;

            }
            cout << "\n |Экспонента|--------Мантисса-------|" << endl;
            cout << "\n";

            cout << "~~~~~ 4 задание ~~~~~\n";
            cout << "Введите значение типа double \n";


            union {
                double num;
                int num3[2];
            };

            cin >> num;

            int a2 = 32;
            int mask2 = 1 << (a2 - 1);

            for (int i = 0; i < a2; i++) {
                if (i == 1 || i % 8 == 0 || i == 12)
                    cout << " ";
                cout << (num3[1] & mask2 ? '1' : '0');
                num3[1] <<= 1;
            }

            for (int i = 0; i < a2; i++) {
                if (i % 8 == 0)
                    cout << " ";
                cout << (num3[0] & mask2 ? '1' : '0');
                num3[0] <<= 1;
            }

            cout << "\n   | Экспонента |-------------------------Мантисса-------------------------| \n";

        }
        break;
        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2: {

            setlocale(LC_ALL, "rus");
            int a, b, c, d, e, f, g, j, l, w, buf;
            c = 0; d = 0; e = 0; f = 0;
            srand(static_cast<unsigned int>(time(NULL)));
            for (unsigned int i = 0; i < arrSIZE; i++)
            {
                arr[i] = rrand(-arrLIMIT, arrLIMIT);

            }
            printArray(arr, arrLIMIT);
            auto start = steady_clock::now();
            int min = arr[0];
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                }
            }
            int max = arr[0];
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
            auto finish = steady_clock::now();
            auto Elapsed_1 = duration_cast<nanoseconds>(finish - start);
            cout << "Минимальное: " << min << "\n" << "Максимальное: " << max << " \n" << "Время поиска Мин. и Макс. : " << Elapsed_1.count() << " " << "NANOseconds\n";
            a = (min + max) / 2;
            cout << "Среднее значение: " << a << "\n";
            cout << "Индексы элементов, равных среднему значению: ";
            auto Start3 = steady_clock::now();
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] == a)
                {
                    c = c++;
                    cout << i << " ";

                }
                if (c == 0 && i == 99) cout << "Индексы отсутствуют";
            }
            auto Finish3 = steady_clock::now();
            cout << "\n";
            cout << "Количество индексов элементов, равных среднему значению: " << c << "\n";
            auto ELapsed5 = duration_cast<nanoseconds>(Finish3 - Start3);
            cout << "Время поиска индекса: " << ELapsed5.count() << " " << "NANOseconds\n\n";

            auto begin = steady_clock::now();
            bubbleSort(arr, arrLIMIT);
            auto end = steady_clock::now();
            printArrayS(arr, arrLIMIT);
            auto Start = steady_clock::now();
            int min1 = arr[0];
            int max1 = arr[98];
            auto Finish = steady_clock::now();
            cout << "Минимальное: " << min1 << "\n" << "Максимальное: " << max1 << " \n";
            auto ELapsed2 = duration_cast<nanoseconds>(Finish - Start);
            cout << "Время поиска Мин. и Макс. : " << ELapsed2.count() << " " << "NANOseconds\n";
            auto elapsed_3 = duration_cast<microseconds>(end - begin);
            cout << "Время сортировки: " << elapsed_3.count() << " " << "MICROseconds\n";
            b = (min1 + max1) / 2;
            cout << "Среднее значение: " << b << "\n";
            cout << "Индекс элементов, равные среднему значению: ";
            auto Start2 = steady_clock::now();
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] == b)
                {
                    d = d++;
                    cout << i << " ";
                }
                if (b == 0 && i == 99) cout << "Индексы отсутствуют";
            }
            auto Finish2 = steady_clock::now();
            cout << "\n";
            cout << "Количество индексов элементов, равных среднему значению: " << d << "\n";
            auto ELapsed4 = duration_cast<nanoseconds>(Finish2 - Start2);
            cout << "Время на поиск индекса: " << ELapsed4.count() << " " << "NANOseconds\n";
            cout << "Введите элемент (a), который есть в массиве: ";
            cin >> g;
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] < g)
                {
                    e = e++;
                }
            }
            cout << "Число элементов < a: " << e << "\n";
            cout << "Введите элемент (b), который есть в массиве: ";
            cin >> j;
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] > j)
                {
                    f = f++;
                }
            }
            cout << "Число элементов > b: " << f << "\n";

            int key = 0;
            int index = 0;
            cout << "\nВведите любое число: ";
            cin >> key;
            auto start3 = steady_clock::now();
            index = Search_Binary(arr, 0, arrSIZE, key);
            auto finish3 = steady_clock::now();
            auto eLapsed5 = duration_cast<nanoseconds>(finish3 - start3);
            if (index >= 0)
                cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
            else
                cout << "В массиве нет такого числа!\n\n";

            cout << "Перебором индексы массивов: ";
            auto start4 = steady_clock::now();
            for (int i = 0; i < 100; ++i)
            {
                if (arr[i] == key)
                {
                    cout << i << " ";
                }
            }
            auto finish4 = steady_clock::now();
            auto eLapsed6 = duration_cast<nanoseconds>(finish4 - start4);
            cout << "\n";
            cout << "Время затраченное бинарным поиском: " << eLapsed5.count() << " " << "NANOseconds" << "  <  " << "Время затраченное пиребором: " << eLapsed6.count() << " " << "NANOseconds\n";
            cout << "Введите индексы массива, которые нужно поменять местами(через пробел): ";
            cin >> l >> w;
            swap(arr[l], arr[w]);
            printArray(arr, arrLIMIT);

        }
              break;
              ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3: {
            srand(time(NULL));
            int N;
            cout << "Enter N(6, 8 or 10):" << "\n";
            cin >> N;
            while (N != 6 && N != 8 && N != 10) {
                cout << "Wrong N value, try again" << "\n";
                cin >> N;
            }
            int** matrix = new int* [N];
            for (int** elem = matrix, **last = elem + N - 1; elem <= last; elem++)
            {
                *elem = new int[N];
            }
            zeroMatrix(matrix, N);
            snakeMatrix(matrix, N);
            cout << "Rotated matrix: " << '\n';
            rotateMatrix(matrix, N);
            cout << '\n' << "Sorted matrix: " << '\n';
            sortMatrix(matrix, N);
            cout << '\n' << "Enter a value to increase matrix elements: ";
            int k;
            cin >> k;
            increaseMatrix(matrix, N, k);

        }
              break;
        case 4: {
            setlocale(LC_ALL, "Rus");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            string line;
            cout << "Введите текст с клавиатуры:" << "\n";
            cin.get();
            getline(cin, line);

            string symbol = "  ";
            size_t pos;
            while ((pos = line.find(symbol)) != line.npos)
                line.replace(pos, symbol.length(), " ");

            string symbol2 = ",,";
            size_t pos2;
            while ((pos2 = line.find(symbol2)) != line.npos)
                line.replace(pos2, symbol2.length(), ",");

            string symbol3 = "..";
            size_t pos3;
            while ((pos3 = line.find(symbol3)) != line.npos)
                line.replace(pos3, symbol3.length(), ".");

            string symbol4 = "!!";
            size_t pos4;
            while ((pos4 = line.find(symbol4)) != line.npos)
                line.replace(pos4, symbol4.length(), "!");

            string symbol5 = "??";
            size_t pos5;
            while ((pos5 = line.find(symbol5)) != line.npos)
                line.replace(pos5, symbol5.length(), "?");

            string symbol6 = "--";
            size_t pos6;
            while ((pos6 = line.find(symbol6)) != line.npos)
                line.replace(pos6, symbol6.length(), "-");

            string symbol7 = "\"\"";
            size_t pos7;
            while ((pos7 = line.find(symbol7)) != line.npos)
                line.replace(pos7, symbol7.length(), "\"");

            transform(line.begin(), line.end(), line.begin(), tolower);

            for (int i = 0; i <= line.length(); i++)
            {
                if (i != line.length() - 2)
                {
                    if ((line[i] == '.' || line[i] == '!' || line[i] == '?') && line[i + 1] == ' ')
                    {
                        line[i + 2] = toupper(line[i + 2]);
                    }
                }


            }
            line[0] = toupper(line[0]);
            cout << endl;
            cout << "Изменённая строка:" << "\n";
            cout << line << "\n";
            cout << endl;
            string linesecond = (line + " ");
            int lengthWord = 0;
            cout << "Строка, с напечатанными в обратном порядке словами: " << "\n";
            for (int i = 0; i < linesecond.length(); i++)
            {
                if (int(linesecond[i]) < 0 || (47 < int(linesecond[i]) && int(linesecond[i]) < 58))
                {
                    lengthWord += 1;
                }
                else
                {
                    if (lengthWord > 0)
                    {
                        for (int j = i - 1; j > i - lengthWord - 1; j--)
                        {
                            cout << linesecond[j];
                        }
                    }
                    cout << linesecond[i];
                    lengthWord = 0;
                }

            }

            cout << endl;
            cout << endl;
            cout << "Введите то, что вы хотите удалить из строки(нужен пробел перед началом):" << "\n";
            string linethird = line, part;

            cin.get();
            getline(cin, part);

            size_t position;
            while ((position = linethird.find(part)) != linethird.npos)
                linethird.replace(position, part.length(), "");
            cout << linethird << "\n";

            string text1, part2;
            cout << "Введите подстроку, которую хотите найти (нужен пробел перед началом): ";

            cin.get();
            getline(cin, text1);
            cout << "Позиции текста, которые содержат введённую Вами подстроку (считая, что позиция первой буквы – 0): " << "\n";

            if (text1.length() == 1) {
                for (int i = 0; i <= line.length(); i++) {
                    if (line[i] == text1[0]) {
                        cout << i << " ";
                    }
                }
            }
            if (text1.length() >= 2) {
                for (int i = 0; i <= line.length(); i++)
                {
                    if (line[i] == text1[0])
                    {

                        for (int j = i; j < (i + text1.length()); j++)
                        {

                            for (int k = j; k < (j + text1.length()); k++) {
                                part2 += line[k - 1];

                                if (k == (j + text1.length()))
                                    part2 += "\0";
                            }

                            if (part2 == text1) {
                                cout << i << " - " << (j + text1.length() - 2) << "\t";
                                part2.clear();
                            }
                            if (part2 != text1) {
                                part2.clear();
                            }
                        }
                    }
                }
            }
            cout << endl;

        }
              break;
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        default:
        {
            cout << "Выберите от 1-4 : \n";
        }
        
      }
    return 0;
}
