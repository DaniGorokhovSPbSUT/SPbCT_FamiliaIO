#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std::literals;

std::string OUTPUT_FILE = "schedule.txt";
std::string INPUT_FILE = "input.txt";

int maxId = 0;

// Из std::string создаёт char* без использования небезопасного API
char* strcp(std::string s) {
    char* ns = new char[s.length() + 1];
    for (int i = 0u; i < s.length(); i++) {
        ns[i] = s[i];
    }

    return ns;
}

// Класс одной записи
class ScheduleVisit {
public:
    std::chrono::time_point<std::chrono::system_clock> dateTime; // Дата и время визита
    std::chrono::system_clock::duration visitDur = 1h; // Продолжительность визита
    std::string lastName; // Фамилия
    std::string firstName; // Имя
    std::string patronymic; // Отчество
    int medPolicyId; // Номер медицинского полиса
    int id = maxId++; // Уникальный идентификатор визита

    ScheduleVisit(
        std::chrono::time_point<std::chrono::system_clock> _dt,
        std::string _ln,
        std::string _fn,
        std::string _p,
        int _mid
    ):
        dateTime(_dt), lastName(_ln), firstName(_fn), patronymic(_p), medPolicyId(_mid) {}

    void print(std::ostream& stream = std::cout) {
        std::time_t parsedDateTime = std::chrono::system_clock::to_time_t(dateTime);

        const int bufSize = 255;
        char buffer[bufSize];
        ctime_s(buffer, bufSize, &parsedDateTime);

        stream << "Визит с идентификатором " << id << ":" << std::endl;
        stream << "ФИО: " << lastName << " " << firstName << " " << patronymic << std::endl;
        stream << "Дата и время визита: " << buffer;
        stream << "Номер медицинского полиса: " << medPolicyId << std::endl << std::endl;
    }
};

// Всё расписание
class Schedule {
public:
    std::vector<ScheduleVisit> visits;

    void addVisit(ScheduleVisit visit) {
        bool isAvailableVisit = true;

        auto visitTime = visit.dateTime.time_since_epoch().count();

        auto iter = visits.begin();

        while (iter != visits.end()) {
            auto recordedTime = iter->dateTime.time_since_epoch().count();

            auto timeDiff = std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::duration(std::abs(recordedTime - visitTime))
            ).count();

            auto posTimeDiff = std::chrono::duration_cast<std::chrono::seconds>(visit.visitDur).count();

            isAvailableVisit = isAvailableVisit && timeDiff >= posTimeDiff;

            iter++;
        }

