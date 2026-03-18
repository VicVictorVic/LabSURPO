#include <iostream>
#include <windows.h>
#include <iomanip>
#include <io.h> // для _setmode
#include <string> // для работы со строками
#include <fcntl.h> // Для Windows: _O_U16TEXT

using namespace std;

const int iLimit = 3;

wchar_t tiret[] = L"-";

class Date {

    public:

    int Day;
    int Month;
    int Year;
    //надо бы добавить ещё тысячелетие и век! они пригодятся потом

    Date() {
        Day = 0;
        Month = 0;
        Year = 0;
    };

    wstring ShowDate() {
        string tmpStr = to_string(Day) + "-" + to_string(Month) + "-" + to_string(Year);
        wstring tmpRet(tmpStr.begin(), tmpStr.end());
        return(tmpRet);
    };

    void GetDate() {
        //wcout << L"День : "; 
        wcin >> Day >> tiret >> Month >> tiret >> Year;
        //wcout << L"Месяц : ";  
        //wcin >> Month;
        //wcout << L"Год : "; 
        //wcin >> Year;
    };

    //еще нужны процедуры - см.мои комментарии
    //процедура сравнения дат
    //процедуры вычисления разности дат (3шт как минимум!): в годах, месяцах, днях

};

class Employee {

    public:
    int empID;
    float empSalary;
    Date empDate;
    wstring* empName;

    Employee() {
        empID = 0;
        empSalary = 0;
        empDate = Date();
        empName = new wstring;
    };

    public:
    void printOut() {
        wcout << L"\nID : " << empID;
        wcout << L" ; Сотрудник : " << *empName;
        wcout << L" ; Оклад : " << empSalary;
        wcout << L" ; Принят на работу : " << empDate.ShowDate() << endl;
        wcout << L"И это все, что мы знаем о нем." << endl;
    };

    void inputEmp() {

        wcout << L"\nВведите ID : "; wcin >> empID;
        wcin.ignore();
        wcout << L"Введите имя : "; getline(wcin, *empName);
        wcout << L"Введите зарплату : "; wcin >> empSalary;
        wcout << L"Дата приема на работу : ";
        empDate.GetDate();

    };

};

int main() {


    // Настройка консоли Windows для отображения Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    //employee myPers;
    Employee* myStaff = new Employee[iLimit];

    wcout << L"\nСначала ввод данных!\n";
    for (int idxE = 0; idxE < iLimit; idxE++) {
        myStaff[idxE].inputEmp();
    }

    wcout << L"\nТеперь посмотрим список!\n";
    for (int idzE = 0; idzE < iLimit; idzE++) {
        myStaff[idzE].printOut();
    }

    wcout << "\n\n";

    delete[] myStaff;
    return 0;

}
