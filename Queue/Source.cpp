#include <iostream>
#include <Windows.h>

using namespace std;

struct Figura {
    string name = ""; //��� 
    double square = 0; //�������
    double volume = 0; //�����
    double AmountVerticeshyny = 0; //���-�� ������
};

class GeometryFigure {
private:
    struct Node {
        Figura val;
        Node* next_ptr = nullptr;
    };
    Node* first_ptr = nullptr;
    Node* last_ptr = nullptr;
public:
    void Push(Figura _val) {
        if (first_ptr == nullptr) {
            first_ptr = new Node;
            first_ptr->val = _val;
            last_ptr = first_ptr;
        }
        else {
            last_ptr->next_ptr = new Node;
            last_ptr = last_ptr->next_ptr;
            last_ptr->val = _val;
        }
    }
    Figura Pop() {
        Figura temp = first_ptr->val;
        first_ptr = first_ptr->next_ptr;
        return temp;
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GeometryFigure body;

    for (int i = 0; i < 3; i++) {
        Figura temp;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "=============== " << i + 1 << " ===============" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "������� �������� ������: ";
        cin >> temp.name;
        cout << "������� ������� ������: ";
        cin >> temp.square;
        cout << "������� ����� ������: ";
        cin >> temp.volume;
        cout << "������� ���-�� ������ ������: ";
        cin >> temp.AmountVerticeshyny;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "=============== " << " ===============" << endl << endl;
        body.Push(temp);
    }
    cout << endl << endl;
    cout << "=============== " << "�������������� ������" << " ===============" << endl << endl;
    for (int i = 0; i < 3; i++) {
        Figura temp = body.Pop();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "=============== " << i + 1 << " ===============" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "�������� ������: " << temp.name << endl;
        cout << "������� ������: " << temp.square << endl;
        cout << "����� ������: " << temp.volume << endl;
        cout << "���-�� ������ ������: " << temp.AmountVerticeshyny << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "=============== " << " ===============" << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

}
