#pragma once
#include <iostream>
#include <stdexcept>  // Для исключений

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node() : data(T()), next(nullptr) {} // Конструктор по умолчанию
    Node(T value) : data(value), next(nullptr) {} // Конструктор с параметром
    ~Node() {} // Деструктор
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:


    // Конструкторы и деструктор
    List();
    ~List();

    size_t GetSize() const { return size; }
    //для файла
    Node<T>* getHead() const {
        return head;
    }
    //
    void push_back(T value); // добавление с конца
    void push_front(T value); // добавление с переднего
    void remove_by_index(size_t index); // удаление по индексу
    void pop_back(); // удаление с конца
    void pop_front(); // удаление с начала
    void clear(); // очистка списка
    void show() const; // вывод списка
    T& front(); // доступ к первому элементу
    T& back();  // доступ к последнему элементу
    T& at(size_t index);
    void insert(size_t index, const T& value); // Метод вставки
    void replace(size_t index, const T& newValue);
    // Внутренний класс Итератора
    class Iterator {
    private:
        Node<T>* current; // Указатель на текущий узел
    public:
        Iterator(Node<T>* node);

        T& operator*();
        Iterator& operator++();        // Префиксный ++
        Iterator operator++(int);      // Постфиксный ++
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        // Перегрузка оператора + для смещения на offset элементов вперед
        Iterator operator+(size_t offset) const {
            Iterator temp = *this;
            for (size_t i = 0; i < offset && temp.current; ++i) {
                temp.current = temp.current->next;
            }
            return temp;
        }

        Node<T>* getNode() const { return current; }

    };


    Iterator erase(Iterator iter);
    Iterator begin();
    Iterator end();

    class Algorithms {
    public:
        // Реализация поиска внутри класса Algorithms
        template <typename Predicate>
        static std::vector<T> find(const List<T>& list, Predicate condition);
    };

};


// Реализация методов списка

template<typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
List<T>::~List() { clear(); }

template<typename T>
void List<T>::push_back(T value) {
    Node<T>* newNode;
    newNode = new Node<T>(value);
    if (tail) {
        tail->next = newNode;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
    size++;
}

template<typename T>
void List<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    if (size == 0) {
        tail = newNode;
    }
    size++;
}


template<typename T>
void List<T>::remove_by_index(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        pop_front();
        return;
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node<T>* temp = current->next;
    current->next = temp->next;

    if (temp == tail) {
        tail = current;
    }
    delete temp;
    size--;
}



template<typename T>
void List<T>::pop_back() {
    if (!head) return;  // Если список пуст

    if (head == tail) { // Если в списке только один элемент
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<T>* current = head;
        while (current->next != tail) {
            current = current->next; // Дойти до предпоследнего узла
        }
        delete tail;             // Удаляем последний узел
        tail = current;          // Обновляем tail на предпоследний узел
        tail->next = nullptr;    // Предпоследний теперь указывает на nullptr
    }
    size--;
}

template<typename T>
void List<T>::pop_front() {
    if (!head) return; // Если список пуст

    Node<T>* temp = head; // Временно сохраняем указатель на голову
    head = head->next;    // Сдвигаем head на следующий узел
    delete temp;          // Удаляем старую голову

    if (!head) { // Если список стал пустым
        tail = nullptr;
    }
    size--;
}

template<typename T>
void List<T>::clear() {
    while (head) {
        pop_front(); // Удаляем элементы один за другим с начала списка
    }
}

template<typename T>
void List<T>::show() const {
    if (this == nullptr) {
        std::cerr << "Ошибка: пытаемся вызвать show() на пустом объекте." << std::endl;
        return;
    }
    Node<T>* current = head;
    int i = 0;
    while (current) {
        std::cout << current->data;
        current = current->next;
        i++;
    }
    std::cout << std::endl;
}



template<typename T>
T& List<T>::front() {
    if (!head) {
        throw std::out_of_range("List is empty. No front element.");
    }
    return head->data;
}

template<typename T>
T& List<T>::back() {
    if (!tail) {
        throw std::out_of_range("List is empty. No back element.");
    }
    return tail->data;
}

template<typename T>
inline T& List<T>::at(size_t index)
{
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range: " + std::to_string(index));
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    if (!current) {
        throw std::runtime_error("Node is null at index: " + std::to_string(index));
    }
    return current->data;
}

template <typename T>
void List<T>::insert(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* newNode = new Node<T>(value);

    if (index == 0) {
        // Вставка в начало списка
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = newNode;
        }
    }
    else {
        // Вставка в середину или конец списка
        Iterator it = begin() + (index - 1);  // Получаем итератор перед индексом
        Node<T>* prev = it.getNode();

        newNode->next = prev->next;
        prev->next = newNode;

        // Если вставка происходит в конец
        if (prev == tail) {
            tail = newNode;
        }
    }

    ++size;
}

template<typename T>
void List<T>::replace(size_t index, const T& newValue) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    if (current) {
        current->data = newValue; // Здесь должен происходить процесс замены
        std::cout << "Элемент на индексе " << index << " успешно заменён." << std::endl;
    }
}


///////////////////////итератор////////////////////

// Конструктор итератора
template <typename T>
List<T>::Iterator::Iterator(Node<T>* node) : current(node) {}

// Оператор разыменования
template <typename T>
T& List<T>::Iterator::operator*() {
    return current->data;
}

// Префиксный оператор ++
template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    if (current) current = current->next;
    return *this;
}

// Постфиксный оператор ++
template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

// Оператор сравнения ==
template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

// Оператор сравнения !=
template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}





template <typename T>
typename List<T>::Iterator List<T>::erase(Iterator iter) {
    if (!iter.current) { // Если итератор указывает на nullptr
        throw std::out_of_range("Invalid iterator: Cannot erase");
    }

    Node<T>* toDelete = iter.current; // Узел для удаления
    Node<T>* nextNode = toDelete->next;

    if (iter.prev) {
        // Если удаляем не первый элемент
        iter.prev->next = nextNode;
    }
    else {
        // Если удаляем первый элемент
        head = nextNode;
    }

    if (toDelete == tail) {
        // Если удаляем последний элемент
        tail = iter.prev;
    }

    delete toDelete; // Удаляем узел
    size--;

    return Iterator(nextNode, iter.prev, this); // Возвращаем итератор на следующий элемент
}


template <typename T>
typename List<T>::Iterator List<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename List<T>::Iterator List<T>::end() {
    return Iterator(nullptr);
}

template<typename T>
template<typename Predicate>
inline std::vector<T> List<T>::Algorithms::find(const List<T>& list, Predicate condition)
{
    {
        std::vector<T> results;
        auto current = list.getHead();
        while (current) {
            if (condition(current->data)) {
                results.push_back(current->data);
            }
            current = current->next;
        }
        return results;
    }
}