        if (isAvailableVisit) {
            visits.push_back(visit);
            std::cout << "Визит с номером " << visit.id << " успешно зарегистрирован." << std::endl << std::endl;
        }
        else {
            std::cout << "Визит не может быть добавлен, так как выбранное время недоступно." << std::endl << std::endl;
        }
    }

    void delVisit(int id) {
        auto iter = visits.begin();

        while (iter != visits.end()) {
            if (iter->id == id) {
                visits.erase(std::next(iter));
            }

            iter++;
        }
    }

    void printAll() {
        auto iter = visits.begin();

        while (iter != visits.end()) {
            iter->print();

            iter++;
        }
    }

    void printOne(int id) {
        auto iter = visits.begin();

        while (iter != visits.end()) {
            if (iter->id == id) {
                iter->print();
            }

            iter++;
        }
    }

    void printAllInFile() {
        std::ofstream filestream(OUTPUT_FILE);

        auto iter = visits.begin();

        while (iter != visits.end()) {
            iter->print(filestream);

            iter++;
        }
    }

    void parseVisit(std::string rawVisit, int shift = 0) {
        // Base splitters
        int dateTimeSplitter = rawVisit.find_first_of('T');
        int timeNameSpliiter = rawVisit.find_first_of('/');
        int namePolicySplitter = rawVisit.find_first_of('/', timeNameSpliiter + 1);

        // Date and time parsing
        std::string date = rawVisit.substr(0, dateTimeSplitter);
        std::string time = rawVisit.substr(dateTimeSplitter + 1, timeNameSpliiter - dateTimeSplitter - 1);
        std::string str = date + " " + time;

        char* dateTimeStr = strcp(str);

        std::tm tm{};
        tm.tm_mday = 4 + shift;
        tm.tm_mon = 11 - 1;
        tm.tm_year = 2021 - 1900;
        tm.tm_hour = 15;
        tm.tm_min = 32;
        tm.tm_sec = 32;

        std::strftime(dateTimeStr, sizeof(dateTimeStr), "%F %T", &tm);
        delete[] dateTimeStr;

        std::time_t dateTime = std::mktime(&tm);

        // Name parsing
        std::string name = rawVisit.substr(timeNameSpliiter + 1, namePolicySplitter - timeNameSpliiter - 1);
        int firstNameSplitter = name.find_first_of('_');
        int secondNameSplitter = name.find_first_of('_', firstNameSplitter + 1);

        std::string lastName = name.substr(0, firstNameSplitter);
        std::string firstName = name.substr(firstNameSplitter + 1, secondNameSplitter - firstNameSplitter - 1);
        std::string patronymic = name.substr(secondNameSplitter + 1);

        // Medical policy id parsing
        int medPolicyId = std::stoi(rawVisit.substr(namePolicySplitter + 1));

        std::cout << lastName << std::endl;
        std::cout << firstName << std::endl;
        std::cout << patronymic << std::endl;
        std::cout << medPolicyId << std::endl;

        ScheduleVisit visit(std::chrono::system_clock::from_time_t(dateTime), lastName, firstName, patronymic, medPolicyId);
        addVisit(visit);
    }

    void addVisitsFromFile() {
        std::ifstream filestream(INPUT_FILE);

        std::string input;
        
        while (filestream >> input) {
            parseVisit(input, 2);

            filestream >> input;
        }
    }

    Schedule() {}
};

// Функция логирования - помогает выводить дополнительную информацию в красивом виде
void log(std::string text)
{
    std::cout << "\tLog: " << text << std::endl << std::endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    Schedule schedule;

    auto dateTime = std::chrono::system_clock::now();

   log("Добавляем первый визит");
    ScheduleVisit visit(dateTime, "Арбузов", "Андрей", "Антонович", 1234);
    schedule.addVisit(visit);

    log("Пробуем добавить визит, который пересекается по времени с предыдущим");
    ScheduleVisit visit2(dateTime - 30min, "Бананов", "Борис", "Борисович", 2345);
    schedule.addVisit(visit2);

    log("Добавляем визит на время, которое доступно");
    ScheduleVisit visit3(dateTime - 2h, "Виноградов", "Валентин", "Витальевич", 3456);
    schedule.addVisit(visit3);

    log("Выводим список всех визитов");
    schedule.printAll();

    log("Выводим информацию про первый созданный визит");
    schedule.printOne(visit.id);

    log("Сохраняем всё расписание в файл " + OUTPUT_FILE + " (файл должен быт создан)");
    schedule.printAllInFile();

    log("Добавляем записи в расписание с помощью файла " + INPUT_FILE + " (файл должен быт создан)");
    log("Формат ввода (для разделения записей используется перенос строки):");
    log("<Номер дня в месяце>.<Номер месяца>.<Год полный>T<Часы>:<Минуты>:<Секунды>/<Фамилия>_<Имя>_<Отчество>/<Номер мед. полиса>");
    schedule.addVisitsFromFile();

    log("Создаём визит с помощью ввода");

    std::string input;
    std::cin >> input;

    input = "2021-11-04T10:32:32/Горохов_Григорий_Геннадьевич/5678";

    schedule.parseVisit(input);

    log("Удаляем первый созданный визит");
    schedule.delVisit(visit.id);

    log("Выводим список всех визитов");
    schedule.printAll();

    system("pause");
}
