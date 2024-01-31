#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class ArrayOperations {
  private:
    int arr[MAX_SIZE];
    int size;
  public:
    ArrayOperations(): size(0) {}

    void updateElement(int k, int x){
    if (k >=0 && k < size) {
      arr[k] = x;
    }
    else {
      cout<<"Invalid index"<<endl;
    }
  }
    void insertElement (int k, int x){
      if (k >=0 && k <= size && size < MAX_SIZE) {
        for (int i = size; i>k ; --i){
          arr[i] = arr[i-1];
        }
        arr[k]= x;
        ++size;
      }
      else {
        cout <<"Invalid index or Array is full"<<endl;
      }
  }
  bool searchElement (int x) {
    for (int i = 0; i< size; i++){
      if (arr[i]==x){
        return true;
      }
    }
    return false;
  }

  void removeElement (int x) {
    int i =0;
    while (i< size  && arr[i]!=x){
      ++i;
    }
  if (i< size){
    for (int j =1; j<size; j++){
      arr[j]= arr[j+1];
    }
    --size;
  }
  else {
    cout <<"Element not found "<< endl;
  }
}
  void displayElement(int k) {
    if (k>=0 && k<size){
      cout <<"Element at position"<<k<<":"<<arr[k]<<endl;
    }
    else {
      cout <<"Invalid index"<<endl;
    }
  }
};

  int main (){
    ArrayOperations arrayops;
    int choice;
    do {
      cout <<"Menu:\n";
      cout<<"1. Update an element\n";
      cout<<"2. Search an Element\n";
      cout<<"3. Insert an Element \n";
      cout<<"4. Remove an Element \n";
      cout<<"5. Display an Element \n";
      cout<<"0. Exit\n";
      cout<<"Enter your choice";
      cin>>choice;

      switch(choice){
      case 1: {
               int k,x;
               cout <<"Enter position and value to update";
               cin >> k >> x;
               arrayops.updateElement(k,x);
               break;
             }
      case 2: {
              int x;
              cout<<"Enter the value to search";
              cin>>x;
              if (arrayops.searchElement(x)){
                cout<<"Element found";
              }
              else {
              cout<<"Element not found";
              }
              break;
             }
        case 3: {
                  int x,k;
                  cout <<"Enter the position and value to insert";
                  cin>>k>>x;
                  arrayops.insertElement(k,x);
                  break;
                }
        case 4:{
                 int x;
                 cout <<"Enter the value to remove";
                 cin>>x;
                 arrayops.removeElement(x);
                 break;
               }
        case 5:{
                 int k;
                 cout <<"Enter the position to display";
                 cin >> k;
                 arrayops.displayElement(k);
                 break;
               }
        case 0:{
               cout<<"Exiting the program";
                break;
               }
        default:
               cout<<"Invalid choice";
      }
    }
      while (choice != 0);
      return 0;
  } 
