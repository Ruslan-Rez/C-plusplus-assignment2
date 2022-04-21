#include <iostream>
#include <string>
template <typename T>
struct Node {
T data;
Node* next;
};
template <typename T>
void showList(const Node<T>* head){
    while(head != nullptr){
            std::cout<< head->data<<" ";
            head = head->next; 
        }
        std::cout<<std::endl;
}
template <typename T>
Node<T>* arrayToList(const T a[], size_t size){
    Node<T>* head = nullptr;
    for(int i = size-1; i>=0; i--){
       Node<T>* tmp = new Node<T>;
        tmp->data = a[i];
        tmp->next = head;
        head = tmp;}
    return head;    
}
template <typename T>
void push(Node<T>*& head, const T &element)
{
    Node<T> *p = new Node<T>;
    p->data = element;
    p->next = head;
    head = p;
}

template <typename T>
T pop(Node<T>*& head)
{
    T x;

    if (head != NULL) {
        Node<T>* tmp = head;
        x = head->data;
        head = head->next;
        delete tmp;
    }

    return x;
}
template <typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred pred){
    Node<T> *ext = nullptr;
    Node<T> *rem = nullptr;

    while (head != nullptr) {
        T value = pop(head);
        if (pred(value)) {
            push(ext, value);
        } else {
            push(rem, value);
        }
    }
   head = rem;
   

    return ext;
    

}
template <typename T>
void deleteList(Node<T>*& head){
    while( head != nullptr){
            Node<T>* x = head->next;
            std::cout<<"del:"<<head->data<<"  ";
           delete head;
            head = x;
         
        }
        std::cout<<std::endl;
}
bool isLong(const std::string& s) { 
return s.size() >= 5; }
int main() {
int tabi[] = { 2, 1, 4, 3, 6, 5, 7, 8 };
size_t sizei = sizeof(tabi)/sizeof(tabi[0]);
Node<int>* listAi = arrayToList(tabi, sizei);
showList(listAi);
Node<int>* listBi = extract(listAi,[](int n) {return n % 2 == 0;});
showList(listBi);
showList(listAi);
deleteList(listBi);
deleteList(listAi); 
std::string tabs[]{ "Kasia", "Ola", "Ala","Zosia", "Ela", "Basia" };
size_t sizes = sizeof(tabs)/sizeof(tabs[0]);
Node<std::string>* listAs = arrayToList(tabs, sizes);
showList(listAs);
Node<std::string>* listBs = extract(listAs, isLong);
showList(listBs);
showList(listAs);
deleteList(listBs);
deleteList(listAs);
}