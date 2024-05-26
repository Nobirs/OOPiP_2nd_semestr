#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include <Windows.h>


using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

class Exception {
private:
    string message;
public:
    Exception(const string& msg) : message(msg) {}
    ~Exception() {}

    string getMessage() const { return message; }
    const char* what() const{ return message.c_str(); }
};

class GymException : public Exception {
public:
    GymException(const string& msg) : Exception(msg) {}
};

class InvalidAgeException : public GymException {
public:
    InvalidAgeException(const string& msg) : GymException(msg) {}
};

class InvalidGenderException : public GymException {
public:
    InvalidGenderException(const string& msg) : GymException(msg) {}
};

class NoTrainerException : public GymException {
public:
    NoTrainerException(const string& msg) : GymException(msg) {}
};

class NoEquipmentException : public GymException {
public:
    NoEquipmentException(const string& msg) : GymException(msg) {}
};

class InvalidDurationException : public GymException {
public:
    InvalidDurationException(const string& msg) : GymException(msg) {}
};

class OutOfMemoryException : public GymException {
public:
    OutOfMemoryException(const string& msg) : GymException(msg) {}
};

class User {
protected:
    string name;
    int age;
    char gender;
    int fitnessLevel;

public:
    User() : name("Default name"), age(18), gender('m'), fitnessLevel(0) 
    {
        cout << "User default constructor" << endl;
    }
    User(const string& _name, int _age, char _gender, int _fitnessLevel) : name(_name), gender(_gender), fitnessLevel(_fitnessLevel)
    {
        cout << "User constructor" << endl;
        if (_age < 0) throw InvalidAgeException("[ERROR] Age < 0 ....");
        if (_gender != 'M' and gender != 'F') throw InvalidGenderException("[ERROR] Invalid gender ....");
        this->age = _age;
    }
    ~User()
    {
        cout << "User Destructor" << endl;
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Fitness Level: " << fitnessLevel << endl;
    }

    void setFitnessLevel(int level) {
        fitnessLevel = level;
    }

    friend class Trainer;
};

class Trainer : public User {
private:
    string specialization;
    int experience;

public:
    Trainer() : User(), specialization("default"), experience(0) {}
    Trainer(const string& name, int age, char gender, int fitnessLevel, const string& specialization, int experience)
        : User(name, age, gender, fitnessLevel), specialization(specialization), experience(experience)
    {
        cout << "Trainer constructor" << endl;
    }
    Trainer(int a) : User()
    {
        if (a < 0) throw Exception("Exception in Trainer constructor");
    }
    ~Trainer()
    {
        cout << "Trainer Destructor" << endl;
    }

    void getInfo() const {
        User::getInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
    }

    static void rateProgress(User& user, int progress)
    {
        user.setFitnessLevel(user.fitnessLevel + progress);
    }
};

class Training {
private:
    string type;
    int duration;
    int difficultyLevel;

public:
    Training(const string& type, int duration, int difficultyLevel)
        : type(type), duration(duration), difficultyLevel(difficultyLevel)
    {
        cout << "Training constructor" << endl;
        if (duration <= 0) throw InvalidDurationException("[ERROR] Invalid duration ....");
    }
    ~Training()
    {
        cout << "Training destructor" << endl;
    }

    void getInfo() const {
        cout << "Type: " << type << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Difficulty Level: " << difficultyLevel << endl;
    }
};

class Equipment {
private:
    string type;
    int quantity;

public:
    Equipment(const string& type, int quantity) : type(type), quantity(quantity)
    {
        cout << "Equipment constructor" << endl;
        if (quantity <= 0) throw NoEquipmentException("[ERROR] No equipment available ....");
    }
    ~Equipment()
    {
        cout << "Equipment destructor" << endl;
    }

    void getInfo() const {
        cout << "Type: " << type << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void serviceEquipment() {
        cout << "Servicing equipment..." << endl;
    }
};

class Gym {
private:
    vector<Trainer> trainers;
    vector<Training> trainings;
    vector<Equipment> equipment;

public:
    Gym()
    {
        cout << "Gym constructor" << endl;
        
    }
    Gym(int a)
    {
        if (a < 0) throw Exception("Exception in Gym constructor");
    }
    ~Gym()
    {
        cout << "Gym destructor" << endl;
    }
    void addTrainer(const Trainer& trainer) {
        trainers.push_back(trainer);
    }

    void addTraining(const Training& training) {
        trainings.push_back(training);
    }

    void addEquipment(const Equipment& equip) {
        equipment.push_back(equip);
    }

    void getInfo() {
        cout << "Gym Information:" << endl;
        cout << "----------------" << endl;
        cout << "Trainers:" << endl;
        for (const auto& trainer : trainers) {
            trainer.getInfo();
        }
        cout << "Trainings:" << endl;
        for (const auto& training : trainings) {
            training.getInfo();
        }
        cout << "Equipment:" << endl;
        for (const auto& equip : equipment) {
            equip.getInfo();
        }
    }

    void performMaintenance() {
        cout << "Performing maintenance for gym equipment..." << endl;
        for (auto& equip : equipment) {
            equip.serviceEquipment();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Trainer* t;
    int count = 0;
    try {
        // Создание объектов тренера, тренировки и оборудования
        Trainer trainer1("John Doe", 30, 'M', 7, "Weightlifting", 5);
        Trainer trainer2("Jane Smith", 25, 'F', 6, "Yoga", 3);
        try {
            Trainer t("test for -age", -5, 'M', 1, "profi", 2);
        }
        catch (const InvalidAgeException& e)
        {
            cout << e.what() << endl;
        }
        try
        {
            Trainer t("test for gender", 5, 'm', 1, "profi", 2);
        }
        catch (const InvalidGenderException& e)
        {
            cout << e.what() << endl;
        }
        try
        {
            Training t("workout", -5, 2);
        }
        catch (const InvalidDurationException& e)
        {
            cout << e.what() << endl;
        }
        try
        {
            Equipment t("body", -1);
        }
        catch (const NoEquipmentException& e)
        {
            cout << e.what() << endl;
        }

        Training training1("Weightlifting", 60, 8);
        Training training2("Yoga", 45, 5);

        Equipment equip1("Treadmill", 10);
        Equipment equip2("Dumbbells", 20);

        // Создание зала и добавление тренеров, тренировок и оборудования
        Gym gym;
        gym.addTrainer(trainer1);
        gym.addTrainer(trainer2);
        gym.addTraining(training1);
        gym.addTraining(training2);
        gym.addEquipment(equip1);
        gym.addEquipment(equip2);

        // Вывод информации о зале и произведение обслуживания оборудования
        gym.getInfo();
        gym.performMaintenance();

        try {
            Trainer a(-1);
        }
        catch (const Exception& e)
        {
            cout << e.what() << endl;
            cout << "Exception in constructor" << endl;
        }
        
        try
        {
            int count = 0;
            while (true) {
                auto asd = (std::numeric_limits<int>::max)();
                int* p = new int[asd];
                count++;
                cout << "Не судьба" << endl;
                if (count > 100) break;
            }
        }
        catch (std::bad_alloc& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "done.\n";
    }
    catch (const Exception& e) {
        cout << "Caught exception: " << e.what() << endl;
        cout << "Counter: " << count << endl;
    }
    catch (const std::bad_alloc& e) {
        cout << "Caught bad_alloc: " << e.what() << endl;
        cout << "Counter: " << count << endl;
        throw OutOfMemoryException("[ERROR] Out of memory ....");
    }

    return 0;
}
