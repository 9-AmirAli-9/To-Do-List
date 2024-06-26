#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct todoitem
    {
        string descripe;
        bool done;
    };

class todolist
    {
    private:
        vector<todoitem> items;   
    public:
    void AddItem(string& description) {     
     cout<<"**** TO DO LIST ****"<<endl;
        todoitem newItem{description};
        items.push_back(newItem); // این خط کد ایتم را از کاربر میگیرد و در استراکچر سیو میکند
        // item[0]=riazi, item[1]=ap
     }    
    void DisplayList() {
       cout<<" **** TO DO LIST **** "<<endl;
        for (int i = 0; i < items.size(); ++i) {
         cout << i + 1 << ". " << (items[i].done ? "(D) " : " () ") << items[i].descripe <<endl;
     }
     }
    void markAsDone(int num) {     
     cout<<"**** TO DO LIST ****";
        if ( num <= items.size()) {
            num--;
            items[num].done = true;
        }else{
         cout<<"Invalid Choice!!"<<endl;
     }
     }    
    void editItem(int num, string& NewDescripe) {
     cout<<"**** TO DO LIST ****"<<endl;
        if ( num <= items.size()) {
            num--;
     items[num].descripe = NewDescripe;
        }else{
         cout<<endl<<"Invalid Choice!!"<<endl;
     } 
     }
    void DeleteItem(int num) {
     cout<<"**** TO DO LIST ****"<<endl;
        if (num > items.size() && num<0) 
            cout<<"Invalid Choice!!"<<endl;
            num--;
        items.erase(items.begin() + num );
      
    }
    };

int main() {
    todolist todolist1;
    char choice;
    cout<<endl<<"**** TO DO LIST ****";
    while (choice != '6')
    { 
        cout <<endl<<"1. Add ToDo Item"<<endl;
        cout << "2. Display ToDo List"<<endl;
        cout << "3. Mark Item as Done"<<endl;
        cout << "4. Edit ToDo Item"<<endl;
        cout << "5. Delete ToDo Item"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        
        switch (choice) {
            case '1': {
                string NewToDo;
                string Date;
                cout << "Enter the New Todo Item: "<<endl;
                cin>>NewToDo;
                NewToDo = NewToDo ;             
                todolist1.AddItem(NewToDo);
                break;
            }
            case '2':
                todolist1.DisplayList();
                break;
            case '3': {
                int number;
                cout << "Enter the number of the num to mark as done: ";
                cin >> number;
                todolist1.markAsDone(number);
                break;
            }
            case '4': {
                int num;
                string NewDescripe;
                cout << "Enter the num of the item to edit: ";
                cin >> num;
                cout << "Enter the new description: ";
                cin>>NewDescripe;
                NewDescripe = NewDescripe ;
                todolist1.editItem(num, NewDescripe);
                break;
            }
            case '5': {
                int num;
                cout << "Enter the num of the item to delete: ";
             cin >> num;
                todolist1.DeleteItem(num);
                break;
            }
            case '6':
                cout << "EXIT";
                break;
            default:
                cout << "Invalid Choice!"<<endl;
                cout<<"Please Choise Again"<<endl;
        }
    }   
}

