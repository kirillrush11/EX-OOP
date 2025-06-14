#include <iostream>

using namespace std;

class DataBase{
private:
    DataBase() {
        cout << "Connection to database...";
    }
    static DataBase* connector;
    string data;
public:
    DataBase(const DataBase &) = delete;
    void operator=(const DataBase &) = delete;

    static DataBase* getConnection(){
        if (connector == nullptr){
            connector = new DataBase;
        }
        return connector;
    }

    string selectData() const{
        return data;
    }

    void insertData(string tmp){
        cout << tmp << endl;
        data = tmp;
    }
};

DataBase* DataBase::connector = nullptr;

int main()
{
    DataBase::getConnection()->insertData("12123123");
    DataBase::getConnection()->insertData("1");
    DataBase::getConnection()->insertData("12");
    return 0;

    cout << ":" << DataBase::getConnection()->selectData() << endl;
}
