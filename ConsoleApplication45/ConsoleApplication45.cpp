class Student {
    string name;    string surname;
    DateTime birthday;    DateTime study_start;
    int* hometask_rates = nullptr; // ПОЛЕ-ПОКАЖЧИК
    int hometask_rates_count = 0;
    int* practice_rates = nullptr;     int practice_rates_count = 0;
    int* exam_rates = nullptr;
    int exam_rates_count = 0;
public:    Student()
{
    cout << "student constructor withour parameters\n";
    SetName("Oleksandr");
    SetSurname("Zahoruiko");        SetBirthday({ 10, 10, 1989 });
    SetStudyStart({ 1, 9, 2022 });
}
      // тiло КК для класу, яке створюе компiлятор за замовчуванням
      // поверхневе копiювання    /* Student(const Student& original)
{        this->name = original.name;
this->surname = original.surname;        this->birthday = original.birthday;
this->study_start = original.study_start;        this->hometask_rates = original.hometask_rates; // проблема виникае саме тут - при копiюваннi адреси :500 з оригiналу до копii
this->hometask_rates_count = original.hometask_rates_count;    }*/
// якщо в складi класу е поле-покажчик,
// то потрiбно ОБОВ'ЯЗКОВО зробити ЯВНИЙ конструктор копiювання    // в якому пiд усi поля-покажчики буде видiлена ОКРЕМА НОВА ДIЛЯНКА ПАМ'ЯТI
Student(const Student & original) {
    cout << "student copy constructor\n";
    this->name = original.name;        this->surname = original.surname;
    this->birthday = original.birthday;        this->study_start = original.study_start;
    // приклад ГЛИБОКОГО КОПIЮВАННЯ
    this->hometask_rates_count = original.hometask_rates_count;
    // для полiв-покажчикiв буде окремий код, який видiляе нову пам'ять!!!!        this->hometask_rates = new int[this->hometask_rates_count];
    // мало видiлити пам'ть, ii потрiбно ще й проiнiцiалiзувати!!!        for (int i = 0; i < this->hometask_rates_count; i++)
    {            this->hometask_rates[i] = original.hometask_rates[i];
    }
    this->practice_rates_count = original.practice_rates_count;
    this->practice_rates = new int[this->practice_rates_count];
    for (int i = 0; i < this->practice_rates_count; i++) {
        this->practice_rates[i] = original.practice_rates[i];
    }
    this->exam_rates_count = original.exam_rates_count;
    this->exam_rates = new int[this->exam_rates_count];
    for (int i = 0; i < this->practice_rates_count; i++) {
        this->exam_rates[i] = original.exam_rates[i];
    }
}
~Student() {
    cout << "student destructor\n";        if (hometask_rates != nullptr)
    {
        delete[] hometask_rates;
        hometask_rates = nullptr;
    }
    if (practice_rates != nullptr) {
        delete[] practice_rates;            practice_rates = nullptr;
    }        if (exam_rates != nullptr)
    {
        delete[] exam_rates;
        exam_rates = nullptr;
    }
}
void SetName(string name) {
    this->name = name;
}
string GetName() const
{
    return name;
}
private:
    void SetBirthday(const DateTime& birthday) {
        this->birthday = birthday;
    }
public:
    DateTime GetBirthday() const {
        return birthday;
    }
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }
    DateTime GetStudyStart() const {
        return study_start;
    }
    void SetSurname(string surname)
    {
        this->surname = surname;
    }
    string GetSurname() const {
        return surname;
    }
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12) {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";            throw "ERROR!";
        }
        if (hometask_rates_count == 0) {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else {
            int* temp = new int[hometask_rates_count + 1];            for (int i = 0; i < hometask_rates_count;